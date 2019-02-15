#include "pargvc.h"

void pargvc_init(char** argv, int argc)
{
	optional_args_count = 0;
	mandatory_args_count = 0;
	optional_args_list = NULL;
	mandatory_args_list = NULL;

	optional_args_list = (optional_cl_argument * )calloc(optional_args_count, sizeof(optional_cl_argument));
	mandatory_args_list = (mandatory_cl_argument * )calloc(mandatory_args_count, sizeof(mandatory_cl_argument));

	argv_copy = argv;
	argc_copy = argc;

	input_args = (argv_value * )calloc(argc_copy, sizeof(argv_value));
}

void pargvc_end()
{
	free(optional_args_list);
	free(mandatory_args_list);
	free(input_args);
}
