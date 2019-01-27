#include "pargvc.h"

int add_optional_argument(const char* flag, const char* extended, int value_level, const char* help)
{
	optional_cl_argument new_optional_arg = {flag, extended, value_level, help};

	append_to_oargs(new_optional_arg);

	return 0;
}

int add_mandatory_argument(const char* flag, int value_level, const char* help)
{
	if(strncmp(flag, "-", 1)==0 && value_level > 1)
	{
		printf("Mandatory arguments cannot not be named with \'--\'or \'-\' at the beginning\n");
		return 0;
	}
	mandatory_cl_argument new_mandatory = {flag, value_level, help};
	append_to_margs(new_mandatory);
	return 1;
}



int append_to_oargs(optional_cl_argument argument)
{
	/*
	This will ACTUALLY append the optional
	argument defined with 'add_optional_argument'
	to optional_args_list
	*/
	for(int x=0; x<optional_args_count; x++)
	{
		if(optional_args_list[x].flag==NULL)
    	{
    		optional_args_list[x] = argument;
    		return 1;
    	}
    }
    return 0;
}


int append_to_margs(mandatory_cl_argument argument)
{
	/*
	This will ACTUALLY append the mandatory
	argument defined with 'add_mandatory_argument'
	to mandatory_args_list
	*/
	for(int x=0; x<mandatory_args_count; x++)
	{
		if(mandatory_args_list[x].flag==NULL)
    	{
    		mandatory_args_list[x] = argument;
    		return 1;
    	}
    }
    return 0;
}


int append_input_value(const char* flag, const char* ext_flag, const char* input_val, int is_accepted_val)
{
	//This will assign <input_val> to the argument <flag>, if it requires one
	//printf("flag:%s value:%s\n", flag, input_val);
	for(int x=0; x<argc_copy; x++)
	{
		if(input_args[x].name==NULL)
    	{
			argv_value arg = {flag, ext_flag, input_val, is_accepted_val};
    		input_args[x] = arg;
    		return 1;
    	}
    }
	return 0;
}



int append_mandatory_value(const char* input_val)
{
	/*
	This is a kind of a wrapper of append_input_value,
	made to assign values of MANDATORY arguments
	*/

	int found = 0;
	/*
	checking if the input_args value
	exists in mandatory args list
	*/
	for(int x=0; x<mandatory_args_count; x++)
	{
		for(int y=0; y<argc_copy; y++)
		{
			if((input_args[y].name==mandatory_args_list[x].flag)==1)
			{
				found = 1;
				break;
			} else { found = 0; break; }
		}
		if(found == 0)
		{
			//printf("\nAdding val[%s] to marg[%s]\n", input_val, mandatory_args_list[x].flag);
			// ^ logging
			append_input_value(mandatory_args_list[x].flag, "/", input_val, 1);
			return 0;
		}

	} return 1;
}
