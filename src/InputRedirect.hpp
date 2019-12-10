#ifndef __INPUTREDIRECT_HPP__
#define __INPUTREDIRECT_HPP__

#include "rShell.hpp"
#include "Execute.cpp"

class InputRedirect : public rShell {
  public:
  InputRedirect(Base* rhs, Base* lhs);
  InputRedirect();
  virtual bool execute(int input, int output);

};

#endif

