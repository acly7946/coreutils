#ifndef UPTIME_H
#define UPTIME_H

#include <sys/sysinfo.h>

void uptime_print(struct sysinfo sys);
void uptime_pretty(long int seconds);
void uptime_since(long int seconds);

#endif
