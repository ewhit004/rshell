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
    	Piping() : public rShell() {}
    	Piping(rShell *left, rShell *right) : public rShell() {this->left = left; this->right = right;}
	bool execute();
    	bool execute(int in, int out);

    private:
	rShell *left;
	rShell *right;

};

#endif

