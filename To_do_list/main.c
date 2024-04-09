#include <stdio.h>
#include <stdlib.h>
#include"Header.h"


int main()
{

   if(login())
    {
        Tasks *list_tasks;
        init(&list_tasks);

        list(list_tasks);

    }else
    {
        printf("Failed login :(\n");
    }
}
