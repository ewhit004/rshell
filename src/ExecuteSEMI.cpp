#include <iostream>
#include "ExecuteSEMI.hpp"
using namespace std;

bool ExecuteSEMI::execute() { 
this->left->execute();

if(this->right->execute()){ return true; }
    else{ return false; }
}

void ExecuteSEMI::exit() { exit(0); }

