#ifndef __EXECUTE_HPP__
#define __EXECUTE_HPP__
#include "rShell.hpp"
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Execute : public rShell {
	public: 
		Execute(char* argv[]) : rShell() {memcpy(this->argv, argv, sizeof(argv));}
		//Execute(vector<string> execs);
		bool execute();
		void exitOut();

	private:
		char* argv[];
};
#endif
