#include "rShell.hpp"
#include "Execute.hpp"
#include "ExecuteAND.hpp"
#include "ExecuteOR.hpp"
#include "ExecuteSEMI.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

rShell* parse(string targetCommand, vector<string> &quotedData);
void print();

int main() {
	string userInput = "echo hello world";
	bool temp;
	print();
	vector<string>quotedData;
	cout << userInput << endl;	

	/*getline(cin, userInput);
	while(userInput != "exit") {
		size_t foundComment = userInput.find('#');
		if(foundComment != string::npos) {
			userInput.erase(foundComment, userInput.size() - 1);
		}
		if(userInput != "") {
			string quotedString; //if command has a quoted string(s), temporarly stored here and then into vector
			vector<string> quotedData;
			string replaceString = "replaceString";
			size_t found = userInput.find('"');
			size_t foundQuote;
			int firstIndex;
			int secIndex;
			while(found != string::npos) {
				foundQuote = userInput.find_first_of('"');
				firstIndex = foundQuote;
				foundQuote = userInput.find_first_of('"', found + 1);
				secIndex = foundQuote;
				quotedString = userInput.substr(firstIndex, (secIndex - firstIndex) + 1);
				userInput.replace(firstIndex, (secIndex - firstIndex) + 1, replaceString);
				quotedData.push_back(quotedString);
				found = userInput.find('"');
			}

			*/
			rShell* parentExecute = parse(userInput, quotedData);

			if(parentExecute->execute()) {
				cout << "Success" << endl;
			}

			else { 
				cout << "try again, doofus" << endl;
			}				
			print();
 	               /* getline(cin, userInput);

		}*/
	//exit(0);
	return 0;
}

void print() { cout << "$ "; }

rShell* parse(string userCommand, vector<string> &quotedData){
	vector<string> parser;
	size_t found1 = userCommand.find(';'); //attempts to find any connectors
        size_t found2 = userCommand.find("&&");
        size_t found3 = userCommand.find("||");
	
	/*char c_userCommand[userCommand.length() + 1];//have to convert string into array of chars to use strtokpoint = strtok(c_userCommand, "&&");
        strcpy(c_userCommand, userCommand.c_str());
        char* point;*/

	string leftParse;
	string rightParse;
	if((found1 == string::npos && found2 == string::npos) && found3 == string::npos) {
		//command does not have a connector
		vector<string> parser;
		char c_userCommand[userCommand.length() + 1];//have to convert string into array of chars to use strtokpoint = strtok(c_userCommand, "&&");
	        strcpy(c_userCommand, userCommand.c_str());
	        char* point;

		point = strtok(c_userCommand, " ");
                while(point != NULL) {
                        if(string(point) != "replaceString") {
				parser.push_back(string(point));
               		}
			else {
				parser.push_back(quotedData.at(0));
				quotedData.erase(quotedData.begin());
			}
			point = strtok(NULL, " ");
		}
		rShell* execute = new Execute(parser);
		return execute;
	}
	else if(found1 != string::npos) {
		/*point = strtok(c_userCommand, ";");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, ";");
                }
		*/
		leftParse = userCommand.substr(0, found1);
		rightParse = userCommand.substr(found1 + 1, userCommand.size() - 1);
                rShell* exec1 = parse(leftParse, quotedData);
                rShell* exec2 = parse(rightParse, quotedData);
                rShell* semiExec = new ExecuteSEMI(exec1, exec2);
                return semiExec;
	}
	else if(found2 != string::npos) {
		/*point = strtok(c_userCommand, "&&");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, "&&");
                }*/
		leftParse = userCommand.substr(0, found2);
                rightParse = userCommand.substr(found2 + 1, userCommand.size() - 1);
		rShell* exec1 = parse(leftParse, quotedData);
		rShell* exec2 = parse(rightParse, quotedData);
		rShell* andExec = new ExecuteAND(exec1, exec2);
		return andExec;
	}
	else if(found3 != string::npos) {
		/*point = strtok(c_userCommand, "||");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, "||");
                }*/
		leftParse = userCommand.substr(0, found3);
                rightParse = userCommand.substr(found3 + 1, userCommand.size() - 1);
                rShell* exec1 = parse(leftParse, quotedData);
                rShell* exec2 = parse(rightParse, quotedData);
                rShell* orExec = new ExecuteOR(exec1, exec2);
                return orExec;
	}
}
