#include "FamilyTree.hpp"

family::Tree::Tree(){}
family::Tree::Tree(string name){}
family::Tree family::Tree::addFather(string childName, string fatherName){}
family::Tree family::Tree::addMother(string childName, string motherName){}
string family::Tree::relation(string name){}
string family::Tree::find(string relation){}
void family::Tree::display(){}
void family::Tree::remove(string name){}