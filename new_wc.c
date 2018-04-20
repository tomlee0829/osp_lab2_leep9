//Description: If [file.txt] is specified, print a count of the number 
//of words in file.txt. Implemeting the program with -l and -c 
//command line flags to show number of lines and number of characters
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

//Using structure that creates a data type 
//to group varibles into a single type
struct variable
{
	int lines; //wc -l flag
	int maxLineLength; 
	int size; //wc -c flag
}wordCount; //The variable wordCount is declared with "variable"

//Function that shows errors
void errorPrint(char str[])
{
	printf("Error:%s",str);
}
//Function isFile() is used when user  input argument with file name
void isFile(char fileName[])
{
	//Declarations
	struct stat getInfo = {};
	FILE *stream;
	char character;
	int length = 0;

	//Using function stat to read messages
	//inside fileName and writes it in getInfo
	//display file or file system status
	int information  = stat(fileName, &getInfo);
	
	//Error if message is wrong
	if(information  == -1)
	{
		//call funciton errorPrint 
		//Prints out the error message
		errorPrint(fileName);
		return;
	}

	//This call to st_size makes File word 
	//count total size equals wc -c byte counts
	wordCount.size = getInfo.st_size;

	//This call to fopen() takes the path to a file 
	//to open, followed by the access mode.
	//fopen() returns a FILE * a (pointer to a
	//stream represening the open file)
	stream = fopen(fileName, "r");

	//This call to fgetc() reads the next character
	//from stream and returns it as an unsinged char
	//cast to an int, or end of file.
	while((character = fgetc(stream)) != EOF)
	{
		//check character condition
		if(character == '\n')
		{
			//increment lines for wc -l flag
			wordCount.lines++;
			if(length > wordCount.maxLineLength)
			{
				//Update the maximum length
				wordCount.maxLineLength = length;
			}

			length = 0;
		}
	}

	//This call to fclose() flushes the stream pointed to
	//by the stram and closes the underlying file descriptor.
	fclose(stream);
}

//Function noFile() is used when there's 
//no argument enterd by user
void noFile()
{
	//Delcare
	char character;
	int length = 0;

	//This call to getchar() reads the next character from
	//stdin and returns it. The while loop 
	//makes it read to the end of file until
	//user hits CRTL+D to indicate EOF
	while((character = getchar()) != EOF)
	{
		//Increment size of character
		//for wc -c flag
		wordCount.size += sizeof(character);

		//check character condition
		if(character == '\n')
		{
			//Increment lines for wc -l flag
			wordCount.lines++;
			if(length > wordCount.maxLineLength)
			{
				//Update the maximum length
				wordCount.maxLineLength = length;
			}

			length = 0;
		}
	}
}

//Main will call the functions and do wc commands
int main(int argc, char *argv[])
{
	//Declare variable
	int number;

	//Conditions check
	//If there's no argument entered by user
	//call noFile and print default -l -c word count
	if(argc == 1)
	{
		noFile();
		printf("%d\t%d\n", wordCount.lines, wordCount.size);
		return 0;
	}
	//If there are 2 arguments
	else if(argc == 2)
	{
		if(argv[1][0] != '-')
		{
			isFile(argv[1]);
			printf("%d %d %s \n", wordCount.lines,
			       wordCount.size, argv[1]);
			return 0;
		}
		else
		{
			noFile();
		}

	}
	//If there are 3 arguments 
	//
	else if(argc == 3)
	{
		isFile(argv[2]);
	}
	//getopt() is used to break up (parse) options
	//in command lines for easy parsing by shell procedure
	while((number = getopt(argc, argv,"lc")) != -1)
	{	
		//Switch for 2 different cases
		//-l flag is used print the length of the longest line
		//or -c is used print the byte counts
		switch(number)
		{
			case 'l':
				printf("%d\t\n", wordCount.lines);
				break;
			case 'c':
				printf("%d\t\n",wordCount.size);
				break;
		}
	}

	//Check condition of using flags
	if(argc != 2 && argv[1][0] != '-')
	{
		printf("%s\n", argv[2]);
	}

	return 0;
}



