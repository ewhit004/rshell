//#include <iostream>
#include "rShell.hpp"
#include "piping.hpp"
using namespace std;

bool piping::execute() {
	int pipe_fd[2];
	pipe(pipe_fd); //in pipe, first process writes into pipe and then the output of that pipe becomes the input for the second process
}
bool piping::execute(int in, int out) {
	
}
void piping::exitOut() { exit(0); }

