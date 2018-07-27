#include <stdio.h>

typedef struct clarg
{
	char* flag;
	char* extended;
	void (*function_to_call)(char* function_argument);
} cl_argument;

cl_argument* arglist[];

int add_argument(const char* flag, const char* extended, void (*function_to_point()));

int remove_argument(const char* flag);

