/*
  datatypes

  This program prints all the information about many commonly used numerical data types
  used in C programming.  There are five columns printed, given by
  Type name, memory size, description, relevant macros for limits, and range of values

  Inputs: none

  Outputs: printed table of information

  Version history:
  3/29/16: initial draft
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <complex.h>

int main(int argc, char* argv[])
{
  printf("\n%25s %8s %35s %25s     %s\n",
	 "Type name", "Size", "Description", "Macros", "Range");
  int i;
  for (i=0; i<145; ++i)
    printf("-");
  printf("\n");

  printf("%25s %2lu bytes %35s %25s %4s[%d, %d]\n",
	 "char", sizeof(char), "Single character", 
	 "[CHAR_MIN, CHAR_MAX]", "", CHAR_MIN, CHAR_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%d, %d]\n",
	 "bool", sizeof(_Bool), "Boolean", 
	 "", "", 0, 1);
  printf("%25s %2lu bytes %35s %25s %4s[%d, %d]\n",
	 "int", sizeof(int), "Integer", 
	 "[INT_MIN, INT_MAX]", "", INT_MIN, INT_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%e, %e]\n",
	 "float", sizeof(float), "Single precision floating point", 
	 "[FLT_MIN, FLT_MAX]", "+/-", FLT_MIN, FLT_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%e, %e]\n",
	 "double", sizeof(double), "Double precision floating point", 
	 "[DBL_MIN, DBL_MAX]", "+/-", DBL_MIN, DBL_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%e, %e]\n",
	 "float complex", sizeof(float complex), "Single precision complex", 
	 "I", "+/-", FLT_MIN, FLT_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%e, %e]\n",
	 "double complex", sizeof(double complex), "Double precision complex", 
	 "I", "+/-", DBL_MIN, DBL_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%d, %d]\n",
	 "short int", sizeof(short int), "Short integer", 
	 "[SHRT_MIN, SHRT_MAX]", "", SHRT_MIN, SHRT_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%ld, %ld]\n",
	 "long int", sizeof(long int), "long integer", 
	 "[LONG_MIN, LONG_MAX]", "", LONG_MIN, LONG_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%lld, %lld]\n",
	 "long long int", sizeof(long long int), "long long integer", 
	 "[LLONG_MIN, LLONG_MAX]", "", LLONG_MIN, LLONG_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%Le, %Le]\n",
	 "long double", sizeof(long double), "Quadruple precision floating point", 
	 "[LDBL_MIN, LDBL_MAX]", "+/-", LDBL_MIN, LDBL_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%Le, %Le]\n",
	 "long double complex", sizeof(long double complex), "Quadruple precision complex", 
	 "I", "+/-", LDBL_MIN, LDBL_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%u, %u]\n",
	 "unsigned char", sizeof(unsigned char), "Single character >= 0", 
	 "[0, UCHAR_MAX]", "", 0, UCHAR_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%u, %u]\n",
	 "unsigned int", sizeof(unsigned int), "Single integer >= 0", 
	 "[0, UINT_MAX]", "", 0, UINT_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%u, %u]\n",
	 "unsigned short int", sizeof(unsigned short int), "Single short integer >= 0", 
	 "[0, USHRT_MAX]", "", 0, USHRT_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%u, %lu]\n",
	 "unsigned long int", sizeof(unsigned long int), "Long integer >= 0", 
	 "[0, ULONG_MAX]", "", 0, ULONG_MAX);
  printf("%25s %2lu bytes %35s %25s %4s[%u, %Lu]\n",
	 "unsigned long long int", sizeof(unsigned long long int), "Extra long integer >= 0", 
	 "[0, ULLONG_MAX]", "", 0, ULLONG_MAX);
  for (i=0; i<145; ++i)
    printf("-");
  printf("\n\n");

  printf("%12s %12s %s\n", "Type name", "Macro name", "Value");
  for (i=0; i<40; ++i)
    printf("-");
  printf("\n");
  
  printf("%12s %12s %e\n", "float", "FLT_EPSILON", FLT_EPSILON);
  printf("%12s %12s %le\n", "double", "DBL_EPSILON", DBL_EPSILON);
  printf("%12s %12s %Le\n", "long double", "LDBL_EPSILON", LDBL_EPSILON);

  for (i=0; i<40; ++i)
    printf("-");
  printf("\n\n");

  return 0;
}
