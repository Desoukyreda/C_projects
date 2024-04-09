#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAX_SIZE 5
#define MAX_sizeof_title  25
#define MAX_sizeof_discription 150
#define ID_deleted -1


typedef struct {
 int ID ;
 char task_title[MAX_sizeof_title];
 char task_discription[MAX_sizeof_discription];
 int task_state;
}Tasks;

int login();
//void infinity();
void init(Tasks**);
void add_task(Tasks**);
void delete_task(int,Tasks*);
int find(int,Tasks*);
//void fit(Tasks*);
//void sort(Tasks*);
void show_tasks(Tasks*);
void list(Tasks *);
void delete_all_task(Tasks**);
#endif // HEADER_H_INCLUDED
