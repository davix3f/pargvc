#include "argvmanager.h"


int add_argument(const char* flag, const char* extended, void (*function_to_point()))
{
	printf("Created command %s [extended version: %s] for function %x\n", flag, extended, function_to_point);
	
	cl_argument newarg={flag, extended, function_to_point};

	return 0;
}

int remove_argument(const char* flag)
{
	printf("Argument %s removed\n", flag);

	return 0;
}
