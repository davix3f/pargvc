#include <stdio.h>
#include "argvmanager.h"

int add(int a, int b)
{return(a+b);}

int main(int argc, char** argv)
{
	add_argument("-a", "--memes-down", &add);

	return 0;
}
