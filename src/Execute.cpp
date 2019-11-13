#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h> //for perror and fork
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include "Execute.hpp"
using namespace std;

Execute::Execute(vector<string> execs) { this->execs = execs; }

//----------------------------------------------------------------------

bool result = true;

pid_t pid = fork();

if(pid < 0) {		//printing fork error
	perror("fork");
	else { return (1); }
}

else if(pid == 0) { 
	if(execvp(execs [0], execs) < 0) { 
		result = false;
		perror("exec");
		_exit(2);	//terminate calling process of child fork 
	}
	_exit(2);
}

else{	//start parent process of fork
	int status;
	if(waitpid(pid, &status, 0) < 0) { perror("waitpid"); }    //execute
	if(WEXITSTATUS(status) != 0) { result = false; }           //checks if child process has finished; if not, return false
}

return result;

//----------------------------------------------------------------------	

void Execute::exit() { exit(); }
