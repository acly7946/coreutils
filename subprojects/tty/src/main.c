#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	bool flag_s;
	char *tty;
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"silent", no_argument, NULL, 's'},
		{"version", no_argument, NULL, 'V'},
	};

	flag_s = false;
	tty = ttyname(0);

	while((optc = getopt_long(argc, argv, "hsV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 's':
				flag_s = true;
				break;

			case 'V':
				version();

			default:
				usage();
		}
	}

	if(!flag_s)
	{
		if(tty)
		{
			puts(tty);
		}
		else
		{
			puts("not a tty");
		}
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: tty [-hsV]\n"
			"\n"
			"  -h, --help     Show help message and quit\n"
			"  -s, --silent   Print nothing, only return exit status\n"
			"  -V, --version  Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("tty %s, acly7946 coreutils\n", VERSION);
	exit(EXIT_SUCCESS);
}
