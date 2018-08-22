#include "argvmanager.h"

void parse_argv()
{
	input_args = (argv_value * )calloc(argc_copy, sizeof(argv_value));
	for(int x=1; x<argc_copy; x++)
	{
		printf("Parsing %s: ", argv_copy[x]);
		for(int y=0; y<optional_args_count; y++)
		{
			//printf("Arg %i flag %s\n", y, optional_args_list[y].flag);
			if(optional_args_list[y].flag != 0)
			{
				if(strcmp(optional_args_list[y].flag, argv_copy[x])==0||strcmp(optional_args_list[y].extended, argv_copy[x])==0)
				{
					if(optional_args_list[y].has_value == 1)
					{
						if(argv_copy[x+1]==0){printf("Requires a value!\n"); return;}
						else if(argv_copy[x+1][0]=='-'){printf("Value cannot be another flag!\n"); return;}
						else
						{
							printf("has value %s\n", argv_copy[x+1]);
							add_input_value(argv_copy[x], argv_copy[x+1]);
							x++;
							break;
						}
					} else {printf("No value required\n"); break;}
				}
			}
		}
	} printf("\nArgv ended\n");
	int f=0;
	while(input_args[f].name != 0)
	{
		printf("Flag %s: %s\n", input_args[f].name, input_args[f].value);
		f++;
	}
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


