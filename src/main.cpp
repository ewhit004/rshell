#include "rShell.hpp"
#include "Execute.hpp"
#include "executeAND.hpp"
#include "executeOR.hpp"
#include "executeSEMI.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
//#include "rShell.hpp"
using namespace std;

rShell* parse(string targetCommand);

using namespace std;



void print() {
	cout << "$ " << endl;
}

int main() {
	vector<string> parser;
	string userCommand;
	getline(cin, userCommand);
	size_t found1 = userCommand.find(';');
	size_t found2 = userCommand.find("&&");
	size_t found3 = userCommand.find("||");
	char c_userCommand[userCommand.length() + 1];
        strcpy(c_userCommand, userCommand.c_str());
        char* point;

	if((found1 == string::npos && found2 == string::npos) && found3 == string::npos) {
		//command does not have a connector
                point = strtok(c_userCommand, " ");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, " ");
                }
		Execute* execute = new Execute(parser);
	}
	if(found2 != string::npos) {
		//char c_userCommand[userCommand.length() + 1];
                //strcpy(c_userCommand, userCommand.c_str());
                //char* point;
                point = strtok(c_userCommand, "&&");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, "&&");
                }
		string firstExec = parser.at(0);
		string secExec = parser.at(1);
		vector<string> leftExec;
		vector<string> rightExec;
		char c_firstExec[firstExec.length() + 1];
        	strcpy(c_firstExec, firstExec.c_str());
		point = strtok(firstExec, " ");
		while(point != NULL) {
			leftExec.push_back(string(point));
			point = strtok(NULL, " ");
		}
		char c_secExec[secExec.length() + 1];
                strcpy(c_secExec, secExec.c_str());
                point = strtok(secExec, " ");
                while(point != NULL) {
                        rightExec.push_back(string(point));
                        point = strtok(NULL, " ");
                }
		Execute* exec1 = new Execute(leftExec);
		Execute* exec2 = new Execute(rightExec);
		ExecuteAND* andExec = new ExecuteAND(leftExec, rightExec);
	}
	if(found != string::npos) {
		//char c_userCommand[userCommand.length() + 1];
		//strcpy(c_userCommand, userCommand.c_str());
		//char* point;
		point = strtok(c_userCommand, ";");
		while(point != NULL) {
			parser.push_back(string(point));
			point = strtok(NULL, ";");
		}
		for(unsigned int i = 0; i < parser.size(); ++i) {
			cout << parser.at(i) << endl;
		}
	}
	
	return 0;
}


rShell* parse(string targetCommand){
	vector<string> parser;
	size_t found1 = userCommand.find(';');
        size_t found2 = userCommand.find("&&");
        size_t found3 = userCommand.find("||");
	char c_userCommand[userCommand.length() + 1];
        strcpy(c_userCommand, userCommand.c_str());
        char* point;
	if((found1 == string::npos && found2 == string::npos) && found3 == string::npos) {
	//command does not have a connector
		point = strtok(c_userCommand, " ");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, " ");
                }
                Execute* execute = new Execute(parser);
		return execute;
	}
	if(found2 != string::npos) {
		point = strtok(c_userCommand, "&&");
                while(point != NULL) {
                        parser.push_back(string(point));
                        point = strtok(NULL, "&&");
                }
                string firstExec = parser.at(0);
                string secExec = parser.at(1);
                vector<string> leftExec;
                vector<string> rightExec;
                char c_firstExec[firstExec.length() + 1];
                strcpy(c_firstExec, firstExec.c_str());
                point = strtok(firstExec, " ");
                while(point != NULL) {
                        leftExec.push_back(string(point));
                        point = strtok(NULL, " ");
                }
                char c_secExec[secExec.length() + 1];
                strcpy(c_secExec, secExec.c_str());
                point = strtok(secExec, " ");
                while(point != NULL) {
                        rightExec.push_back(string(point));
                        point = strtok(NULL, " ");
                }
                Execute* exec1 = new Execute(leftExec);
                Execute* exec2 = new Execute(rightExec);
                ExecuteAND* andExec = new ExecuteAND(leftExec, rightExec);
	}
