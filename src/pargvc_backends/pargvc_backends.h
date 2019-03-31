#include "pargvc_types.h"
#include <string.h>
#include <stdlib.h>

optional_cl_argument *optional_args_list;
mandatory_cl_argument *mandatory_args_list;
argv_value *input_args;
char **argv_copy;
int argc_copy;
int optional_args_count;
int mandatory_args_count;

int wflag_ignore_state;

char* wrong_flag_msg;
char** wrong_flag_msg_p;

char* help_description;
char** help_description_p;

char* help_author;
char** help_author_p;

char* help_website;
char** help_website_p;

char* help_license;
char** help_license_p;

char* help_usage;
char** help_usage_p;

// Backends
// NOT FOR USER
// These functions shouldn't be called by the user.

int append_mandatory_value(const char* input_val); // not for user
int append_input_value(const char* flag, const char* ext_flag, const char* input_val, int is_accepted); // not for user
int append_to_oargs(optional_cl_argument argument); // not for user
int append_to_margs(mandatory_cl_argument argument); //not for user
int help_flag();

int str_empty(const char* target_string);
int assign_help_string(char* source, char** destination);
