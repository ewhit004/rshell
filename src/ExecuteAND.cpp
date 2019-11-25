#include <iostream>
#include "rShell.hpp"
#include "ExecuteAND.hpp"
using namespace std;

bool ExecuteAND::execute() {
   if(this->left->execute()){
	cout << "In AND execute: left was successful" << endl;
	if(this->right == NULL) {
		cout << "Right pointer is NULL" << endl;
	}
	return this->right->execute();
   }
   return false; 
}

void ExecuteAND::exitOut() { exit(0); }
