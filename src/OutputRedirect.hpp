#ifndef __OUTPUTREDIRECT_HPP__
#define __OUTPUTREDIRECT_HPP__

#include "rShell.hpp"
#include "Execute.cpp"

class OutputRedirect: public rShell {
    public:
    OutputRedirect();
    OutputRedirect(Base* lhs, Base* rhs);
    virtual bool execute(int input, int output);
};


#endif
