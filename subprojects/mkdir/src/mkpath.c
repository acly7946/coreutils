#include "mkpath.h"
#include <err.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int mkpath(char *_path, unsigned int _mode)
{
	struct stat sb;
	char *slash;
	int done = 0;

	slash = _path;

	while(!done)
	{
		slash += strspn(slash, "/");
		slash += strcspn(slash, "/");

		done = (*slash == '\0');
		*slash = '\0';

		if(stat(_path, &sb))
		{
			if((errno != ENOENT) || (mkdir(_path, _mode) && (errno != EEXIST)))
			{
				warn("%s", _path);
				return -1;
			}
		}
		else if(!S_ISDIR(sb.st_mode))
		{
			warnx("%s: %s", _path, strerror(ENOTDIR));
			return -1;
		}

		*slash = '/';
	}

	return 0;
}
