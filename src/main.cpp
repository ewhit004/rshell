#include "rShell.hpp"
#include "Execute.hpp"
#include "executeAND.hpp"
#include "executeOR.hpp"
#include "executeSEMI.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



void print() {
	cout << "$ " << endl;
}

int main() {
	string userCommand;
	CommandLine* commandLine = new CommandLine();
	commandLine->print();
	getline(cin, userCommand);

	return 0;
}
