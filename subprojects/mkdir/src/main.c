#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
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

	/* Default mode */
	mode = 0777 & ~umask(0);

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

	/* for each non-option arg */
	for(argc -= optind; argc > 0; argc--)
	{
		if((mkdir(argv[argc], mode)) == -1)
		{
			perror("mkdir(main.c)");
		}
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: mkdir [-hmpV]\n"
			"\n"
			"  -h, --help     Show help message and quit\n"
			"  -m, --mode     Set permissions for new directory\n"
			"  -p, --parent   Make parent directories if they don't exist\n"
			"  -V, --version  Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("mkdir %s (%s License)\n", VERSION, LICENSE);
	exit(EXIT_SUCCESS);
}
