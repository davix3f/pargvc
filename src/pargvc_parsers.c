#include "pargvc.h"

void parse_argv()
{
	// check for help_flag
	if(help_flag() == 1) // if --help or -h does not exists in argv
	{
		int found = 0;
		for(int argc_index=1;
			argc_index < argc_copy;
			argc_index++)
		// for each item in argv
		{
			if(argv_copy[argc_index][0] == '-')
			// if the item starts with '-', it should be a flag
			{
				found = 0;
				//printf("Parsing %s: ", argv_copy[argc_index]); //logging
				for(int optional_index=0;
					optional_index < optional_args_count;
					optional_index++)
				// for each item in optional_args_list
				{
					if(optional_args_list[optional_index].flag != 0)
					{
						// if that flag exists
						if(strcmp(optional_args_list[optional_index].flag, argv_copy[argc_index])==0
						   ||strcmp(optional_args_list[optional_index].extended, argv_copy[argc_index])==0)
						{
							found = 1;
							if(optional_args_list[optional_index].value_level <= 1)
							// if it accepts a value
							{
								// but nothing after that flag is found
								if(argv_copy[argc_index+1] == 0)
								{
									if(optional_args_list[optional_index].value_level == 0)
									// if a value is REQUIRED
									{
										printf("\'%s\'/\'%s\' requires a value!\n",
											   optional_args_list[optional_index].flag,
											   optional_args_list[optional_index].extended);
										exit(1);
									} // error

									else if(optional_args_list[optional_index].value_level == 1)
									// if a value is not required
									{
										append_input_value(argv_copy[argc_index],
														   optional_args_list[optional_index].extended,
														   "TRUE", 1);
									}
								}

								// or the item next to it is another flag
								else if(argv_copy[argc_index+1][0]=='-')
								{
									switch (optional_args_list[optional_index].value_level)
									{
										case 0:
											printf("Value cannot be another flag!\n"); exit(1);

										case 1:
											append_input_value(argv_copy[argc_index],
															   optional_args_list[optional_index].extended,
															   "TRUE", 1);
										case 2:
											append_input_value(argv_copy[argc_index],
														   	   optional_args_list[optional_index].extended,
														       "TRUE", 0);
											break;
									}
								}

								// if none of the above situations
								else
								{
									//printf("has value %s\n", argv_copy[argc_index+1]); // logging
									append_input_value(argv_copy[argc_index],
													   optional_args_list[optional_index].extended,
													   argv_copy[argc_index+1], 0); // assign that value
									argc_index++;
									break;
								}
							}
							else
							{
								// if it does not require a value
								//printf("No value required\n"); //logging
								break;
							}
						}
					}
				}
				// if that flag has not been found
				if(found==0)
				{
					if(!ignore_state)
					{
						if(wrong_flag_msg == NULL)
						{
							printf("\'%s\' not defined. Aborting.\n", argv_copy[argc_index]);
						} else { printf("%s\n", wrong_flag_msg); }
						exit(1);
					}
				}
			}
			else
			{
				if(mandatory_args_count != 0)
				{
					append_mandatory_value(argv_copy[argc_index]);
				    /*
				    if the argv item is not a flag, it is added to
				    the first not-assigned positional argument.
				    */
				} else { printf("Value \'%s\' ignored\n", argv_copy[argc_index]); }
			}
		}
	}

	for(int mandatory_index=0;
		mandatory_index < mandatory_args_count;
		mandatory_index++)
	/*
	parse mandatory_args_list and input_args
	so if any is missing, an error is returned
	*/
	{
		if(strcmp(get_arg_value(mandatory_args_list[mandatory_index].flag), "NO_VAL")==0)
		{
			printf("Mandatory value for '%s' missing!\n", mandatory_args_list[mandatory_index].flag);
			exit(1);
		}
	}

}
