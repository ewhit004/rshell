#ifndef __EXECUTE_HPP__
#define __EXECUTE_HPP__
#include "rShell.hpp"
#include <vector>
#include <string>
using namespace std;

class Execute : public rShell {
	public: 
		Execute(vector<string> execs) : rShell(){this->execs = execs;}
		bool execute();
		void exit();

	private:
		vector<string> execs;
};
#endif
