#include <iostream>
#include "OutputRedirect.hpp"

using namespace std;

/*OutputRedirect::OutputRedirect()
{
    rShell::outputBegin = false;
}*/

//OutputRedirect::OutputRedirect(Base* lhs, Base* rhs): rShell(lhs, rhs) {}

char* OutputRedirect::getFilename()
{
    return NULL;
}

bool OutputRedirect::execute(int inFile, int outFile)
{
    if(rhs->getFilename() == NULL)
    {
        cout << "Error: Filename?" << endl;
        return false;
    }

    if((lhs->isOutput() || lhs->isDoubleOutput()) && rShell::outputBegin)
    {
        open(rhs->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    }
    else if((lhs->isOutput() || left->isDoubleOutput()) && !rShell::outputBegin)
    {
        outFile = open(rhs->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        rShell::outputBegin = true;
    }
    else if(!(lhs->isOutput() && lhs->isDoubleOutput()) && !rShell::outputBegin)
    {
        outFile = open(rhs->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        rShell::outputBegin = false;
    }
    else
    {
        open(rhs->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        rShell::outputBegin = false;
    }
    return lhs->execute(inFile,outFile);

}

bool OutputRedirect::isOutput()
{
    return true;
}
