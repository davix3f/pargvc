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

	wflag_ignore_state = 0;

	wrong_flag_msg = NULL;
	wrong_flag_msg_p = &wrong_flag_msg;

	help_description = NULL;
	help_description_p = &help_description;

	help_author = NULL;
	help_author_p = &help_author;

	help_website = NULL;
	help_website_p = &help_website;

	help_license = NULL;
	help_license_p = &help_license;

	help_usage = NULL;
	help_usage_p = &help_usage;
}

void pargvc_end()
{
	free(optional_args_list);
	free(mandatory_args_list);
	free(input_args);
	free(wrong_flag_msg);
	free(help_description);
	free(help_author);
	free(help_website);
	free(help_license);
	free(help_usage);
}
