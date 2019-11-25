#include <iostream>
#include "rShell.hpp"
#include "ExecuteAND.hpp"
using namespace std;

bool ExecuteAND::execute() {
   if(this->left->execute()){
	return this->right->execute();
   }
   return false; 
}

void ExecuteAND::exitOut() { exit(0); }
