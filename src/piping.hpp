#ifndef __PIPING_HPP__
#define __PIPING_HPP__

#include "rShell.hpp"
#include <vector>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

class Piping : public rShell {
    public:
    	Piping() : rShell() {}
    	Piping(rShell *left, rShell *right) : rShell() {this->left = left; this->right = right;}
	bool execute();
    	bool execute(int output_fd, int pipeNum);
	bool isPipe();
	void exitOut();
    private:
	rShell *left;
	rShell *right;
};

#endif

