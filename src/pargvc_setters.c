#include "pargvc.h"

void ignore_wrong_flag()
{ wflag_ignore_state = 1; }

void set_wrong_flag_msg(char* wflag_msg)
{ assign_help_string(wflag_msg, wrong_flag_msg_p); }

void set_description(char* description_arg)
{ assign_help_string(description_arg, help_description_p); }

void set_author(char* author_arg)
{ assign_help_string(author_arg, help_author_p); }

void set_website(char* usage_arg)
{ assign_help_string(usage_arg, help_website_p); }

void set_license(char* license_arg)
{ assign_help_string(license_arg, help_license_p); }

void set_usage(char* usage_arg)
{ assign_help_string(usage_arg, help_usage_p); }
