#include "rShell.hpp"
#include "InputRedirect.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>

using namespace std;

/*InputRedirect::InputRedirect(): rShell() {}
InputRedirect::InputRedirect(Base* lhs, Base* rhs): rShell(lhs, rhs) {}
*/

bool InputRedirect::execute() {
    if(right->getFilename() == NULL)
    {
        cout << "Error: Filename?";
        return false;
    }

    inFile = open(right->getFilename(), O_RDONLY);
    return left->execute(inFile, outFile);
}

bool InputRedirection::isInput()
{
    return true;
}

