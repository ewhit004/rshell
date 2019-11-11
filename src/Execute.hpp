#ifndef __EXECUTE_HPP__
#define __EXECUTE_HPP__
#include "rShell.hpp"
using namespace std;

class Execute : public rShell {
	public: 
		Execute() : rShell() {}
		void execute(vector<Executable*> execs);
		void exit();
};
#endif
