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
#include <iterator> 
#include <map>
#include <stdio.h>
using namespace std;

rShell* parse(string targetCommand, vector<string> &quotedData, vector<string> &parenthesisData);
void print();
string extractParenthesis(string userInput, vector<string> &parenthesisData);

int main() {
	string userInput;
	bool temp;
	//map<int, string> parenthesisMap
	restart:
	print();
	getline(cin, userInput);
	while(userInput != "exit") {
		size_t foundComment = userInput.find('#');
		if(foundComment != string::npos) {
			userInput.erase(foundComment, userInput.size() - 1);
		}
		if(userInput != "") {
			string targetString; //if command has a quoted string(s), temporarly stored here and then into vector
			vector<string> quotedData;
			vector<string> parenthesisData;
			size_t found = userInput.find('"');
			int firstIndex;
			int secIndex;
			while(found != string::npos) {
				firstIndex = userInput.find_first_of('"');
				secIndex = userInput.find_first_of('"', found + 1);
				targetString = userInput.substr(firstIndex, (secIndex - firstIndex) + 1);
				userInput.replace(firstIndex, (secIndex - firstIndex) + 1, "quoteString");
				quotedData.push_back(targetString);
				found = userInput.find('"');
			}
			found = userInput.find('(');//looks for parenthesis in the userInput
			if (found != string::npos) {
				int x = 0;
				int y = 0;
				for (size_t found = userInput.find_first_of('('); found != string::npos; found = userInput.find_first_of('(', found + 1)) {
					++x;
				}
				for (size_t found = userInput.find_first_of(')'); found != string::npos; found = userInput.find_first_of(')', found + 1)) {
                                        ++y;
                                }
				if (x != y) {
					cout << "Invalid Input" << endl;
					goto restart;
				}
				while (found != string::npos) {
					firstIndex = userInput.find_first_of('(');
					secIndex = userInput.find_first_of(')');
					targetString = userInput.substr(firstIndex, (secIndex - firstIndex) + 1);
					userInput.replace(firstIndex, (secIndex - firstIndex) + 1, "parenthesisString");
					parenthesisData.push_back(targetString);
					//userInput = extractParenthesis(userInput, parenthesisData);
					found = userInput.find('(');
				}
			}
			found = userInput.find('['); //looks for any bracket test commands in userinput and replaces them with just "test"
			while (found != string::npos) {
				firstIndex = userInput.find_first_of('[');
				userInput.replace(firstIndex, 1, "test");
				secIndex = userInput.find_first_of(']');
				userInput.erase(secIndex, 1);
				found = userInput.find('[');
			}

			//cout << "userInput before parse: " << userInput << endl;
			rShell* parentExecute = parse(userInput, quotedData, parenthesisData);				
			if(!parentExecute->execute()) {
				cout << "Execution failed" << endl;
			}
			print();
 	                getline(cin, userInput);

		}
	}
	exit(0);
	return 0;
}

void print() { cout << "$ "; }

rShell* parse(string userCommand, vector<string> &quotedData, vector<string> &parenthesisData){
	vector<string> parser;
	size_t found1 = userCommand.find(';'); 	  //attempts to find any ; connectors in parsed content
        size_t found2 = userCommand.find("&&");	  //attempts to find any && connectors in parsed content 
        size_t found3 = userCommand.find("||");	  //attempts to find any || connectors in parsed content
	
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
                        if(string(point) == "quoteString") {
				string temp = quotedData.at(0);
                                temp = temp.substr(1, temp.size() - 2);
                                parser.push_back(temp);
                                quotedData.erase(quotedData.begin());
               		}
			else if (string(point) == "parenthesisString") {
				string temp = parenthesisData.back();
				temp = temp.substr(1, temp.size() - 2); //deletes the parenthesis from the sentence
				parenthesisData.erase(parenthesisData.end());
				return parse(temp, quotedData, parenthesisData);
			}
			else {
				parser.push_back(string(point));
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
                rShell* exec1 = parse(leftParse, quotedData, parenthesisData);
                rShell* exec2 = parse(rightParse, quotedData, parenthesisData);
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
                rightParse = userCommand.substr(found2 + 2, userCommand.size() - 1);
		rShell* exec1 = parse(leftParse, quotedData, parenthesisData);
		rShell* exec2 = parse(rightParse, quotedData, parenthesisData);
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
                rightParse = userCommand.substr(found3 + 2, userCommand.size() - 1);
                rShell* exec1 = parse(leftParse, quotedData, parenthesisData);
                rShell* exec2 = parse(rightParse, quotedData, parenthesisData);
                rShell* orExec = new ExecuteOR(exec1, exec2);
                return orExec;
	}
}

/*string extractParenthesis(string userInput, vector<string> &parenthesisData) {
	int firstIndex = userInput.find_first_of('(');
	int secIndex = userInput.find_first_of(')');
	if (firstIndex == string::npos && secIndex == string::npos) {
		parenthesisData.push_back(userInput);
		return userInput.replace(0, userInput.size(), "parenthesisString");
	}
	size_t found = userInput.find_first_of('(', firstIndex + 1);
	string temp;
	while (found != string::npos) {
		secIndex = userInput.find_first_of(')', secIndex + 1);
		found = userInput.find_first_of('(', found + 1);
	}
	temp = userInput.substr(firstIndex + 1, (secIndex - firstIndex) - 1);
	temp = extractParenthesis(temp);
	if(temp == "parenthesisString") {
		userInput.replace(firstIndex, (secIndex - firstIndex) + 1, temp);
		return userInput;
	}
	userInput.replace(firstIndex, (secIndex - firstIndex) + 1, extractParenthesis(temp));
	return userInput;
}*/

/*string extractParenthesis(string userInput, vector<string> &parenthesisData) {
	int firstIndex = userInput.find_first_of('(');
	int secIndex = userInput.find_first_of(')');
	if (firstIndex == string::npos && secIndex == string::npos) {
		//push back 
		parenthesisData.push_back(userInput);
		return userInput.replace(0, userInput.size(), "parenthesisString");
	}
	size_t found = userInput.find_first_of('(', firstIndex + 1);
	string temp;
	while (found != string::npos) {
		if (found > secIndex) {
			break;
		}
		secIndex = userInput.find_first_of(')', secIndex + 1);
		found = userInput.find_first_of('(', found + 1);
	}
	temp = userInput.substr(firstIndex + 1, (secIndex - firstIndex) - 1);
	temp = extractParenthesis(temp, parenthesisData);
	if (temp == "parenthesisString") {
		userInput.replace(firstIndex, (secIndex - firstIndex) + 1, temp);
		return userInput;
	}
	userInput.replace(firstIndex, (secIndex - firstIndex) + 1, extractParenthesis(temp, parenthesisData));
	return userInput;
}*/
