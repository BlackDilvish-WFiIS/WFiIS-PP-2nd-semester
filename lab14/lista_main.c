#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
struct cycle *head=NULL;

head=dodajNowy(head,'f');
head=dodajNowy(head,'t');
head=dodajNowy(head,'d');
head=dodajNowy(head,'a');
wypiszCycle(head);
head=usunzCycle(head,'f');
wypiszCycle(head);
head=usunzCycle(head,'d');
wypiszCycle(head);
head=usunzCycle(head,'a');
wypiszCycle(head);
head=usunzCycle(head,'t');
wypiszCycle(head);
head=zwolnijCycle(head);
wypiszCycle(head);


return 0;
}
