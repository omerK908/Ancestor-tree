#include <iostream>
#include "FamilyTree.hpp"
using namespace family;

 
Tree& Tree::addFather(string name, string father)
{
    add(this->root, name, father, true);
    return *this;
}

Tree& Tree::addMother(string name, string mother)
{
    add(this->root, name, mother, false);
    return *this;
};

void family::Tree::display()
{
    printTree(root);

}

void family::Tree::printTree(Node* root)
{
    if(root==NULL) return;
    
    cout<< root->getName() <<endl;
    printTree(root->getFather());
    printTree(root->getMother());
        
    
    // if(root == NULL)return;
    // printTree(root->getFather());
    // printTree(root->getMother());
    // if(root->getFather() == NULL && root->getMother() == NULL)
    // {
    //     cout << root->getName() << endl;
    // }
    
    // cout << root->getFather()->getName() + "\n";
    // cout << root->getMother()->getName() + "\n";
    // cout << root->getName() << endl;
    
    
}

string family::Tree::relation(string name)
{
    return "";
}

string family::Tree::find(string name)
{
    return "";
}

void family::Tree::remove(string name)
{

}

void family::Tree::add(Node* root ,string name, string parent,bool g){
    if(root != NULL && g == true && root->getName() == name && root->getFather() == NULL){
        root->setNode(parent, g);
        return;
    }
    if(root != NULL && g == false && root->getName() == name && root->getMother() == NULL){
        root->setNode(parent, g);
        return;
    }
    if(root != NULL){
        add(root->getMother(), name, parent, g);
        add(root->getFather(), name, parent, g);
    }
    return;
}