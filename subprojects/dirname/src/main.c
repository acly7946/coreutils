#include <getopt.h>
#include <libgen.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	bool flag_z = false;
	static struct option long_options[] =
	{
		{"zero", no_argument, NULL, 'z'},
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'V'},
	};

	while((optc = getopt_long(argc, argv, "hVz", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'z':
				flag_z = true;
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

	for(; optind < argc; optind++)
	{
		printf("%s%c", dirname(argv[optind]), flag_z ? 0 : '\n');
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: dirname [-hVz] <PATH1> [PATH2]...\n"
			"\n"
			"  -h, --help     Show help message and quit\n"
			"  -V, --version  Show version number and quit\n"
			"  -z, --zero     Do not print newline after each result\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("dirname %s, acly7946 coreutils\n", VERSION);
	exit(EXIT_SUCCESS);
}
