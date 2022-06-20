#include "uptime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>
#include <sys/sysinfo.h>

void uptime_print(struct sysinfo sys)
{
	time_t t;
	int users;
	int hours;
	int mins;
	struct tm *time_now;
	struct utmp *ut;

	t = time(NULL);
	users = 0;
	if((time_now = localtime(&t)) == NULL)
	{
		perror("uptime(uptime.c): Can't get time");
		exit(EXIT_FAILURE);
	}
	if((ut = getutent()) == NULL)
	{
		perror("uptime(uptime.c): Can't get users");
		exit(EXIT_FAILURE);
	}

	while(ut)
	{
		if(ut->ut_type == USER_PROCESS)
		{
			users++;
		}
		ut = getutent();
	}

	hours = sys.uptime / (60 * 60);
	mins = (sys.uptime / 60) - (hours * 60);

	printf(" %02d:%02d:%02d up %d:%02d,  %d user,  load average: %.2f, %.2f, %.2f\n",
			time_now->tm_hour,
			time_now->tm_min,
			time_now->tm_sec,
			hours,
			mins,
			users,
			sys.loads[0]/65536.0,
			sys.loads[1]/65536.0,
			sys.loads[2]/65536.0);
}

void uptime_pretty(long int seconds)
{
	long int days;
	int hours;
	int mins;

	days = seconds / (24 * 60 * 60);
	hours = (seconds / (60 * 60)) - (days * 24);
	mins = (seconds / 60) - (hours * 60);

	if(days > 0)
	{
		printf("up %ld day%s, %d hour%s, %d minute%s\n",
				days,
				days == 1 ? "" : "s",
				hours,
				hours == 1 ? "" : "s",
				mins,
				mins == 1 ? "" : "s");
	}
	else
	{
		printf("up %d hour%s, %d minute%s\n",
				hours,
				hours == 1 ? "" : "s",
				mins,
				mins == 1 ? "" : "s");
	}
}

void uptime_since(long int seconds)
{
	time_t t;
	struct tm *time_since;

	t = time(NULL);
	t -= seconds;
	if((time_since = localtime(&t)) == NULL)
	{
		perror("uptime(uptime.c): Can't get time");
		exit(EXIT_FAILURE);
	}

	printf("%04d-%02d-%02d %02d:%02d:%02d\n",
			time_since->tm_year + 1900,
			time_since->tm_mon + 1,
			time_since->tm_mday,
			time_since->tm_hour,
			time_since->tm_min,
			time_since->tm_sec);
}
