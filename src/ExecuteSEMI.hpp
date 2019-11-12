#ifndef __EXECUTE_SEMI_HPP__
#define __EXECUTE_SEMI_HPP__
#include "rShell.hpp"
#include <vector>

using namespace std;

class ExecuteSEMI : public rShell {
	public:
		ExecuteSEMI() : rShell() {}
		ExecuteSEMI(rShell *left, rShell *right) : rShell() {L = left; R = right;}
		void execute;
		void exit();

	private: 
		rShell* left;
		rShell* right;
};
#endif
