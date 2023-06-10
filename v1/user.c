#include "trans.h"

void gettran(trans **dic)
{
    char *tranfrom = NULL, *tranto = NULL;
    size_t weight, _weight, nr;

    write (STDOUT_FILENO, "I don't know, can you tech me?\n", 31);
    write (STDOUT_FILENO, "give me the English word:\n", 26);
    if ((nr = getline(&tranfrom, &weight, stdin)) != -1)
    {
        tranfrom[nr - 1] = '\0';
        write (STDOUT_FILENO, "add the translation: \n", 22);
        if ((nr = getline(&tranto, &_weight, stdin)) != -1)
        {
            tranto[nr - 1] = '\0';
            add_word(dic, tranfrom, tranto);
        }
    }
    write (STDOUT_FILENO, "Thank you very match\n", 21);
    free(tranfrom);
    if (tranto)
        free(tranto);
}

char *getword()
{
    char *tranfrom = NULL;
    size_t weight, nr;

    write (STDOUT_FILENO, "which word you want to translate: ", 34);
    if ((nr = getline(&tranfrom, &weight, stdin)) != -1)
    {
        tranfrom[nr - 1] = '\0';
        return (tranfrom);
    }
    else
        free(tranfrom);
    return (NULL);
}

void output(char *Desplay)
{
    if (Desplay != NULL)
    {
        write(STDOUT_FILENO, "your word is: ", 14);
        write(STDOUT_FILENO, Desplay, strlen(Desplay));
        write(STDOUT_FILENO, "\n", 1);
    }
}

char *check_dic(char *word, trans **dic)
{
    trans *checker = *dic;

    if (word == NULL)
        return (NULL);
    while (checker)
    {
        if (!(strcmp(word, checker->from)))
            return (checker->to);
        checker = checker->next;
    }
    return (NULL);
}

trans **add_word(trans **dic, char *fword, char *tword)
{
    trans *new = malloc(sizeof(trans));

    if (!new)
        return (NULL);
    new->from = strdup(fword);
    new->to = strdup(tword);
    new->next = NULL;
    if (dic == NULL)
    {
        *dic = new;
        return (dic);
    }
    new->next = *dic;
    *dic = new;
    return (dic);
}

void saveAndFree(trans *dic)
{
    size_t fd;
    trans *_free = NULL, *save = dic;

    fd = open("ENGLISH_TACHLHET", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd >= 0)
    {
        while (save)
        {
            write(fd, save->from, strlen(save->from));
            write(fd, "::::::::::::::::", 16);
            write(fd, save->to, strlen(save->to));
            write(fd, "\n", 1);
            _free = save;
            save = save->next;
            free(_free->from);
            free(_free->to);
            free(_free);
        }
        close(fd);    
    }
    else
        write(fd, "The dictionary can't be saved\n", 30);
}


trans *import_dic()
{
    trans *dic;
    char *tmp, *line = NULL, *tmpto, *tmpfrom, *del = ":";
    size_t fd, weight, nr;

    fd = open("ENGLISH_TACHLHET", O_RDONLY);
    if (fd >= 0)
    {
        FILE *file = fdopen(fd, "r");
        while ((nr = getline(&line, &weight, file)) != -1)
        {
            line[nr - 1] = '\0';
            tmpfrom = strtok(line, del);
            tmpto = strtok(NULL, del);
            add_word(&dic, tmpfrom, tmpto);
        }
        free(line);
        close(fd);
        fclose(file);
        return (dic);
    }
    else
        return (NULL);
}