#include <unistd.h>
#include "ft_printf.h"
#include <signal.h>

int handler_2(int *character)
{
    int i;
    int decimal;
    int position;

    decimal = 0;
    position = 0;
    i = 0;
    while (i < 8)
    {
        if (character[i] == 1)
            decimal += 1 << position;
        position++;
    }
    if (decimal == 0)
	    return 0;
    ft_printf("%c", decimal);
    return 1;

}

void handler(int signum)
{
    static int character[8];
    static int i;
    static int flag;

        //usleep(100);
        if (signum == SIGUSR1)
        {
            
            // character[i] = 0;
            ft_printf("%d, i : %d, new i : ", 0, i);
            i++;
            ft_printf("%d\n", i);
        }
        if (signum == SIGUSR2)
        {
            
            //character[i] = 1;
            ft_printf("%d, i : %d, new i : ", 1, i);
            i++;
            ft_printf("%d\n", i);
        }
        /*flag = handler_2(character);
        if (flag == 0)
            return ;*/
}

int main(int argc, char **argv)
{
    int pid;

    (void)argv;
    pid = getpid();
    if (argc == 1 && pid > 100 && pid < 99999)
    {
        ft_printf("server pid : %d\n", pid);
        while (1)
        {
            signal(SIGUSR1, handler);
            signal(SIGUSR2, handler);
        }
    }
    return (0);
}