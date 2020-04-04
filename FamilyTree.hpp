#pragma once
#include<string>
#include <iostream>
using namespace std;

namespace family{
    
    class Tree{
        public:
            Tree();
            Tree(string name);
            Tree addFather(string childName, string fatherName);
            Tree addMother(string childName, string motherName);
            string relation(string name);
            string find(string relation);
            void display();
            void remove(string name);

    };
}