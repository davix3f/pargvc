#include "argvmanager.h"

void argvmanager_init(int number_of_mandatory_args, int number_of_optional_args, char** argv, int argc)
{
	optional_args_count = number_of_optional_args;
	mandatory_args_count = number_of_mandatory_args;
	optional_args_list = NULL;
	mandatory_args_list = NULL;

	optional_args_list = calloc(number_of_optional_args, sizeof(optional_cl_argument));
	mandatory_args_list = calloc(number_of_mandatory_args, sizeof(mandatory_cl_argument));

	argv_copy = argv;
	argc_copy = argc;
}


int add_optional_argument(const char* flag, const char* extended, const char* help)
{
	//printf("Created optional argument \'%s\' [extended version: \'%s\']\n", flag, extended);
	
	optional_cl_argument new_optional_arg = {flag, extended, help};

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
    		//printf("Assigned optional %x to optional_args_list[%i](%x)\n", &argument, index, &optional_args_list[x]);
    		optional_args_list[x] = argument;
    		return 1;
    	}
    }
}

int append_to_margs(mandatory_cl_argument argument)
{
	for(int x=0; x<mandatory_args_count; x++)
	{
		if(mandatory_args_list[x].flag==NULL)
    	{
    		//printf("Assigned mandatory %x to mandatory_args_list[%i](%x)\n", &argument, index, &mandatory_args_list[x]);
    		mandatory_args_list[x] = argument;
    		return 1;
    	}
    }
}


int check_flag(const char* flag_to_check)
{
	for(int x=0; x<argc_copy; x++)
	{
		if((strcmp(optional_args_list[x].flag, flag_to_check)==0) || strcmp(optional_args_list[x].extended, flag_to_check)==0)
		{ //check if the flag to be searched exists in the flags array
		  //if it exists
			for(int index=0; index<argc_copy; index++)
			{ // argv is parsed to look for it
				if((strcmp(flag_to_check, argv_copy[index])==0) || strcmp(optional_args_list[x].extended, argv_copy[index])==0)
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
	for(int index=0; index<optional_args_count; index++)
	{
		if(optional_args_list[index].flag!=NULL)
		{
			printf("[%i] #%i (Flag: %s, Expanded: %s)\n", index, index+1, optional_args_list[index].flag, optional_args_list[index].extended);
		}
	}
}


void help_flag()
{
	if((argc_copy==2) && ((strcmp("-h", argv_copy[1])==0 || (strcmp("--help", argv_copy[1])==0))))
	{
		printf("Usage: %s ", argv_copy[0]);

		for(int x=0; x<mandatory_args_count; x++)
		{
			if(mandatory_args_list[x].flag!=NULL)
			{
				printf(" <%s> ", mandatory_args_list[x].flag);
			}
		}


		printf("\nOptional arguments:\n");
		for(int x=0; x<optional_args_count; x++)
		{
			if(optional_args_list[x].flag!=NULL)
			{
			printf(" %s, %s <value>   %s\n", optional_args_list[x].flag, optional_args_list[x].extended, optional_args_list[x].help);
			}
		}
		printf("\n");
	}
}
