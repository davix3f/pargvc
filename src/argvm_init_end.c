#include "argvmanager.h"

void argvmanager_init(int number_of_mandatory_args, int number_of_optional_args, char** argv, int argc)
{
	optional_args_count = number_of_optional_args;
	mandatory_args_count = number_of_mandatory_args;
	optional_args_list = NULL;
	mandatory_args_list = NULL;

	optional_args_list = (optional_cl_argument * )calloc(number_of_optional_args, sizeof(optional_cl_argument));
	mandatory_args_list = (mandatory_cl_argument * )calloc(number_of_mandatory_args, sizeof(mandatory_cl_argument));

	argv_copy = argv;
	argc_copy = argc;
}

void argvmanager_end()
{
	free(optional_args_list);
	free(mandatory_args_list);
}