#include "string.h"
/*
 * _putstr: prints out string
 * @return: returns output
 */


int _putstr(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
    }
    return len;
}

