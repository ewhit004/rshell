#ifndef __INPUTREDIRECT_HPP__
#define __INPUTREDIRECT_HPP__

#include "Execute.hpp"
#include "Execute.cpp"

class InputRedirect : public Connector {
  public:
  InputRedirect(Base* rhs, Base* lhs);
  InputRedirect();
  virtual bool execute(int in, int out);

};

#endif

