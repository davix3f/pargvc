#include "argvmanager.h"

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
		printf("\n");

		if(optional_args_count>0)
		{
			printf("\nOptional arguments:\n");
			for(int x=0; x<optional_args_count; x++)
			{
				if(optional_args_list[x].flag!=NULL)
				{
				printf(" %s, %s %s\n", optional_args_list[x].flag, optional_args_list[x].extended, optional_args_list[x].help);
				}
			}
		}
		printf("\n");
		exit(0);
	}
}
