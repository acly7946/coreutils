#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	struct utsname u;
	static struct option long_options[] =
	{
		{"all", no_argument, NULL, 'a'},
		{"help", no_argument, NULL, 'h'},
		{"machine", no_argument, NULL, 'm'},
		{"nodename", no_argument, NULL, 'n'},
		{"kernel-release", no_argument, NULL, 'r'},
		{"kernel-name", no_argument, NULL, 's'},
		{"kernel-version", no_argument, NULL, 'v'},
		{"version", no_argument, NULL, 'V'},
	};

	if(uname(&u) == -1)
	{
		perror("uname");
		exit(EXIT_FAILURE);
	}

	if(argc == 1) /* -s when no args */
	{
		puts(u.sysname);
		exit(EXIT_SUCCESS);
	}

	while((optc = getopt_long(argc, argv, "ahmnrsvV", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'a':
				printf("%s %s %s %s %s\n",
						u.sysname,
						u.nodename,
						u.release,
						u.version,
						u.machine
				);
				exit(EXIT_SUCCESS);

			case 'm':
				fputs(u.machine, stdout);
				u.machine[0] = '\0';
				break;

			case 'n':
				fputs(u.nodename, stdout);
				u.nodename[0] = '\0';
				break;

			case 'r':
				fputs(u.release, stdout);
				u.release[0] = '\0';
				break;

			case 's':
				fputs(u.sysname, stdout);
				u.sysname[0] = '\0';
				break;

			case 'v':
				fputs(u.version, stdout);
				u.version[0] = '\0';
				break;

			case 'V':
				version();

			default:
				usage();
		}
		if(optind < argc) /* Multiple options specified */
		{
			putchar(' ');
		}
	}
	putchar('\n');

	return EXIT_SUCCESS;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: uname [-ahmnrsvV]\n"
			"\n"
			"  -a, --all             Print all information\n"
			"  -m, --machine         Print machine name\n"
			"  -n, --nodename        Print node name\n"
			"  -r, --kernel-release  Print kernel release\n"
			"  -s, --kernel-name     Print kernel name\n"
			"  -v, --kernel-version  Print kernel version\n"
			"  -h, --help            Show help message and quit\n"
			"  -V, --version         Show version number and quit\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("uname %s (%s License)\n", VERSION, LICENSE);
	exit(EXIT_SUCCESS);
}
