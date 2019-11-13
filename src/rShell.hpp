#ifndef __RSHELL_HPP__
#define __RSHELL_HPP__
//#include <vector>
using namespace std;

class rShell {
	public:
		rShell(){};
		virtual bool execute() = 0;
		virtual void exitOut() = 0;
};

#endif
