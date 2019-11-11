#ifndef __RSHELL_HPP__
#define __RSHELL_HPP__
using namespace std;

class rShell {
	public:
		rShell();
		virtual void execute(vector <Executable*> execs) = 0;
		virtual void exit() = 0;
};

#endif
