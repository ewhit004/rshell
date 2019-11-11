#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__
using namespace std;

class Executable {
	public:
		Executable();
		Executable(int argc, char* argv[]);
		void set_argc(int argc);
		void set_argv(char* argv[]);
		int get_argc();
		char* get_argv();
	private:
		int argc;
		char* argv[];
};
#endif
