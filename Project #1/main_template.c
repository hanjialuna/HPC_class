/*
	Put your comments about this file here
*/

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
   if (argc != 2) {
      printf("Incorrect usage: only enter the input data file name\n");
      return 0;
   }
   FILE* inputfile = fopen(argv[1], "r");
   if (!inputfile) {
      printf("Unable to open input file\n");
      return 0;
   }
   // start reading input data using function fscanf here
   int N;
   fscanf(inputfile, "%d", &N); // read an integer N for example
   // read rest of parameters here
   fclose(inputfile);

   clock_t start = clock();
   
   // ... rest of program ...

   printf("Time elapsed: %g seconds\n", (float)(clock()-start)/CLOCKS_PER_SEC);
   return 0;
}
