#include "trans.h"

void main(void)
{
    trans *dic = NULL;
    char *from, *to;

    dic = import_dic();
    while (true)
    {
        to = NULL;
        from = getword();
        if (!(strcmp(from, "$$")))
        {
            saveAndFree(dic);
            free(from);
            break;
        }
        to = check_dic(from, &dic);
        if (!to)
            gettran(&dic, from);
        if (from)
            free(from);
        output(to);
    }
}
