#include "pargvc_backends/pargvc_backends.h"

#define VAL_REQ 0
#define VAL_OPT 1
#define VAL_NOT 2

// Call this to initialize pargvc
void pargvc_init(char** argv, int argc);

// Call this at the end of the function
void pargvc_end();

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
/*
 Call this function after declaring
 all the cli arguments
*/

int check_flag(const char* flag_to_check);
/*
 Use this function to check if an argument has been given
 e.g "if (check_flag("-a")){do_this;} "
 also supports extended flags
 e.g "if(check_flag("--extended-version")){do_that;}"
*/

void get_all_args();
//print all args

const char* get_arg_value(const char* arg_name);
// get the value of a flag