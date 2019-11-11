#ifndef __EXECUTE_OR_HPP__
#define __EXECUTE_OR_HPP__
#include "rShell.hpp"
using namespace std;

class ExecuteOR : rShell {
	public:
		ExecuteOR() : rShell() {}
		void execute(vector<Executable*> execs);
		void exit();
};

#endif
