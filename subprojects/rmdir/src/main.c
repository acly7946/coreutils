#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"ignore-fail-on-non-empty", no_argument, NULL, 'i'},
		{"parents", no_argument, NULL, 'p'},
		{"verbose", no_argument, NULL, 'v'},
		{"version", no_argument, NULL, 'V'},
	};

	while((optc = getopt_long(argc, argv, "hpvV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'i':
				break;

			case 'p':
				break;

			case 'v':
				break;

			case 'V':
				version();

			default:
				usage();
		}
	}

	if(optind == argc)
	{
		fprintf(stderr, "rmdir(main.c): must specify directory to remove\n");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: rmdir [-hpvV] <DIRECTORY> [DIRECTORY2] ...\n"
			"\n"
			"  -h, --help                      Show help message and quit\n"
			"      --ignore-fail-on-non-empty  Do not fail on non-empty directories\n"
			"  -p, --parents                   Remove parent directories\n"
			"  -v, --verbose                   Verbose output\n"
			"  -V, --version                   Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("rmdir %s, acly7946 coreutils\n", VERSION);
	exit(EXIT_SUCCESS);
}
