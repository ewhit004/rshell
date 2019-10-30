#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void commandParser(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	string fullcommand;

	cout << "Number of args: " << argc << endl;
	cout << "Contents in array: " << endl;
	for (unsigned int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	char* updatedArgs[] = {argv[1], NULL};
	cout << "Beginning a fork" << endl;
	pid_t pid = fork();
	if (pid < 0) { //error occurred
		perror("Error upon creating fork");
	}
	else if (pid == 0) { //this code is only executed by child process
		cout << "This is the child process. pid = " <<  getpid() << endl;
		cout << "Executing " << updatedArgs[0] << endl;
		execvp(updatedArgs[0], updatedArgs);
		cout << "This is code after execvp and should not be executed" << endl;
	}
	else { //this code is only executed by parent process
		waitpid(pid, NULL, 0);
		cout << "This is the parent process. pid = " << getpid() << endl;
	}
	cout << "This should be the last line outputted as the program continues its code" << endl;
		
	return 0;
}

void commandParser(int argc, char* argv[]) {
	int executableCount = 0;
	int connectorCount = 0;
	int argumentCount = 0;
	if (argc > 0) {
		++argumentCount; //first command will be argument
		for (unsigned int i = 0; i < argc; ++i) {//iterate through everything in the argv.
				//for first and following arguments, check last char in string to see if it is ';' connector
				//if it is, ++connectorCount and next arg is going to be another executable
				//if its none of these, then its an argument so ++argument 
		}
	}
}











