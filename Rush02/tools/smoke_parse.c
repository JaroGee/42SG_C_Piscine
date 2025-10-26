#include "rush02.h"
#include <unistd.h>

static int put(const char *s){ return (int)write(1, s, ft_strlen(s)); }

int main(int argc, char **argv)
{
    t_dict d; int i;
    if (argc != 2){ put("usage: smoke_parse <dict>\n"); return 1; }
    if (parse_dict(argv[1], &d) != 0){ put("parse_dict failed\n"); return 2; }

    put("parsed size=");
    {
        char buf[32]; int n=d.size; int j=30; buf[31]=0;
        if (n==0){ put("0\n"); free_dict(&d); return 0; }
        while (j>=0){ buf[j--]=(char)((n%10)+'0'); n/=10; if (!n) break; }
        put(&buf[j+1]); put("\n");
    }

    for (i=0; i<d.size && i<10; i++){
        put(d.pairs[i].key); put(" -> "); put(d.pairs[i].val); put("\n");
    }
    free_dict(&d);
    return 0;
}
