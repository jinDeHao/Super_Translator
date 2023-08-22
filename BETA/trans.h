#ifndef TRANS_H
#define TRANS_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct translator{
    char *from;
    char *to;
    struct translator *next;
} trans;

trans *import_dic();
char *getword();
void output(char *Desplay);
char *check_dic(char *word, trans **dic);
void saveAndFree(trans *dic);
void gettran(trans **dic, char *tranfrom);
trans *insert_word(trans **head, char *fword, char *tword);
int builtAction(char *from, trans *dic);
char *nSASE(char *string, int len);
char *upperC(char *addr);

#endif