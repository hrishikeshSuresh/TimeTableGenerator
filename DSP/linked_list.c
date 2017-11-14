//Linked list to read all the teacher_name from the teacher_name file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

typedef struct Node {
	char teacher_name[30];
	char subject[30];
	int hours;
	struct Node *link;
} Node;

typedef struct List {
	Node* head;
	int no_of_teachers;
} List;

//Create an empty linked list
List* create_list();

//Insert a new Node at the beginning of the linked list
void insert_beginning(List* list, char teacher_name[],char subject[],int hours);

//Delete the first Node having the element "teacher_name".
//No operation if there is no such Node.
void delete_element(List* list, char teacher_name[]);

//Display the elements of the linked list seperated by spaces in a single line
void disp_list(List* list);

//Delete the linked list along with any qes it has.

List* delete_list(List* list);

//Generate time table
void timeTableGenerator(List *list);


int main()
{
	int choice=1;
	List* list = create_list();
	char *name,*subject;
	int *i;
	char line[30];
	char entry[30];
	FILE *fp = fopen("teachers_data.csv","r+");
	while(choice > 0 && choice < 5)
	{
		printf("1. Auto enter the details of teachers.\n");
		printf("2. Delete a record of teacher.\n");
		printf("3. Display the list.\n");
		printf("4. Delete list.\n");
		printf("5. Generate Time Table\n");
	  scanf("%d",&choice);
		switch(choice)
		{
   			case 1 : while(fgets(line,sizeof(line),fp)!=NULL)
								 {
									 	name=strtok(line,",");
										subject=strtok(NULL,",");
										i = atoi(strtok(NULL,"\n"));
										insert_beginning(list,name,subject,i);
								 }
								 break;
				case 2 : printf("Enter the name of the teacher to be removed from the list\n");
				         scanf("%s",&entry);
								 /*if(height_name(list,&entry) == 1)
								 	delete_element(list,&entry);
									else if(height_name(list,&entry) !=	1)*/
								 delete_element(list,&entry);
				         break;
				case 3 : disp_list(list);
				     		 break;
				case 4 : delete_list(list);
								 break;
				case 5 : timeTableGenerator(list);
								 break;
		}
	}
	fclose(fp);
}
List* create_list()
{
    List *list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->no_of_teachers=0;
    return list;
}
void insert_beginning(List* list,char teacher_name[],char subject[],int hours)
{
    Node* p=(Node*)malloc(sizeof(Node));
		if(hours == 0)
			list->no_of_teachers--;
		p->hours=hours;
    for(int i=0;i<=strlen(teacher_name)-1;i++)
			p->teacher_name[i]=teacher_name[i];
		for(int k =0;k<=strlen(subject)-1;k++)
			p->subject[k]=subject[k];
    p->link=list->head;
    list->head=p;
		printf("%s\n",p->teacher_name );
    list->no_of_teachers+=1;
}
void delete_element(List *list,char teacher_name[])
{
  Node *p,*q;
  p=list->head;
  while(p!=NULL)
  {
    	if(strcmp(p->teacher_name,teacher_name)==0)
	    {
				  printf("JIII\n");
					list->head = p->link;
					printf("%s has been deleted.\n",p->teacher_name);
					free(p);
					list->no_of_teachers--;
					return;
      }
			else
			{
				printf("current:%s\n",p);
				q = p;
				p = p->link;
			}
	}
	return;
}
/*
		Node* temp = list->head, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void delete_firstelement(List *list,char teacher_name[])
{
	Node *q;
	Node *p = list->head;
	q = p->link;
	list->head = q;
	free(p);
	printf("MOOO%s\n",q->subject);
	return;
}
*/
void disp_list(List* list)
{
    Node* p=list->head;
    while(p!=NULL)
			{
      	printf("%s \n",p->teacher_name);
        p=p->link;
	  	}
}
List* delete_list(List* list)
{
    Node* p=list->head;
    Node* q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->link;
        free(q);
    }
	list->head =NULL;
		return list;
}

void timeTableGenerator(List *list)
{
	FILE *f = fopen("final.csv","w");
	if(f == NULL)
	{
		printf("ERROR LOADING FILE\n");
		return;
	}
	Node *timeTable;
	int check = 1;
	int k,v,count;
	count = 0;
	printf("OK\n");
	//for(int i=0;i<=4;i++)
	//{
		while(check)
		{
			v = 0;
			int l = lengthOfLinkedList(list);
			Node *p = list->head;
			k = rand()%l;
			while(v<k && p!=NULL)
			{
				p = p->link;
				++v;
			}
			if(list->no_of_teachers == 0)
			{
				printf("Current staff provided not sufficient.\n");
				check = 0;
				return;
			}
			if(p->hours == 0 )//&& height_name(list,p->teacher_name)!=1)
			{
				delete_element(&list,p->teacher_name);
			}
			/*if(p->hours == 0 && height_name(list,p->teacher_name)==1)
			{
				printf("ENTER %s\n",p->subject);
				delete_element(&list,p->teacher_name);
			}*/
			if(p->hours!=0 && list->no_of_teachers!=0)
			{
				timeTable=p;
				printf("%s\n",timeTable->subject);
				fprintf(f,"%s,%s\n",timeTable->teacher_name,timeTable->subject);
				p->hours = p->hours - 1;
				count++;
				timeTable = timeTable->link;
				printf("---------------------------------------------------------\n");
			}
			if(count == 5)
			{
				printf("DONE\n");
				fclose(f);
				return;
			}
		}
	//}
}

void displayTimeTable(Node *day,Node *timeTable)
{
	while(day!=NULL)
	{
		while(timeTable!=NULL)
		{
			printf("%s",timeTable->subject);
			timeTable=timeTable->link;
		}
		day = day->link;
	}
}

int lengthOfLinkedList(List* list)
{
	int i =0;
	Node * p = list->head;
	while(p->link!=NULL)
	{
		i++;
		p = p->link;
	}
	return i;
}

int lengthNode(Node *p)
{
	int i =0;
	while(p->link!=NULL)
	{
		i++;
		p = p->link;
	}
}
