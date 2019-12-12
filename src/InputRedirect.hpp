#ifndef __INPUTREDIRECT_HPP__
#define __INPUTREDIRECT_HPP__

#include "rShell.hpp"

class InputRedirect : public rShell {
  public:
  InputRedirect();
  InputRedirect(Base* rhs, Base* lhs);
  virtual bool execute(int inFile, int outFile);
  virtual isInput(); 
};

#endif

