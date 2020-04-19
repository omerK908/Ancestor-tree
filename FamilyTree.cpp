#include <iostream>
#include <string>
#include "FamilyTree.hpp"

using namespace family;

/**
 * add a father for the given name node if exists if not throw an exception.
 * @param name the node we look for in the tree.
 * @param father the father of name(node) we want to add.
 * @return the father into the tree.
 */
Tree &Tree::addFather(string name, string father) {
    Node *tmp = findNode(_root, name);
    if (tmp == NULL)throw runtime_error("This name is not a member of this ancestor tree\n");
    if (tmp->getFather() != NULL) throw "ERROR: " + tmp->getName() + " Father already exist!\n";
    add(this->_root, name, father, true);
    return *this;
}

/**
 * add a mother for the given name node if exists if not throw an exception.
 * @param name the node we look for in the tree.
 * @param mother the mother of the name(node) we want to add.
 * @return the mother into the tree.
 */
Tree &Tree::addMother(string name, string mother) {
    Node *tmp = findNode(_root, name);
    if (tmp == NULL)throw runtime_error("This name is not a member of this ancestor tree\n");
    if (tmp->getMother() != NULL)throw "ERROR: " + tmp->getName() + " Mother already exist!\n";
    add(this->_root, name, mother, false);
    return *this;
}

/**
 * print the tree using a help method printTree.
 */
void Tree::display() {
    printTree(_root);
    cout << endl;
}

/**
 * receiving the ancestor tree root and printing the tree.
 * if he is null then the tree is empty
 * @param root of the tree.
 */
void Tree::printTree(Node *root) {
    if (root != NULL) {
        if (root->getFather() != NULL) {
            printTree(root->getFather());
        }
        cout << root->getName() << " ";
        if (root->getMother() != NULL) {
            printTree(root->getMother());
        }

    } else {
        throw runtime_error("The tree is empty!!\n");
    }
}


/**
 *given a name this method should return the relation of this node to the root.
 * @param name the node name relation to the root we are looking for.
 * @return (father/mother, grandfather/grandmother, great-grandfather/great-grandmother, ..etc.)
 */
string Tree::relation(string name) {

    Node *tmp = findNode(this->_root, name);
    int lvl = getLevel(this->_root, name);
    if (tmp == NULL || lvl == 0) return "unrelated";
    else if (lvl == 1) return "me";
    bool gender = tmp->getGender();
    if (lvl == 2) {
        if (gender) return "father";
        return "mother";
    } else if (lvl == 3) {
        if (gender)return "grandfather";
        return "grandmother";
    } else {
        string great = "great-";
        for (int i = 0; i < lvl - 4; i++) {
            great += "great-";
        }
        string ans;
        if (gender) ans = "grandfather";
        else ans = "grandmother";
        return great + ans;
    }
}

/**
 * source code from: https://www.youtube.com/watch?v=IJCg_jxOM_Q
 * level of the root start from 1.
 * using this method finds out what depth of the node we look for.
 * @param node start looking from this given node.
 * @param name the node we are looking for in the tree.
 * @return the depth of the node who's name we looked for in the tree.
 */
int Tree::getLevel(Node *node, string name) {
    Node *tmp = findNode(node, name);
    if (tmp == NULL) return 0;
    return getLevelUtil(node, name, 1);
}

/**
 * gets the level of the name we look for in the tree.
 * @param node the root node.
 * @param name the node depth we look for.
 * @param level the level of that name node we looked for.
 * @return the level he's at.
 */
int Tree::getLevelUtil(Node *node, string name, int level) {
    if (node == NULL) return 0;
    if (node->getName() == name) return level;
    int downlevel = getLevelUtil(node->getFather(), name, level + 1);
    if (downlevel != 0) return downlevel;
    downlevel = getLevelUtil(node->getMother(), name, level + 1);
    return downlevel;
}

/**
 * Given a name to look for in the tree and a root node to start from,
 * the method returns the name(node) we look for.
 * @param root the node we start looking from.
 * @param name to look for in the tree.
 * @return the name(node) if exists.
 */
