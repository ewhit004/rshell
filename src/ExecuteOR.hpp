#ifndef __EXECUTE_OR_HPP__
#define __EXECUTE_OR_HPP__
#include "rShell.hpp"
#include <vector>

using namespace std;

class ExecuteOR : rShell {
	public:
		ExecuteOR() : rShell() {}
		ExecuteOR(rShell *left, rShell *right) : rShell() {L = left; R = right;}
		void execute();
		void exit();

	private:
        	rShell *L;
        	rShell *R;

};

#endif
