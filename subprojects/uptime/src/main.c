#include "uptime.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	struct sysinfo sys;
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"pretty", no_argument, NULL, 'p'},
		{"since", no_argument, NULL, 's'},
		{"version", no_argument, NULL, 'V'},
	};

	if(sysinfo(&sys) != 0)
	{
		perror("Can't get sysinfo");
		exit(EXIT_FAILURE);
	}

	if(argc == 1)
	{
		uptime_print(sys);
		exit(EXIT_SUCCESS);
	}

	while((optc = getopt_long(argc, argv, "hpsV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'p':
				uptime_pretty(sys.uptime);
				exit(EXIT_SUCCESS);

			case 's':
				uptime_since(sys.uptime);
				exit(EXIT_SUCCESS);

			case 'V':
				version();

			default:
				usage();
		}
	}

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: uptime [-hpsV]\n"
			"\n"
			"  -p, --pretty   Print in a human-readable format\n"
			"  -h, --help     Show help message and quit\n"
			"  -s, --since    Print time uptime is calculated from\n"
			"  -V, --version  Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("uptime %s (%s License)\n", VERSION, LICENSE);
	exit(EXIT_SUCCESS);
}
