//Description: Print all [arg] arguments to stdout. If they are no [arg]
//arguments, simply print a newline and end the program.
#include <stdio.h>

int main(int argc, char *argv[])
{
	//If there are not [arg] arguments, print a newline 
	//and end the program
	if(argc < 2)
	{
		printf(" \n");
		return 0;
	}
	else
	{
		//Loop and print
		for(int i = 1; i < argc; i++)
		{
			printf(argv[i],"\n");
		}
	}

	return 0;

}
