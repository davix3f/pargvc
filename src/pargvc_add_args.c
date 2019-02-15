#include "pargvc.h"

int add_optional_argument(const char* flag, const char* extended, int value_level, const char* help)
{
	optional_cl_argument new_optional_arg = {flag, extended, value_level, help};

	optional_args_count++;
	optional_args_list = (optional_cl_argument *) realloc(optional_args_list, sizeof(optional_cl_argument)*optional_args_count);

	append_to_oargs(new_optional_arg);

	return 0;
}

int add_switch(const char* flag, const char* extended, const char* help)
{
	add_optional_argument(flag, extended, 2, help);
	return 0;
}

int add_mandatory_argument(const char* flag, const char* help)
{
	if(strncmp(flag, "-", 1)==0)
	{
		printf("Mandatory arguments cannot not be named with \'--\'or \'-\' at the beginning\n");
		return 0;
	}
	mandatory_cl_argument new_mandatory = {flag, help};

	mandatory_args_count++;
	mandatory_args_list = (mandatory_cl_argument *) realloc(mandatory_args_list, sizeof(mandatory_cl_argument)*mandatory_args_count);

	append_to_margs(new_mandatory);

	return 1;
}