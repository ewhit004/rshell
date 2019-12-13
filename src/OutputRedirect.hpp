#ifndef __OUTPUTREDIRECT_HPP__
#define __OUTPUTREDIRECT_HPP__

#include "rShell.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class OutputRedirect : public rShell
{
  public:
     OutputRedirect() : rShell() {}
     OutputRedirect(rShell* lhs, string fileName) : rShell() {this->lhs = lhs; this->fileName = fileName;}
     char* getFilename();
     bool execute();
     bool isOutput();
  private: 
	rShell* lhs;
	string fileName;
};
#endif
