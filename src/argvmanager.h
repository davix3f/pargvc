#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct o_clarg
{
	const char* flag;
	const char* extended;
	const char* help;
} optional_cl_argument;

typedef struct m_clarg
{
	const char* flag;
	const char* help;
} mandatory_cl_argument;

static optional_cl_argument *optional_args_list;
static mandatory_cl_argument *mandatory_args_list;
static char **argv_copy;
static int argc_copy;
static int optional_args_count;
static int mandatory_args_count;

//Launch this with argc as argument before anything else
void argvmanager_init(int number_of_mandatory_args, int number_of_optional_args, char** argv, int argc);

int add_optional_argument(const char* flag, const char* extended, const char* help);
int add_mandatory_argument(const char* flag, const char* help);

int append_to_oargs(optional_cl_argument argument); // not for user
int append_to_margs(mandatory_cl_argument argument); //not for user

/* Use that in your program to check if an argument has been given
e.g "if (check_flag("-a", argv, argc)){do_this;} "
also supports extended flags
e.g "if(check_flag("--extended-version", argv, argc)){do_that;}"
*/
int check_flag(const char* flag_to_check);

//print all args
void get_all_args();

void help_flag(); // execute this function at the end of the arguments declaration or of the whole script
/*
add_mandatory_argument(this this)
add_optional_argument(this this this)
add_optional_argument(that those these)
help_flag()*/
