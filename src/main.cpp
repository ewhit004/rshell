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
//#include "rShell.hpp"
using namespace std;

rShell* parse(string targetCommand, vector<string> &quotedData);
void print();

int main() {
	print();
	string userInput;
	getline(cin, userInput);
	if(userInput == "exit") {
                exit(0);
        }
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
	rShell* parentExecute = parse(userInput, quotedData);
	parentExecute->execute();
	return 0;
}

void print() { cout << "$ "; }

rShell* parse(string userCommand, vector<string> &quotedData){
	vector<string> parser;
	size_t found1 = userCommand.find(';'); //attempts to find any connectors
        size_t found2 = userCommand.find("&&");
        size_t found3 = userCommand.find("||");
	char c_userCommand[userCommand.length() + 1];//have to convert string into array of chars to use strtokpoint = strtok(c_userCommand, "&&");
        strcpy(c_userCommand, userCommand.c_str());
        char* point;
	if((found1 == string::npos && found2 == string::npos) && found3 == string::npos) {
		//command does not have a connector
		//implement special case of quotes ""
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
		point = strtok(c_userCommand, ";");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, ";");
                }
                rShell* exec1 = parse(parser.at(0), quotedData);
                rShell* exec2 = parse(parser.at(1), quotedData);
                rShell* semiExec = new ExecuteSEMI(exec1, exec2);
                return semiExec;
	}
	else if(found2 != string::npos) {
		point = strtok(c_userCommand, "&&");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, "&&");
                }
		rShell* exec1 = parse(parser.at(0), quotedData);
		rShell* exec2 = parse(parser.at(1), quotedData);
		rShell* andExec = new ExecuteAND(exec1, exec2);
		return andExec;
	}
	else if(found3 != string::npos) {
		point = strtok(c_userCommand, "||");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, "||");
                }
                rShell* exec1 = parse(parser.at(0), quotedData);
                rShell* exec2 = parse(parser.at(1), quotedData);
                rShell* orExec = new ExecuteOR(exec1, exec2);
                return orExec;
	}
}







