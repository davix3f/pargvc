#include "pargvc_backends.h"

int append_to_oargs(optional_cl_argument argument)
{
	/*
	This will ACTUALLY append the optional
	argument defined with 'add_optional_argument'
	to optional_args_list
	*/
	for(int optional_index=0;
		optional_index < optional_args_count;
		optional_index++)
	{
		if(optional_args_list[optional_index].flag==NULL)
    	{
    		optional_args_list[optional_index] = argument;
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
	for(int mandatory_index=0;
		mandatory_index < mandatory_args_count;
		mandatory_index++)
	{
		if(mandatory_args_list[mandatory_index].flag==NULL)
    	{
    		mandatory_args_list[mandatory_index] = argument;
    		return 1;
    	}
    }
    return 0;
}


int append_input_value(const char* flag, const char* ext_flag, const char* input_val, int is_accepted_val)
{
	//This will assign <input_val> to the argument <flag>, if it requires one
	//printf("flag:%s value:%s\n", flag, input_val);
	for(int argc_index=0; argc_index<argc_copy; argc_index++)
	{
		if(input_args[argc_index].name==NULL)
    	{
			argv_value arg = {flag, ext_flag, input_val, is_accepted_val};
    		input_args[argc_index] = arg;
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
	for(int mandatory_index=0;
		mandatory_index < mandatory_args_count;
		mandatory_index++)
	{
		for(int argc_index=0;
		 	argc_index < argc_copy;
			argc_index++)
		{
			if((input_args[argc_index].name==mandatory_args_list[mandatory_index].flag)==1)
			{
				found = 1;
				break;
			} else { found = 0; break; }
		}
		if(found == 0)
		{
			//printf("\nAdding val[%s] to marg[%s]\n", input_val, mandatory_args_list[mandatory_index].flag);
			// ^ logging
			append_input_value(mandatory_args_list[mandatory_index].flag, "/", input_val, 1);
			return 0;
		}

	} return 1;
}
