#include <unistd.h>
int dbg_puts(const char *s)
{
    int n = 0;
    if (!s)
        return (0);
    while (s[n])
        n++;
    return (int)write(2, s, n);
}
