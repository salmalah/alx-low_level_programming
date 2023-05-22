#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int printf(const char *format, ...)
{
    const char *message = "9 8 10 24 75 9\n";
    const char *congrats = "congratulations, you win the jackpot\n";
    
    int i = 0;
    while (message[i] != '\0') {
        putchar(message[i]);
        i++;
    }
    
    i = 0;
    while (congrats[i] != '\0') {
        putchar(congrats[i]);
        i++;
    }
    
    exit(EXIT_SUCCESS);
}
