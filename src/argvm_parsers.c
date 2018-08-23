#include "argvmanager.h"

int help_flag()
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

	return 1;
}


void parse_argv()
{
	if(help_flag() == 1)
	{
		_Bool found = 0;
		for(int x=1; x<argc_copy; x++)
		{
			if(argv_copy[x][0] == '-')
			{
				found = 0;
				printf("Parsing %s: ", argv_copy[x]);
				for(int y=0; y<optional_args_count; y++)
				{
					//printf("Arg %i flag %s\n", y, optional_args_list[y].flag);
					if(optional_args_list[y].flag != 0)
					{
						if(strcmp(optional_args_list[y].flag, argv_copy[x])==0||strcmp(optional_args_list[y].extended, argv_copy[x])==0)
						{
							found = 1;
							if(optional_args_list[y].has_value == 1)
							{
								if(argv_copy[x+1]==0){ printf("Requires a value!\n"); return; }
								else if(argv_copy[x+1][0]=='-'){ printf("Value cannot be another flag!\n"); return; }
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
				} if(found==0){ printf("not existing!\n"); return; }
			} else { printf("Adding %s as argument for something\n", argv_copy[x]);
				add_mandatory_value(argv_copy[x]);}
		} 

		/*for(int f=0; f<argc_copy; f++)
		{
			if(input_args[f].name != 0)
			{
				printf("Flag %s: %s\n", input_args[f].name, input_args[f].value);
				f++;
			}
		}*/
	}
}