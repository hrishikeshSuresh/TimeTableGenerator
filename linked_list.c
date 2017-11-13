//Linked list to read all the teacher_name from the teacher_name file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

typedef struct Node {
	char teacher_name[30];
	char subject;
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

int main()
{
	int choice=1;
	List* list = create_list();
	char *name,*subject;
	char line[30];
	FILE *fp = fopen("teachers_data.csv","r+");
	while(choice > 0 && choice < 5)
	{
		printf("1. Auto enter the details of teachers.\n");
		printf("2. Delete a record of teacher.\n");
		printf("3. Display the list.\n");
		printf("4. Delete list.\n");
	  scanf("%d",&choice);
		switch(choice)
		{
   			case 1 : while(fgets(line,sizeof(line),fp)!=NULL)
								 {
										int *i;
									 	name=strtok(line,",");
										subject=strtok(NULL,",");
										i = strtok(NULL,"\n");
										insert_beginning(list,name,subject,i);
								 }
								 break;
				case 2 : printf("Enter the name of the teacher to be removed from the list\n");
				         scanf("%s",&name);
				         delete_element(list,&name);
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
		p->hours=hours;
    for(int i=0;i<=strlen(teacher_name)-1;i++)
			p->teacher_name[i]=teacher_name[i];
		for(int k =0;i<=strlen(subject)-1;k++)
			p->subject[k]=subject[k];
    p->link=list->head;
    list->head=p;
		printf("%s\n",p->teacher_name );
    list->no_of_teachers+=1;
}
void delete_element(List *list,char teacher_name[])
{
  Node *p,*q;
  if(list->head==NULL)
  {
    printf("No elements present in the linked list.\n");
  }
  else
  {
    p=list->head;
		q=p;
    while(p!=NULL)
    {
      	if(strcmp(p->teacher_name,teacher_name)==0)
      	{
					q->link = p->link;
					printf("%s has been deleted.\n",p->teacher_name);
					free(p);
					list->no_of_teachers--;
      	}
				if(p!=NULL)
				{
					q = p;
					p = p->link;
				}
		}
  }
}
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

void timeTableGenerator(Node *list)
{
	Node *day,*timeTable;
	for(int i=0;i<=5;i++)
	{
		int check = 1;
		while(check)
		{
			int l = lengthOfLinkedList(&list);
			Node *p = list;
			int k = floor(rand()*l);
			while(p!=NULL)
			{
				p = p->link;
			}
			if(p->hours == 0)
				delete_element(&list,p->teacher_name);
				if(p==NULL && lengthOfLinkedList(&list)==5)
				{
					return;
		}
		if(p==NULL && lengthOfLinkedList(&list)==0)
			{
				printf("Current staff provided not sufficient.\n");
				break;
			}
			if(p->hours!=0)
			{
				timeTable=p;
				p->hours--;
				timeTable=timeTable->link;
			}
		}
	day = timeTable;
	day= day->link;
	}
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
