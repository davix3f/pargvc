#include <stdio.h>
#include <stdlib.h>

typedef struct clarg
{
	char* flag;
	char* extended;
	void (*function_to_call)(char* function_argument);
} cl_argument;

static cl_argument *args_list;
static int arg_count;

//Launch this with argc as argument before anything else
void argvmanager_init(int number_of_args);

int add_argument(const char* flag, const char* extended, void (*function_to_point()));

int remove_argument(const char* flag);

int append_to_args(cl_argument argument); // not for user

/* Use that in your program to check if an argument has been given
e.g "if (check_flag("-a", argv, argc)){do_this;} "
also supports extended flags
e.g "if(check_flag("--extended-version", argv, argc)){do_that;}"
*/
int check_flag(const char* flag_to_check, char** argv_c, int args_count);

//print all args
void get_all_args();

