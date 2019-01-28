# pargvc

## What is this?
`pargvc` is a small set of utilities for managing argv in a faster way. I'm coding it mainly for my use, but you can use this as well, and eventually improve it.

## What can I use pargvc for?
Adding command line arguments, and interacting with them.

pargvc supports both 'switch' arguments and value-assignable arguments, so you can
* Check the value assigned to each argument
* Check for flags called in the command

## Where is that code?
I won't merge to master very often, so check dev branch!

## How do I install pargvc?
1. Clone the repo
2. Open the **src** directory in the terminal
3. `make createlib`
✔️

## How do I use it?
Include it in your code with `#include <pargvc.h>`

In gcc, add the `-lpargvc` flag when compiling any project that uses pargvc

## May I get some documentation?
Sure. Check the wiki!
