#include<stdio.h>
#include<string.h>
#include"Header.h"
#include<conio.h>
#include<stdlib.h>


enum {false,true}bool,flag;    // it is implementation to boolen type .

static int size;          // number of tasks .

static int check = 0;          // variable to count number of attempts of login .

int login ()   // function ask user to enter his name and password (which is hidden) and user have 3 attempts .
{
    printf("\nMAX size of password is 5 \n");
char *username = "admin";
char *password ="admin";
    char user[6];
    char pass [6];


    while(check != 3)
    {
    printf("enter your username : ");
    scanf("%6s",user);
    printf("enter your password : ");
    int i = 0 ;
    do{
    pass[i] = getch();       // function to read character and hide input
    if(pass[i-1]!='\r') {    // check if input not equal (enter)
        printf("*");         // print star on screen .
    }
    i++;
    }while(pass[i-1]!='\r' && i<=5);

     pass[i-1]='\0';
     if(strcmp(username,user) != 0 || strcmp(password,pass) != 0)  // compare input with stored password and username .
     {
         if(check<3)
         printf("\nusername or password is not correct .. Try again !\n");
         check++;
     }else{
     return true;
     }
    }
    printf("Try again in later time :(");
    return false ;
}

//--------------------------------

void init(Tasks ** ptr)    // function to start program and  reserves a place in memory (heap) .
{
    *ptr = (Tasks *)malloc(sizeof(Tasks));
 size = 0 ;
}
void delete_all_task(Tasks ** ptr)   // function to terminate program and free place which i resreve .
{
    printf("\nThanks for using our program :) \n");
    free(*ptr);
}

//------------------------------------------------------------

void add_task(Tasks **ptr)   // passing using (pointer to pointer ) to change in pointer variable itself .
{
   if(size >= 5) {
      printf("you exceeded number of task allowed :( \n");
      return;
   }

    *ptr = (Tasks *) realloc(*ptr,MAX_SIZE * sizeof(Tasks));    // reserve (number of block in heap) .

    Tasks *new_task = (*ptr+size);

    new_task->ID = rand()%100;    // function to generate rand number from 0 to 100 .
    printf("Enter task title : ");

    fflush(stdin);    // to clear buffer memory .
    fgets(new_task->task_title,MAX_sizeof_title,stdin);   // read task title .


    printf("Enter discription : ");

    fgets(new_task->task_discription,MAX_sizeof_discription,stdin);  // read task discription .
    printf("enter (1) if task is urgent or (0) else : ");
    scanf("%d",&new_task->task_state);

     flag = true ;
    if(new_task->task_state!=0&&new_task->task_state!=1)
    {
        printf("Wrong number try again :(");
        flag = false ;
    }

if(flag)
 {
 size++;
 }

}

//---------------------------------------------------------

int find(int num,Tasks *p)    // function which return index of task which you want to delete .
{
   for(int i=0 ;i<=size;i++ )
   {
      if((p+i)->ID == num) return i ;
   }

    return -1;
}



/*void fit (Tasks *ptr)
{
     for (int i = 1; i < number_task; i++)
     {
      for(int j =1 ; j <number_task-i+1 ; j++ )
      {
         if((ptr+j)->ID < (ptr+j+1)->ID)
         {
            Tasks swap = *(ptr+j) ;
            *(ptr+j) = *(ptr+j+1) ;
            *(ptr+j+1) = swap ;

         }
      }
   }

}*/

void delete_task(int id ,Tasks *ptr)  // function to delete task by (id) .
{
    if(size==0)
    {
         printf("there is not any tasks exist :( \n");
         return;
    }
   int ch = find(id,ptr);
   if(ch != -1){
      (ptr+ch)->ID = ID_deleted;

      *(ptr+ch) = *(ptr+size-1) ;   // swap task which you want to delete with last task .
      size--;
      //fit(ptr);

      return;
   }else
   {
      printf("ID is not correct :( \n");

   }
}

//-------------------------------------------------------------------

/*void sort(Tasks *ptr)
{
   for (int i = 0; i < size; i++)
   {
      for(int j =0 ; j <size-i ; j++ )
      {
         if((ptr+j)->task_state < (ptr+j+1)->task_state)
         {
            Tasks swap = *(ptr+j) ;
            *(ptr+j) = *(ptr+j+1) ;
            *(ptr+j+1) = swap ;
         }
      }
   }

}*/

void show_tasks(Tasks *ptr)  // function to show tasks sorted from urgent to not .
{
    if(size == 0)
    {
        printf("there is not existing any tasks ..\n");
        return;
    }
  //sort(ptr);
  printf("---------------------------------------------------\n");
  int index = 0;
  for (size_t i = 0; i < size; i++)  // print urgent first
  {
      if(ptr->task_state == 1)
      {
          index++;
    printf("TASK [%d].. : \n",index);
    printf("Task ID : %d\n",(ptr+i)->ID);
    printf("Task title : %s",(ptr+i)->task_title);
    printf("Task discriptin : %s\n",(ptr+i)->task_discription);
    printf("---------------------------------------------------\n");
      }

  }
for (size_t i = 0; i < size ; i++)
  {
      if(ptr->task_state == 0)
      {
        index++;
    printf("TASK [%d].. : \n",index);
    printf("Task ID : %d\n",(ptr+i)->ID);
    printf("Task title : %s",(ptr+i)->task_title);
    printf("Task discriptin : %s\n",(ptr+i)->task_discription);
    printf("---------------------------------------------------\n");
      }
  }
}

//------------------------------------------------------------------

void list(Tasks * ptr)   // list of operation which you can to do .
{
    printf("\n------------------------------------------------\n");
    int number;
    printf("\nenter number of choose which you want to do :\n-Add task(1)\t-Delete_task(2)\t-Show_tasks(3)\t-Quit mode(4)\n");
    printf("your choose : ");
    scanf("%d",&number);
    switch(number)
    {
    case 1 :
        add_task(&ptr);
        break;
    case 2 :
        int id ;
        printf("enter the ID you want to delete : ");
        scanf("%d",&id);
        delete_task(id,ptr);
        break;
    case 3 :
        show_tasks(ptr);
        break;
    case 4 :
        delete_all_task(&ptr);
        exit(0);
        break;
    default :
        printf("\nwrong number :(\n");
        break;
    }
    list(ptr);     // to run program until stack overflow .
}
