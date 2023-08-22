#include "trans.h"

int main(void)
{
    trans *dic = NULL;
    char *from, *to;

    dic = import_dic();
    while (true)
    {
        to = NULL;
        from = getword();
        if (builtAction(from, dic))
            continue;
        to = check_dic(from, &dic);
        if (!to)
            gettran(&dic, from);
        if (from)
            free(from);
        output(to);
    }
    return (0);
}
