//Description: Print all [arg] arguments to stdout. If they are no [arg]
//arguments, simply print a newline and end the program.
#include <stdio.h>

int main(int argc, char *argv[])
{
	//If there are no [arg] arguments, print a newline 
	//and end the program
	if(argc < 2)
	{
		printf(" \n");
		return 0;
	}
	else
	{
		//Loop, increment and  print all the 
		//arguments entered by user starting
		//at i = 1, argv[1]
		for(int i = 1; i < argc; i++)
		{
			printf(argv[i]);
			printf(" ");
		}
	}

	printf("\n"); //print a newline
	return 0;
}
