//Description: If the [file.txt] argument is passed, open the file 
//and print it to stdout. If there is no second argument, repeat what the user 
//types on stdinback to stdout(until the user hits CTRL+D to indicate EOF).
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//delcare variables
	FILE *stream;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t  nread;
	int character;

	//This call to fopen() takes the path to a file to open
	//(the argument is argv[1], the filename provided by 
	//the user), followed by the access mode (the "r" argument
	//means read only). fopen returns a FILE * (pointer to
	//a stream representing the open file)
	if(stream = fopen(argv[1],"r"))
	{
		//This call to getline() reads an entire line from stream
		//since *lineptr is set to NULL and *n is set to 0
		//before the call, getline() will allocate a buffer
		//for storing the line
		while((nread = getline(&lineptr, &n, stream)) != -1)
		{
			fwrite(line, nread, 1, stdout);
		} 
		
		//This call to fclose() flushes the stream pointed to 
		//by the stream and closes the underlying file descriptor.
		//When successful, 0 is returned. Program exits
		fclose(stream);
		exit(EXIT_SUCCESS);
	}
	else
	{
		character = getchar();
		while(character != EOF)
		{
			putchar(character);
			character = getchar();
		
		}
		return 0;
	}
}
