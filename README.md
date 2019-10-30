# *CS 100 Programming Project*
Creators: Ethan White ~~ SID: 861312702 && Jorge Marin ~~ SID: 862009642

# *Introduction*
Our goal for this assignment is to design a command shell called RShell with C++. The command shell should be designed to contain a prompt that will read a given command and print it on one line. Therefore, the RShell we will design will contain executables that will be located in the specified PATH setting; containing zero or more arguments separated by spaces or connectors (&& and | |). There are three conditions that me and my partner will reference for the connectors of a command used in this assignment. First, if a command is preceded by the “;” connector, then the command will always execute. If a command is followed by the “&&” connector, then the following command is only executed if the first command passes. The final condition is if a command is followed by the “| |” connector, then the next command is executed only if the first command fails. One final note for this assignment is that only commands that can be executed through PATH directories should be used in the shell; therefore, commands like “ls” and “cd” are not needed for this assignment.

# *Design*



# *Classes* 
**rShell (base class) →**
This class is the implementation, virtual, class that will run functions as they arise in our RShell terminal. 
→ *virtual void print () = 0;*  This function is purely virtual, which will permit it to be implemented in parent and subclasses. 
→ *virtual void execute(vector <Executable*> execs) = 0;*   This function is also purely virtual. However, our planned implementation                                                               for sub and parent classes, would be to let the user execute their commands                                                             on the lines given in our shell. It is passed in a vector of executable                                                                 files to be executed depending on the connector.
→ *exit();*                 As the name implies, this function will allow the user to exit their current state in the program.

**executable class →** 
This class does not inherit from rShell but is referenced by the CommandLine class. This class stores the information needed for each executable to actually be executed. This includes the number of arguments and an array of null terminated strings.
→ *int argc;*               Variable of type int that stores the number of arguments in the executable
→ *char* argv[ ];*          An array of null terminated strings that stores the contents of each argument
  
**commandLine class →**
	The class inherits from rShell and references Executable as it adds executables into a vector.
→ *void print ();*          A function that prints out a command prompt
→ *void extractExecutables(int argc, char* argv[ ]);*    This function takes in two parameters passed in from main and goes through the                                                          entire command line inputted by the user. It extracts all executables and                                                                stores them in a vector of type Executable.
→ *void execute(vector <Executable*> execs);*        This function uses the vector of Executables and determines which of the                                                                execution methods is necessary. It will then create an object of whichever of                                                            the execution methods and call it’s execute function.
  
**execute class →**
This class simply executes a single executable normally, when no connectors are found.
  
**executeAND class →**
A class that will first execute the first Execute* in the vector and will only move on to the next executable in the vector if the first one is successful. 

**executeOR class →**
A class that will execute the first Execute* in the vector and will move onto the next, if and only if, the first one fails.

**executeSEMI class →**
A class that will always execute the first Execute* in the vector, no matter what, and execute the following executables regardless of failure or success.

	

