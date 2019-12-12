#include "rShell.hpp"
#include "OutputRedirection2.hpp"
#include <iostream>

using namespace std;

OutputRedirect2::OutputRedirect2() { rShell::outputBegin = false; }

OutputRedirect2::OutputRedirect2(Base* left, Base* right): rShell(left, right) {}

char* OutputRedirect2::getFilename()
{
    return NULL;
}

bool OutputRedirect2::execute(int inFile, int outFile)
{
    if(rhs->getFilename() == NULL)
    {
        cout << "Error: Filename?" << endl;
        return false;
    }

    if((lhs->isOutput() || lhs->isOutput2()) && rShell::outputBegin)
    {
        open(rhs->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    }

    else if((lhs->isOutput() || lhs->isOutput2()) && !rShell::outputBegin)
    {
        outputFile = open(rhs->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        rShell::outputBegin = true;
    }
    else if(!(lhs->isOutput() && lhs->isOutput2()) && !rShell::outputBegin)
    {
        outputFile = open(rhs->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        rShell::outputBegin = false;
    }
    else
    {
        open(rhs->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        rShell::outputBegin = false;
    }

    return lhs->execute(inFile, outFile);
}

bool OutputRedirect2::isOutput2()
{
    return true;
}