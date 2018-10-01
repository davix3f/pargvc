# argvmanager

## What is this?
`argvmanager` is a small set of utilities for managing argv in a faster way. I'm coding it mainly for my use, but you can use this as well, and eventually improve it.

## What can argvmanager do?
* Add command line arguments
* Check the value assigned to an argument
* Check for flags

## How?
```C

#include <stdio.h>
#include "argvmanager.h"

int main(int argc, char** argv)
{
    argvmanager_init(2, 2, argc, argv);
    // this will initialize space for
    // two positional arguments and
    // two optional arguments

    add_mandatory_argument("FILE", "File to scan");
    add_mandatory_argument("MODE", "File read mode(R/W/RW)");
    // We defined two mandatory arguments, with their names
    // "FILE" and "MODE"


    add_optional_argument("-o", "--output", 1, "Set to 1 to parse output");
    add_optional_argument("-w", "--warning", 0, "Give warnings for typos";
    // We defined two optional arguments:
    // "-o" (which extended version is "--output") which accept
    // a value (has_value is 1)
    // "-w" does not accept (or better, ignores) any value
    // before it

    parse_argv();
    // This function will parse argv,
    // accordingly to the arguments
    // we defined before


    /*
    code
    code
    code
    code/*

    argvmanager_end();
    // Deallocate all the memory used
    // for arguments and argvmanager elements
}```

