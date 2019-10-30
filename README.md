# CS 100 Programming Project
Creators: Ethan White ~~ SID: 861312702 && Jorge Marin ~~ SID: 862009642

# Introduction
Our goal for this assignment is to design a command shell called RShell with C++. The command shell should be designed to contain a prompt that will read a given command and print it on one line. Therefore, the RShell we will design will contain executables that will be located in the specified PATH setting; containing zero or more arguments separated by spaces or connectors (&& and | |). There are three conditions that me and my partner will reference for the connectors of a command used in this assignment. First, if a command is preceded by the “;” connector, then the command will always execute. If a command is followed by the “&&” connector, then the following command is only executed if the first command passes. The final condition is if a command is followed by the “| |” connector, then the next command is executed only if the first command fails. One final note for this assignment is that only commands that can be executed through PATH directories should be used in the shell; therefore, commands like “ls” and “cd” are not needed for this assignment.

# Design

