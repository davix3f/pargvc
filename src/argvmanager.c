#include "argvmanager.h"

void argvmanager_init(int number_of_args)
{
	arg_count = number_of_args;
	args_list = NULL;
	args_list = calloc(number_of_args, sizeof(cl_argument));
}


int add_argument(const char* flag, const char* extended, void (*function_to_point()))
{
	printf("%i\n", arg_count);
	printf("Created command %s [extended version: %s] for function %x\n", flag, extended, function_to_point);
	
	cl_argument newarg = {flag, extended, function_to_point};

	append_to_args(newarg);

	return 0;
}


int remove_argument(const char* flag)
{
	printf("Argument %s removed\n", flag);

	return 0;
}


int append_to_args(cl_argument argument)
{
    int index=0;
	for(int x=0; x<arg_count; x++)
	{
		if(args_list[x].flag==NULL)
    	{
    		printf("Assigned %x to args[%i](%x)\n", &argument, index, &args_list[index]);
    		args_list[x] = argument;
    		return 1;
    	}
    }
}


int check_flag(const char* flag_to_check, char** argv_c, int args_count)
{
	for(int x=0; x<args_count; x++)
	{
		if((strcmp(args_list[x].flag, flag_to_check)==0) || strcmp(args_list[x].extended, flag_to_check)==0)
		{
			printf("Flag %s exists at %i\n", flag_to_check, x);
			for(int index=0; index<	args_count; index++)
			{
				if((strcmp(flag_to_check, argv_c[index])==0) || strcmp(args_list[x].extended, argv_c[index])==0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}


void get_all_args()
{
	int index=0;
	while(args_list[index].flag!=NULL)
	{
		printf("[%i] #%i (Flag: %s, Expanded: %s, Function: %x)\n", index, index+1, args_list[index].flag, args_list[index].extended, args_list[index].function_to_call);
		index++;
	}
}

