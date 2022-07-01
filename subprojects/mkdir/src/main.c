#include "mkpath.h"
#include <getopt.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	int rv;
	bool flag_p;
	__mode_t mode;
	struct stat st;
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"mode", no_argument, NULL, 'm'},
		{"parent", no_argument, NULL, 'p'},
		{"version", no_argument, NULL, 'V'},
	};

	flag_p = false;
	mode = 0777 & ~umask(0); /* Default mode */

	while((optc = getopt_long(argc, argv, "hmpV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'm':
				break;

			case 'p':
				flag_p = true;
				break;

			case 'V':
				version();

			default:
				usage();
		}
	}

	if(optind == argc)
	{
		fputs("mkdir(main.c): specify name of directory to create\n", stderr);
		exit(EXIT_FAILURE);
	}

	argc -= optind;
	argv += optind;

	/* for each non-option arg */
	for(; *argv != NULL; ++argv)
	{
		if(flag_p)
		{
			rv = mkpath(*argv, mode);
		}
		else
		{
			rv = mkdir(*argv, mode);
		}
		if(rv == -1)
		{
			perror("mkdir(main.c)");
		}
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: mkdir [-hmpV] <DIRECTORY1> [DIRECTORY2]...\n"
			"\n"
			"  -h, --help     Show help message and quit\n"
			"  -m, --mode     Set permissions for new directory\n"
			"  -p, --parent   Make parent directories if they don't exist\n"
			"  -V, --version  Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("mkdir %s, acly7946 coreutils\n", VERSION);
	exit(EXIT_SUCCESS);
}
