#include "trans.h"

trans *insert_word(trans **head, char *fword, char *tword)
{
    trans *new = NULL;
    trans *current = *head, *prev = *head;

    new = malloc(sizeof(trans));
    if (!new)
        return (NULL);
    new->from = strdup(fword);
    new->to = strdup(tword);
    new->next = NULL;

    if (!*head)
    {
        new->next = NULL;
        *head = new;
        return (*head);
    }
    if (new->from[0] <= current->from[0])
    {
        new->next = current;
        *head = new;
        return(*head);
    }
    
    while (current)
    {
        if (new->from[0] > current->from[0] && !current->next)
        {
            current->next = new;
            new->next = NULL;
            return(*head);
        }
        if (new->from[0] <= current->from[0])
        {
            prev->next = new;
            new->next = current;
            return(*head);
        }
        prev = current;
        current = current->next;
    }
    return(*head);
}