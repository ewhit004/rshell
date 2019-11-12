#include <iostream>
#include "ExecuteAND.hpp"
using namespace std;

bool ExecuteAND::execute() {
   if (this->left->execute()){
       if(this->right->execute()){ return true; } 
   }
       else { return false; }
}

void ExecuteAND::exit() { exit(0); }
