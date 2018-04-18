//Description: If [file.txt] is specified, print the last N lines of that file
//(default is 5 lines if -n is not used). Otherwise, read from stdin until the
//user hits CTRL+D, and print the last N lines typed by the user.

#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 512

int main(int argc, char *argv[])
{
	//Declarations
	FILE *stream;
	char character;
	int line = 5; //default
	int count = 0;
	int index = 0;
	char buffer[BUFFSIZE][BUFFSIZE];

	stream = fopen(argv[1], "r"); //Open text file for reading
	if(stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while(!feof(stream))
	{
		count++;
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

	fclose(stream);
	if(count < line)
	{
		line = count;
	}
	if(index != 0)
	{
		index--;
	}
	for(int i = 0; i< line; i++)
	{
		printf("%s",buffer[index++]);
		if(index >= line)
		{
			index = 0;
		}
	}
	exit(EXIT_SUCCESS);
}
