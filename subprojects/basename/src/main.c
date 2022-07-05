#include <getopt.h>
#include <libgen.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_suffix(char *str, const char *suffix);
static void usage(void) __attribute__((noreturn));
static void version(void) __attribute__((noreturn));

int main(int argc, char *argv[])
{
	int optc;
	bool flag_a = false;
	bool flag_s = false;
	bool flag_z = false;
	static struct option long_options[] =
	{
		{"multiple", no_argument, NULL, 'a'},
		{"suffix", no_argument, NULL, 's'},
		{"zero", no_argument, NULL, 'z'},
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'V'},
	};

	while((optc = getopt_long(argc, argv, "ashVz", long_options, NULL)) != EOF)
	{
		switch(optc)
		{
			case 'a':
				flag_a = true;
				break;

			case 's':
				flag_s = true;
				break;

			case 'z':
				flag_z = true;
				break;

			case 'V':
				version();

			default:
				usage();
		}
	}

	do
	{
		printf("%s%c",
				basename(argv[optind]),
				flag_z ? 0 : '\n');
		optind++;
	}	while((flag_a) && (optind < argc));

	return EXIT_SUCCESS;
}

char *remove_suffix(char *str, const char *suffix)
{
	size_t len = strlen(str);
	size_t suffix_len = strlen(suffix);
	if(len < suffix_len)
	{
		return str;
	}
	if(strcmp(str + len - suffix_len, suffix) == 0)
	{
		str[len - suffix_len] = '\0';
	}
	return str;
}

static void usage(void)
{
	fprintf(stderr,
			"Usage: basename [-ashVz] <PATH1> [PATH2]...\n"
			"\n"
			"  -a, --multiple  Support multiple arguments\n"
			"  -s, --suffix    Remove trailing suffix\n"
			"  -h, --help      Show help message and quit\n"
			"  -V, --version   Show version number and quit\n"
			"  -z, --zero      Do not print newline after each result\n");
	exit(EXIT_FAILURE);
}

static void version(void)
{
	printf("basename %s, acly7946 coreutils\n", VERSION);
	exit(EXIT_SUCCESS);
}
