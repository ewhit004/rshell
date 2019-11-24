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

/*Execute::Execute(vector<string> execs) { 
	this->execs = execs; 
}
*/
//----------------------------------------------------------------------
bool Execute::execute() {
	bool result = true;
	cout << sizeof(argv) << endl;	             //test to see if argv array is empty or not
	for (int i = 0; i < sizeof(argv); ++i) {
        	cout << argv[i] << endl;             //check to see what's inside of the array
        }
	pid_t pid = fork();
	
	if(pid < 0) {		//printing fork error
		perror("Error upon creating fork");
		return false;
	}
	else if(pid == 0) { 
		execvp(this->argv[0], argv);
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
