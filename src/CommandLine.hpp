#ifndef __COMMAND_LINE_HPP__
#define __COMMAND_LINE_HPP__
#include "rShell.hpp"
using namespace std;

class CommandLine : public rShell {
	public:
		CommandLine() : rShell() {}
		void execute(vector<Executable*> execs);
		void exit();
		void print();
};
#endif
