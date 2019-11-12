#ifndef __EXECUTE_AND_HPP__
#define __EXECUTE_AND_HPP__
#include "rShell.hpp"
#include <vector>

using namespace std;

class ExecuteAND : public rShell {
        public:
                ExecuteAND() : rShell() {}
		ExecuteAND(rShell *left, rShell *right) : rShell() {L = left; R = right;}
                void execute;
                void exit();

	private:
		rShell* left;
		rShell* right;
};


#endif
