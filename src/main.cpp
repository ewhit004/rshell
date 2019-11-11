#include <iostream>
#include <vector>
#include <string>
#include "rShell.hpp"
using namespace std;

int main() {
	string userCommand;
	CommandLine* commandLine = new CommandLine();
	commandLine->print();
	getline(cin, userCommand);

	return 0;
}
