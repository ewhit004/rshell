#ifndef __OUTPUTREDIRECT_HPP__
#define __OUTPUTREDIRECT_HPP__

#include "rShell.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class OutputRedirect : public rShell
{
  public:
     OutputRedirect();
     OutputRedirect(Base* lhs, Base* rhs);
     bool execute(int inFile, int outFile);
     char* getFilename();
     bool isOutput();
}
#endif