Node *Tree::findNode(Node *root, string name) {
    if (this->_root == NULL)throw runtime_error("The tree is empty!!\n");
    if (root == NULL)
        return NULL;

    if (root->getName() == name)
        return root;

    /* then recur on father sutree */
    Node *res1 = findNode(root->getFather(), name);

    if (res1 != NULL) return res1; // node found, no need to look further

    /* node is not found in father, so recur on right subtree */
    Node *res2 = findNode(root->getMother(), name);
    return res2;

}


/**
 * given a relation string method should return the name of the node who's in this relation.
 * @param relation - father/mother , grandfather/grandmother , great-grandfather/great-grandmother, ..etc.
 * @return string the name of this node who's associated with this given relation.
 */

string Tree::find(string relation) {
    
    if(relation == "me") return _root->getName();
    else if(relation == "father")
    {
        if(_root->getFather() != NULL)
            return _root->getFather()->getName();
        else throw "No relation in the tree\n";
    } 
    else if(relation == "mother"){
        if(_root->getMother() != NULL)
            return _root->getMother()->getName();
        else throw "No relation in the tree\n";
    } 

    string delimiter = "-";
    size_t pos = 0;
    string token;
    int countGreat = 0;
    while ((pos = relation.find(delimiter)) != std::string::npos) {
        // token = relation.substr(0, pos);
        // std::cout << token << std::endl;
        relation.erase(0, pos + delimiter.length());
        countGreat++;
    }
   
    if(relation == "grandfather")
    {
        if(countGreat > 0)
        {
            Node* ans = getNodeByRel(_root, countGreat, true);
            if(ans == NULL) throw "No relation in the tree\n";
            else return ans->getName();
        }
        else
        {
            Node* tmp1;
            Node* tmp2;
            if(_root->getFather() != NULL)
            {
                tmp1 = _root->getFather();
                tmp1 = tmp1->getFather();
            }
            
            if(_root->getMother() != NULL)
            {
                tmp2 = _root->getMother();
                tmp2 = tmp1->getFather();
            }
            if(tmp1 != NULL)return tmp1->getName();
            else if(tmp2 != NULL) return tmp2->getName();
            else throw "No relation in the tree\n";
        }
        throw "No relation in the tree\n";
    }
    if(relation == "grandmother")
    {
        if(countGreat > 0)
        {
            Node* ans = getNodeByRel(_root, countGreat, false);
            if(ans == NULL) throw "No relation in the tree\n";
            else return ans->getName();
        }
        else
        {
            Node* tmp1;
            Node* tmp2;
            if(_root->getFather() != NULL)
            {
                tmp1 = _root->getFather();
                tmp1 = tmp1->getMother();
            }
            
            if(_root->getMother() != NULL)
            {
                tmp2 = _root->getMother();
                tmp2 = tmp1->getMother();
            }
            if(tmp1 != NULL)return tmp1->getName();
            else if(tmp2 != NULL) return tmp2->getName();
            else throw "No relation in the tree << endl";
        }
        throw "No relation in the tree\n";
    }
    else throw "No relation in the tree\n"; //no grandmother of grandfather
}

Node* Tree::getNodeByRel(Node* root, int count, bool gender)
{
    if(root != NULL)
    {
        if (count < 0) return NULL;
        else if (count == 0)
        {
            Node* tmp1;
            Node* tmp2;
            
            if(gender)
            {
               
                if(root->getFather() != NULL)
                {
                    tmp1 = root->getFather();
                    tmp1 = tmp1->getFather();
                }
                if(root->getMother() != NULL)
                {
                    tmp2 = root->getMother();
                    tmp2 = tmp2->getFather();
                }
                
            }
            else
            {
                
                if(root->getFather() != NULL)
                {
                    tmp1 = root->getFather();
                    tmp1 = tmp1->getMother();
                }
                if(root->getMother() != NULL)
                {
                    tmp2 = root->getMother();
                    tmp2 = tmp2->getMother();
                }
                
            }
            if(tmp1 != NULL) return tmp1;
            return tmp2;
            
        } 
        else
        {
            Node* f = getNodeByRel(root->getFather(), count - 1, gender);
            Node* m = getNodeByRel(root->getMother(), count - 1, gender);
            if(f != NULL) return f;
            if(m != NULL) cout <<"find: " << m->getName();
            return m;
        }
    }
    return NULL;
}


