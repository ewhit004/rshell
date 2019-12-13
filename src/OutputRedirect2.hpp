#ifndef __OUTPUTREDIRECT2_HPP__
#define __OUTPUTREDIRECT2_HPP__

#include "rShell.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class OutputRedirect2 : public rShell {
    public:
    OutputRedirect2() : rShell() {}
    OutputRedirect2(rShell* lhs, string fileName) : rShell() {this->lhs = lhs; this->fileName = fileName;}
    char* getFilename();
    bool execute(int inFile, int outFile);
    bool isOutput2();
    private: 
	rShell* lhs;
	string fileName;
};

#endif
