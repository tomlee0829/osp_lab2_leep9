//Description: If the [file.txt] argument is passed, open the file 
//and print it to stdout. If there is no second argument, repeat what the user 
//types on stdinback to stdout(until the user hits CTRL+D to indicate EOF).
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//delcare
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t  nread;

	stream = fopen(argv[1],"r"); //Open text file for reading
	if (stream == NULL)
	{
	/*	perror("fopen");
		exit(EXIT_FAILURE);  //exit */
		fread(line, nread, 1, stdin);
		printf("%s\n", line);
		fclose(stdin);
	}

	while((nread = getline(&line, &len, stream)) != -1)
	{
		fwrite(line, nread, 1, stdout);
	} 

	//free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
