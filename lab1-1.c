#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f1, *f2; //pointers to two files	
	char buffer[10];
	size_t data;
	//read from file1 the source file 
	f1 = fopen(argv[1], "r");
	//test to see if file can be opened or not
	if(argc <2)
	{		
		printf("Not enough arguments!");
		exit(0);
	}
	if(f1 == NULL)
	{
		printf("can't open %s file \n", argv[1]);
		exit(0);
	}
	//f2 is the destination file
	f2 = fopen(argv[2], "w");
	printf("\n");
	if(f2 == NULL)
	{
		printf("can't open %s file \n", argv[2]);
		exit(0);
	}
	//now copy from one file to another
	//fread takes what we're reading from, the size of how much we're
	//reading, how many items (size of buffer) and where we're reading from
	while(0 < (data = fread(buffer,1, 10, f1)))
	{
		fwrite(buffer,1, data, f2);
	//	data = fread(f1);
	}
	printf("Contents copied to %s", argv[2]);
	printf("\n");
	fclose(f1);
	fclose(f2);
	return 0;
}
