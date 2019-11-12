#include <iostream>
#include "ExecuteOR.hpp"
using namespace std;

bool ExecuteOR::execute() {    
    if (!(this->left->execute()))
    {
        if(this->right->execute()){ return true; }
    }
    else { return false; }
}


void ExecuteOR::exit() { exit(0); } 

