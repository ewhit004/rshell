#ifndef __EXECUTE_SEMI_HPP__
#define __EXECUTE_SEMI_HPP__
#include "rShell.hpp"
using namespace std;

class ExecuteSEMI : public rShell {
	public:
		ExecuteSEMI() : rShell() {}
		void execute(vector<Executable*> execs);
		void exit();
};
#endif
