#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h> //for perror and fork
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include "rShell.hpp"
#include "Execute.hpp"
using namespace std;

/*Execute::Execute(char* argv[], int size) { 
	for (unsigned int i = 0; i < size; ++i) {
		this->argv[i] = argv[i];
	}
}*/

//----------------------------------------------------------------------
bool Execute::execute() {
	char* argv[this->argvString.size() - 1];
	for(unsigned int i = 0; i < this->argvString.size(); ++i) {
		char* temp = const_cast<char*>(this->argvString.at(i).c_str());
		argv[i] = temp;
	}
	pid_t pid = fork();
	if(pid < 0) {		//printing fork error
		perror("Error upon creating fork");
		return false;
	}
	else if(pid == 0) { 
		execvp(argv[0], argv);
		return false;
	}	
	else{	//start parent process of fork
	/*	int status;
		if(waitpid(pid, &status, 0) < 0) { perror("waitpid"); }    //execute
		if(WEXITSTATUS(status) != 0) { result = false; }           //checks if child process has finished; if not, return false
	*/
		waitpid(pid, NULL, 0);
		return true;
	}	

}
//----------------------------------------------------------------------	

void Execute::exitOut() { 
	exit(0);
}
