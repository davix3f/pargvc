#include "argvmanager.h"

int add_optional_argument(const char* flag, const char* extended, _Bool has_value, const char* help)
{
	//printf("Created optional argument \'%s\' [extended version: \'%s\']\n", flag, extended);

	optional_cl_argument new_optional_arg = {flag, extended, has_value, help};

	append_to_oargs(new_optional_arg);

	return 0;
}

int add_mandatory_argument(const char* flag, const char* help)
{
	if(strncmp(flag, "-", 1)==0)
	{
		printf("Mandatory arguments should not be named with \'--\'or \'-\' at the beginning\n");
	}
	//printf("Created mandatory argument \'%s\'\n", flag);
	mandatory_cl_argument new_mandatory = {flag, help};
	append_to_margs(new_mandatory);
	return 1;
}


int append_to_oargs(optional_cl_argument argument)
{
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

int add_input_value(const char* flag, const char* input_val)
{
	for(int x=0; x<argc_copy; x++)
	{
		if(input_args[x].name==NULL)
    	{
			argv_value arg = {flag, input_val};
    		input_args[x] = arg;
			//printf("added %s with val %s\n", arg.name, arg.value);
    		return 1;
    	}
    }
	return 0;
}

int add_mandatory_value(const char* input_val)
{
	int found = 0;
	for(int x=0; x<mandatory_args_count; x++)
	{
		for(int y=0; y<argc_copy; y++)
		{
			if((input_args[y].name==mandatory_args_list[x].flag)==1)
			{
				found = 1;
				break;
			}
		}
		if(found == 0)
		{
			//printf("\nAdding val[%s] to marg[%s]\n", input_val, mandatory_args_list[x].flag);
			add_input_value(mandatory_args_list[x].flag, input_val);
			return 0;
		}

	} return 1;
}
