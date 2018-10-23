#include "pargvc.h"

void get_all_args()
{
	printf("Mandatory arguments: ");
	if(mandatory_args_count==0)
		{  printf("None\n");  }
	else
	{
		printf("\n");
		for(int index=0; index<mandatory_args_count; index++)
		{
			if(mandatory_args_list[index].flag!=NULL)
			{
				printf("[%i] #%i (Flag: %s)\n", index, index+1, mandatory_args_list[index].flag);
			}
		}
	}

	printf("Optional arguments:\n");
	if(optional_args_count==0)
		{  printf("None\n");  }
	else
	{
		for(int index=0; index<optional_args_count; index++)
		{
			if(optional_args_list[index].flag!=NULL)
			{
				printf("[%i] #%i (Flag: %s, Expanded: %s)\n", index, index+1, optional_args_list[index].flag, optional_args_list[index].extended);
			}
		}
	}
}


const char* get_arg_value(const char* arg_name)
{
	for(int x=0; x<argc_copy; x++)
	{
		if(input_args[x].name == NULL){ break; }

		if(strcmp(input_args[x].name, arg_name)==0)
		{
			return(input_args[x].value);
		}
	}
	return("NO_VAL");
}

int check_flag(const char* flag_to_check)
{
	for(int x=0; x<optional_args_count-1; x++)
	{
		if(strcmp(optional_args_list[x].flag, flag_to_check)==0 || strcmp(optional_args_list[x].extended, flag_to_check)==0)
		{ //check if the flag to be searched exists in the flags array
		  //if it exists
			for(int index=0; index<argc_copy; index++)
			{ // argv is parsed to look for it
				if(strcmp(optional_args_list[x].flag, argv_copy[index])==0 || strcmp(optional_args_list[x].extended, argv_copy[index])==0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
