#include <iostream>
#include "ExecuteSEMI.hpp"
using namespace std;

bool ExecuteSEMI::execute() { 
	this->left->execute();
	return this->right->execute();
}

void ExecuteSEMI::exitOut() { exit(0); }

