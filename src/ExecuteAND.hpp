#ifndef __EXECUTE_AND_HPP__
#define __EXECUTE_AND_HPP__
#include "rShell.hpp"
using namespace std;

class ExecuteAND : public rShell {
	public:
		ExecuteAND() : rShell() {}
		void execute(vector<Executable*> execs);
		void exit();
};

#endif