// string Tree::nodeNameAtHeight(Node *node, int heightAns, bool gender) {
//     if (node == NULL)return "";
//     if (getLevel(node, node->getName()) == heightAns && node->getGender() == gender)return node->getName();
//     if (gender) {
//         if (getLevel(node, node->getName()) == heightAns && node->getGender() == gender)return node->getName();
//         else if (node->getFather() != NULL) {
//             nodeNameAtHeight(node->getFather(), heightAns, gender);
//             nodeNameAtHeight(node->getMother(), heightAns, gender);
//         }
//     }
//     else {
//         if (getLevel(node, node->getName()) == heightAns && node->getGender() == gender)return node->getName();
//         else if (node->getMother() != NULL) {
//             nodeNameAtHeight(node->getMother(), heightAns, gender);
//             nodeNameAtHeight(node->getFather(), heightAns, gender);
//         }
        
//     }
//     return "";
// }


/**
 * remove a tree(if root is given, except for the root) or a subtree from the tree.
 * @param name
 */
void Tree::remove(string name) {

    if (findNode(_root, name) == NULL)throw "Cannot remove an empty name from the tree!!\n";
    Node *tmp = nullptr;
    if (_root->getName() == name)
        throw runtime_error("cannot delete the root node " + _root->getName() + "\n");
    else if ((_root->getName() == name && _root->getFather() != NULL) || _root->getMother() != NULL) {
        if (_root->getFather() != NULL) {
            tmp = findNode(_root->getFather(), name);
            if (tmp != NULL) {
                deleteSubTree(tmp);
            }
        } else if (_root->getMother() != NULL) {
            tmp = findNode(_root->getMother(), name);
            if (tmp != NULL) {
                deleteSubTree(tmp);
            }
        }
    } else {
        if (_root->getFather() != NULL) {
            tmp = findNode(_root->getFather(), name);
            if (tmp != NULL) {
                deleteSubTree(tmp);
            }
        } else if (_root->getMother() != NULL) {
            tmp = findNode(_root->getMother(), name);
            if (tmp == NULL)return;
            deleteSubTree(tmp);
        }
    }

}

/**
 * Help method for remove method deleting a subtree from ancestor tree.
 * @param root the ancestor tree root.
 */
void Tree::deleteSubTree(Node *root) {
    if (root == NULL) return;
    //deleting all subtree of the node.
    if (root->getFather() != NULL) {
        deleteSubTree(root->getFather());
    }
    if (root->getMother() != NULL) {
        deleteSubTree(root->getMother());
    }

    //then delete the root node of this subtree.
    cout << "\n Deleting node: " << root->getName() << endl;
    delete root;
}

/**
 * add a node to the tree for the given name node by gender.
 * @param root of the tree to add the father or mother.
 * @param name node to add the parent.
 * @param parent is the parent name.
 * @param gender is the parent gender.
 */
void Tree::add(Node *root, string name, string parent, bool gender) {
    
    Node* tmp = findNode(_root, name);
    if(tmp == NULL) throw runtime_error("not exist\n");
    if(gender)
    {
        if(tmp->getFather() != NULL)throw runtime_error("father exist\n");
    }
    else
    {
        if(tmp->getMother() != NULL)throw runtime_error("mother exist\n");
    }
    tmp->setNode(parent, gender);
    
    
    

    // if (root != NULL && gender == true && root->getName() == name && root->getFather() == NULL) {
    //     root->setNode(parent, gender);
    //     return;
    // }
    // if (root != NULL && gender == false && root->getName() == name && root->getMother() == NULL) {
    //     root->setNode(parent, gender);
    //     return;
    // }
    // if (root != NULL) {
    //     add(root->getMother(), name, parent, gender);
    //     add(root->getFather(), name, parent, gender);
    // }
    // return;

}