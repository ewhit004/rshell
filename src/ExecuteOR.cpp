#include <iostream>
#include "ExecuteOR.hpp"
using namespace std;

bool ExecuteOR::execute() {   
    //cout << "Should not see this" << endl; 
    if (!(this->left->execute())) {
        return this->right->execute();
    }
    else { return true; }
}


void ExecuteOR::exitOut() { exit(0); } 

