#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAL_REQ 0
#define VAL_OPT 1
#define VAL_NOT 2

typedef struct o_clarg
{
	const char* flag;
	const char* extended;
	int  value_level;
	const char* help;
} optional_cl_argument;

typedef struct m_clarg
{
	const char* flag;
	const char* help;
} mandatory_cl_argument;

typedef struct i_arg
{
	const char* name;
	const char* ext_flag;
	const char* value;
	int is_accepted;
} argv_value;

optional_cl_argument *optional_args_list;
mandatory_cl_argument *mandatory_args_list;
argv_value *input_args;
char **argv_copy;
int argc_copy;
int optional_args_count;
int mandatory_args_count;

// Call this with before anything else
void pargvc_init(char** argv, int argc);

// Call this at the end of the function
void pargvc_end();


// Backends
// NOT FOR USER
// These functions shouldn't be called by the user.
int append_mandatory_value(const char* input_val); // not for user
int append_input_value(const char* flag, const char* ext_flag, const char* input_val, int is_accepted); // not for user
int append_to_oargs(optional_cl_argument argument); // not for user
int append_to_margs(mandatory_cl_argument argument); //not for user
int help_flag();



// Callables
// FOR USER
// Call those functions to interact with argv values

int add_optional_argument(const char* flag, const char* extended, int value_level, const char* help);
int add_mandatory_argument(const char* flag, const char* help);
int add_switch(const char* flag, const char* extended, const char* help);
/* value_level codes
 0 -> value required
 If the value is missing, an error will come up

 1 -> value optional
 If given, the value is stored
 If not, the value assigned to
 that argument will be "TRUE"

 2 -> value not is_accepted
 This kind of optional arguments do
 not accept values and act like switches.
 It's recommended to use "add_switch" instead
 of using this value_level
*/

void parse_argv();

/* Use that in your program to check if an argument has been given
e.g "if (check_flag("-a")){do_this;} "
also supports extended flags
e.g "if(check_flag("--extended-version")){do_that;}"
*/
int check_flag(const char* flag_to_check);

//print all args
void get_all_args();

// get the value of a flag
const char* get_arg_value(const char* arg_name);
