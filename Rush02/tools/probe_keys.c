#include "rush02.h"
#include <unistd.h>

static int put(const char *s){ return (int)write(1, s, ft_strlen(s)); }

int main(int argc, char **argv)
{
    const char *keys[] = {
        "0","1","2","3","4","5","6","7","8","9",
        "10","11","12","13","14","15","16","17","18","19",
        "20","30","40","50","60","70","80","90",
        "100","1000","1000000","1000000000", 0
    };
    t_dict d;
    if (argc!=2){ put("usage: probe_keys <dict>\n"); return 1; }
    if (parse_dict(argv[1], &d)!=0){ put("parse failed\n"); return 2; }
    for (int i=0; keys[i]; i++){
        const char *v = dict_find(&d, keys[i]);
        if (!v){ put("MISS "); put(keys[i]); put("\n"); }
    }
    free_dict(&d);
    return 0;
}
