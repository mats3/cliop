#include<stdio.h>
#include"cliop/cliop.h"

void arguments_print(char **arg, uint arg_count)
{
	void *end;
	for (end = &arg[arg_count]; arg != end; arg++)
	{
		printf("Argument: %s\n", *arg);
	}
}

void list_all(char **arg, uint arg_count)
{
	arguments_print(arg, arg_count);
	printf("func: list\n");
}

void append(char **arg, uint arg_count)
{
	arguments_print(arg, arg_count);
	printf("func: apend\n");
}

int main(int argc, char **argv)
{
    cliop_option_append('h', "show helpsite", HELPSITE_FUNCTION);
	cliop_option_append('l', "list all things", &list_all);
	cliop_option_append('a', "append things", &append);

	cliop_option_exec(argc, argv);

	return 0;
}
