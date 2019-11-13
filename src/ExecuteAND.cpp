#include <iostream>
#include "rShell.hpp"
#include "ExecuteAND.hpp"
using namespace std;

bool ExecuteAND::execute() {
   if (this->left->execute()){
       if(this->right->execute()){ 
		return true; 
       } 
   }
   return false; 
}

void ExecuteAND::exitOut() { exit(0); }
