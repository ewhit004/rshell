#include <iostream>
#include "ExecuteSEMI.hpp"
using namespace std;

bool ExecuteSEMI::execute() { 
	bool temp = this->left->execute();

	if(this->right->execute()){ return true; }
	return false;
}

void ExecuteSEMI::exitOut() { exit(0); }

