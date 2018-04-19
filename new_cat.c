//Description: If the [file.txt] argument is passed, open the file 
//and print it to stdout. If there is no second argument, repeat what the user 
//types on stdinback to stdout(until the user hits CTRL+D to indicate EOF).
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//delcare variables
	FILE *stream;
	char *line = NULL;
	size_t n = 0;
	ssize_t  nread;
	int character;

	//If the user passed in > 2 arguments,
	//prints out a error message
	if(argc > 2)
	{
		fprintf(stderr, "The arguments are > 2, please retry.\n");
		exit(EXIT_FAILURE);
	}

	//This call to fopen() takes the path to a file to open
	//(the argument is argv[1], the filename provided by 
	//the user), followed by the access mode (the "r" argument
	//means read only). fopen returns a FILE * (pointer to
	//a stream representing the open file)
	else if(stream = fopen(argv[1],"r"))
	{	
		//This call to getline() reads an entire line from stream
		//since *line pointer is set to NULL and *n is set to 0
		//before the call, getline() will allocate a buffer
		//for storing the line
		while((nread = getline(&line, &n, stream)) != -1)
		{
			//This call to fwrite() writes items of data 
			//each size bytes long, to stdout pointed to
			//by stream, obtaining them from the location
			//given by ptr line
			fwrite(line, nread, 1, stdout);
		} 
		
		//This call to fclose() flushes the stream pointed to 
		//by the stream and closes the underlying file descriptor.
		//When successful, 0 is returned, program exits.
		fclose(stream);
		exit(EXIT_SUCCESS);
	}

	//If the file does not exist or fopen fails
	//print an error message
	else if(argc == 2 && (stream = fopen(argv[1],"r")) == NULL)
	{
		perror("new_cat");
		exit(EXIT_FAILURE);
	}

	//If there is no second argument
	//repate what the user types back to stdout
	else
	{
		//getchar() reads the next character from
		//stdin and returns it. The while loop
		//makes it read to the end of file until 
		//user hits CRTL+D to indicate EOF
		character = getchar();
		while(character != EOF)
		{
			//putchar() writes the character
			//and output it to stdout.
			putchar(character);
			character = getchar();
		}

		return 0;
	}
}
