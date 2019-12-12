#ifndef __OUTPUTREDIRECT2_HPP__
#define __OUTPUTREDIRECT2_HPP__

#include "rShell.hpp"

class OutputRedirect2 : public rShell {
    public:
    OutputRedirect2();
    OutputRedirect2(Base* lhs, Base* rhs);
    virtual bool execute(int inFile, int outFile);
};

#endif
