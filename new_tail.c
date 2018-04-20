//Description: If [file.txt] is specified, print the last N lines of that file
//(default is 5 lines if -n is not used). Otherwise, read from stdin until the
//user hits CTRL+D, and print the last N lines typed by the user.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 512

int main(int argc, char *argv[])
{
	//Declarations
	FILE *stream;
	char *path;
	int number;
	int line = 5; //default lines
	int count = 0;
	int index = 0;
	char buffer[BUFFSIZE][BUFFSIZE];
	
	//getopt() is used to break up (parse) options
	//in command lines for easy parsing by shell procedure
	//here we use it for -n flag and ':' is added so 
	//an arugment(number) should be added after the flag
	while((number = getopt(argc, argv, "n:")) != -1)
	{
		//atoi() takes a string here optarg
		//as an argument and returns its value
		int newLine = atoi(optarg);

		//change default lines to user's line number
		//when -n flag is used
		line = newLine; 
	}

	//The variable optind is the index of the 
	//next element to be processed in argv
	//let path equals it for fopen to use the path
	//to open the file 
	path = argv[optind];

	//This part should be implemented when user 
	//enters no arg it should read from stdin
	//until user hits CTRL+D, and prints out 
	//the last N lines typed by the user
	/*if(argc < 2)
	{
		while((character = getchar()) != EOF)
		{
			putchar(character);
		}
		return 0;
	}*/

	//This call to fopen() takes the path to a file to open
	//(the argument is argv[1], the filename provided by
	//the user), followed by the access mode (the "r" argument
	//means read only). fopen returns a FILE * (pointer to
	//a stream representing the open file)
	stream = fopen(path, "r");
	
	//If the file does not exist or fopen fails
	//print an error message
	if(stream == NULL)
	{	
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	
	//The while loop makes it read to the end of file
	while(!feof(stream))
	{
		//increment counter
		count++;

		//This call to fgets() reads in at most one
		//less than BUFFSIZE characters from stream
		//and stores them into the buffer.
		fgets(buffer[index],BUFFSIZE,stream);
		if(index + 1 >= line)
		{
			index = 0;
		}
		else
		{
			index++;
		}
		
	}
	
	//This call to fclose() flushes the stream pointed to
	//by the stream and closes the underlying file descriptor.
	fclose(stream);
	if(count < line)
	{
		line = count;
	}
	//Because of the increment ++ before
	//there is an extra 1 added, decrement here
	if(index != 0)
	{
		index--;
	}
	//loop through and print
	for(int i = 0; i< line; i++)
	{
		printf("%s",buffer[index++]);
		if(index >= line)
		{
			index = 0;
		}
	}
}
