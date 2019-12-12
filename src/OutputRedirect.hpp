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
     char* getFilename();
     bool execute(int inFile, int outFile);
     bool isOutput();
}
#endif
