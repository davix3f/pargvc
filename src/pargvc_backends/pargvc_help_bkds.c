#include "pargvc_backends/pargvc_backends.h"
#define get_var_name(var) #var

int str_empty(const char* target_string)
{
	if(!strcmp(target_string, ""))
	{
		return 1;
	}
	return 0;
}


int assign_help_string(char* source, char** destination)
{
	if(str_empty(source))
 	{
 		printf("Argument cannot be an empty string\n");
 		return 0;
 	}

	*destination = (char *)malloc((strlen(source)+1) * sizeof(char));
	strcpy(*destination, source);

	if(!strcmp(source, *destination))
	{ return 1; } else {
		printf("Error occurred during help_string assignment\n");
		*destination = NULL;
		return 0;
	}
}
