#include "pargvc.h"

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
				printf(" %s, %s %s\n", optional_args_list[x].flag,
						       		   optional_args_list[x].extended,
						    		   optional_args_list[x].help);
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
	// check for help_flag
	if(help_flag() == 1) // if --help or -h does not exists in argv
	{
		int found = 0;
		for(int x=1; x<argc_copy; x++)
		// for each item in argv
		{
			if(argv_copy[x][0] == '-')
			// if the item starts with '-', it should be a flag
			{
				found = 0;
				//printf("Parsing %s: ", argv_copy[x]); // logging
				for(int y=0; y<optional_args_count; y++)
				// for each item in optional_args_list
				{
					if(optional_args_list[y].flag != 0)
					{
						// if that flag exists
						if(strcmp(optional_args_list[y].flag, argv_copy[x])==0||strcmp(optional_args_list[y].extended, argv_copy[x])==0)
						{
							found = 1;
							if(optional_args_list[y].value_level <= 1)
							// if it accepts a value
							{
								// but nothing after that flag is found
								if(argv_copy[x+1] == 0)
								{
									if(optional_args_list[y].value_level == 0)
									// if a value is REQUIRED
									{ printf("\'%s\' requires a value!\n", optional_args_list[y].flag); exit(1); } // error

									else if(optional_args_list[y].value_level == 1)
									// if a value is not required
									{
										append_input_value(argv_copy[x], optional_args_list[y].extended, "TRUE", 1);
									}
								}
								

								// or the item next to it is another flag
								else if(argv_copy[x+1][0]=='-')
								{
									switch (optional_args_list[y].value_level)
									{
										case 0:
											printf("Value cannot be another flag!\n"); exit(1);

										case 1:
											append_input_value(argv_copy[x], optional_args_list[y].extended, "TRUE", 1);
											break;
									}
								}
								
								// if none of the above situations
								else
								{
									//printf("has value %s\n", argv_copy[x+1]); // logging
									append_input_value(argv_copy[x], optional_args_list[y].extended, argv_copy[x+1], 0); // assign that value
									x++;
									break;
								}
							} else {printf("No value required\n"); break;} // if it does not require a value
						}
					}
				}
				// if that flag has not been found
				if(found==0){ printf("\'%s\' not existing!\n", argv_copy[x]); exit(1); } 
			}
			else
			{
				if(mandatory_args_count != 0)
				{
					append_mandatory_value(argv_copy[x]);
				    /*
				    if the argv item is not a flag, it is added to
				    the first not-assigned positional argument.
				    */
				} else { printf("Value \'%s\' ignored\n", argv_copy[x]); }
			}
		}
	}

	for(int indx=0; indx<mandatory_args_count; indx++)
	/*
	parse mandatory_args_list and input_args
	so if any is missing, an error is returned
	*/
	{
		if(strcmp(get_arg_value(mandatory_args_list[indx].flag), "NO_VAL")==0 && mandatory_args_list[indx].value_level <= 1)
		{
			printf("Mandatory value for '%s' missing!\n", mandatory_args_list[indx].flag);
			exit(1);
		}
	}

}
