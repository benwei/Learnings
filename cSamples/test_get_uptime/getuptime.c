#include <stdio.h>
#include <errno.h>
#include <linux/unistd.h> 
#include <linux/kernel.h>
#include <sys/sysinfo.h>

int getuptime(long *uptime)
{
    struct sysinfo s_info;
    int error;
    error = sysinfo(&s_info);
    if(error == -1) return -1;
    *uptime = s_info.uptime;
    return 0;
}

int main()
{
    long uptime = 0;

    int rc = getuptime(&uptime);
    if (rc == 0)
        printf("uptime: %ld \n", uptime);
    else
        printf("error: %d\n", errno);

    return 0;
}
