#ifndef CYCLE_H_INCLUDED
#define CYCLE_H_INCLUDED

struct cycle
{
    int value;
    struct cycle *next;
};

struct cycle *dodajNowy(struct cycle *head,char var);
void wypiszCycle(struct cycle *head);
struct cycle *zwolnijCycle(struct cycle *head);
struct cycle *usunzCycle(struct cycle *head,char var);

#endif
