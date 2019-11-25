#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h> //for perror and fork
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
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
	if (this->argvString.at(0) == "test") { //special case where test is executable. NOT supposed to use execvp
		struct stat buf;
		bool temp = false;
		//stat(this->argvString.at(argvString.size() - 1).c_str(), &buf);
		if (stat(argvString.at(argvString.size() - 1).c_str(), &buf) == 0) {
	                if (this->argvString.at(1) == "-f") { //checks if the file/directory exists and is a regular file
				if(S_ISREG(buf.st_mode)) {
					temp = true;
				}
			}
			else if (this->argvString.at(1) == "-d") { //checks if the file/directory exists and is a directory
				if(S_ISDIR(buf.st_mode)) {
	                                temp = true;
	                        }
	                }
			else { //checks if the file/directory exists (default if user doesn't specify flag)
				temp = true;
			}
		}
		if(temp) {
			cout << "(True)" << endl;
		}
		else {
			cout << "(False)" << endl;
		}
		return temp;
		
        }
	char* argv[this->argvString.size() + 1];
	for(unsigned int i = 0; i < this->argvString.size(); ++i) {
		char* temp = const_cast<char*>(this->argvString.at(i).c_str());
		argv[i] = temp;
	}
	argv[this->argvString.size()] = '\0';
	pid_t pid = fork();
	if(pid < 0) {		//printing fork error
		perror("Error upon creating fork");
		return false;
	}
	else if(pid == 0) { 
		execvp(argv[0], argv);
		exit(0);
		cout << "should not see this" << endl;
	}	
	else{	//start parent process of fork
	/*	int status;
		if(waitpid(pid, &status, 0) < 0) { perror("waitpid"); }    //execute
		if(WEXITSTATUS(status) != 0) { result = false; }           //checks if child process has finished; if not, return false
	*/
		waitpid(pid, NULL, 0);
		//cout << "Parent process finished successful" << endl;
		return true;
	}	
	return false;
}
//----------------------------------------------------------------------	

void Execute::exitOut() { 
	exit(0);
}
