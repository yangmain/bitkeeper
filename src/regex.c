/* regex.c Copyright (c) 2004 BitMover, Inc. */

#include "system.h"
#include "regex/regex.h"	/* has to be second, conflicts w/ system .h's */

/*
 * This file contains routines to match file names against lists of
 * regex patterns.  
 */
int
regex_main(int ac, char **av)
{
	char	*regex = av[1];
	int	i, matched = 0;

	unless (av[1] && av[2]) {
		system("bk help -s regex");
		return (2);
	}
	if (re_comp(regex)) return (1);
	for (i = 2; av[i]; i++) {
		if (re_exec(av[i])) {
			printf("%s matches.\n", av[i]);
			matched = 1;
		}
	}
	unless (matched) printf("No match.\n");
	return (matched ? 0 : 1);
}