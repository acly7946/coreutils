#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int i;
	int optc;
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'V'},
	};

	while((optc = getopt_long(argc, argv, "hV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'V':
				version();

			default:
				usage();
		}
	}

	if(argc > 1)
	{
		while(true)
		{
			for(i = 1; i < argc; i++)
			{
				printf("%s ", argv[i]);
			}
			putchar('\n');
		}
	}
	else
	{
		while(true)
		{
			puts("y");
		}
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: yes [STRING] [-hV]\n"
			"\n"
			"  -h, --help     Show help message and quit\n"
			"  -V, --version  Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("yes %s, acly7946 coreutils\n", VERSION);
	exit(EXIT_SUCCESS);
}
