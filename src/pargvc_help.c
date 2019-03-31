#include "pargvc.h"

int help_flag()
{
	if( (argc_copy==2) && ((strcmp("-h", argv_copy[1])==0
	   || (strcmp("--help", argv_copy[1])==0))) )
	{
		if(help_usage == NULL)
		{
	        printf("Usage: %s", argv_copy[0]);

	        for(int mandatory_index=0;
	            mandatory_index < mandatory_args_count;
	            mandatory_index++)
	        {
	            if(mandatory_args_list[mandatory_index].flag!=NULL)
	            {
	                printf(" <%s> ", mandatory_args_list[mandatory_index].flag);
	            }
	        } printf("\n");
		} else { printf("%s\n", help_usage); }

		//printf("%s\n", optional_args_count>0 ? "[OPTIONAL ARGS]" : "");

		if(optional_args_count > 0)
		{
			printf("\n[OPTIONAL ARGUMENTS]:\n");
			for(int optional_index=0;
				optional_index < optional_args_count;
				optional_index++)
			{
				if(optional_args_list[optional_index].flag!=NULL)
				{
					printf(" %s, %s %s\n",
							optional_args_list[optional_index].flag,
							optional_args_list[optional_index].extended,
							optional_args_list[optional_index].help);
				}
			}
			printf("\n");
		}

        if(help_description != NULL)
    	{ printf("\n%s\n", help_description); }

	   	if(help_author != NULL)
   		{ printf("Author: %s\n", help_author); }

		if(help_website != NULL)
		{ printf("Website: %s\n", help_website);}

		if(help_license != NULL)
		{ printf("License: %s\n", help_license);}

		exit(0);
	}
	//if --help hasn't been called
	return 1;
}
