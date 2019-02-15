#include <stdio.h>

typedef struct o_clarg
{
	const char* flag;
	const char* extended;
	int  value_level;
	const char* help;
} optional_cl_argument;

typedef struct m_clarg
{
	const char* flag;
	const char* help;
} mandatory_cl_argument;

typedef struct i_arg
{
	const char* name;
	const char* ext_flag;
	const char* value;
	int is_accepted;
} argv_value;
