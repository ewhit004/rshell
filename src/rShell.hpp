#ifndef __RSHELL_HPP__
#define __RSHELL_HPP__
//#include <vector>
using namespace std;

class rShell {
	public:
		rShell(){};
		virtual bool execute() = 0;
		virtual void exitOut() = 0;
		virtual bool isPipe() {return false;}
		virtual bool execute(int output_fd, int pipeNum) {return false;}
};

#endif
