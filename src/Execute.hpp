#ifndef __EXECUTE_HPP__
#define __EXECUTE_HPP__
#include "rShell.hpp"
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Execute : public rShell {
	public: 
		Execute(vector<string> argv) : rShell() {
			this->argvString = argv;
			/*for (unsigned int i = 0; i < size; ++i) {
                                //cout << argv[i] << endl;
				//char* temp = const_cast<char*>(argv.at(i).c_str());
				string temp = argv.at(i);
				this->argv[i] = new char[temp.size() + 1];
				char c_temp[temp.size() + 1];
				strcpy(c_temp, temp.c_str());
				this->argv[i] = c_temp;
                        }
			for(unsigned int i = 0; i < size; ++i) {
				cout << argv[i] << endl;
			}*/
			//cout << "Passes constructor" << endl;
			//this->argv[0] = argv[0];
			//cout << this->argv[0] << endl;
			/*for (unsigned int i = 0; i < size; ++i) {
		                this->argv[i] = argv[i];
        		}*/
		}
		//Execute(vector<string> execs);
		bool execute();
		void exitOut();

	private:
		vector<string> argvString;
};
#endif
