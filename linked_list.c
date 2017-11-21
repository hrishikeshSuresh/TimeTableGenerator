//Linked list to read all the teacher_name from the teacher_name file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

typedef struct Node {
	char teacher_name[30];
	char subject[30];
	int hours,marks;
	struct Node *link;
} Node;

typedef struct List {
	Node* head;
	int no_of_teachers;
} List;

struct node{
  int priority;
  int info;
  struct node *next;
}*start=NULL,*q,*temp,*new;
typedef struct node N;
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
//Priority Queue functions below....


int main()
{
	int choice=1;
	List* list = create_list();
	char *name,*subject;
	int *item,*itprio;
	int *i;
	char line[30];
	char entry[30];
	FILE *file;
	FILE *fp = fopen("teachers_data.csv","r+");
	while(choice > 0 && choice < 8)
	{
		printf("\n1. Auto enter the details of teachers.\n");
		printf("2. Delete a record of teacher.\n");
		printf("3. Display the list.\n");
		printf("4. Delete list.\n");
		printf("5. Generate Time Table\n");
		printf("6. Performance Analyzer\n");
		printf("7. Exit Program\n");
	  scanf("%d",&choice);
		switch(choice)
		{
   			case 1 : while(fgets(line,sizeof(line),fp)!=NULL)
								 {
									 	name=strtok(line,",");
										subject=strtok(NULL,",");
										i = atoi(strtok(NULL,","));
										insert_beginning(list,name,subject,i);
								 }
								 printf("\nDatabase successfully loaded\n");
								 break;
				case 2 : printf("\nEnter the name of the teacher to be removed from the list\n");
				         scanf("%s",&entry);
								 delete_element(list,&entry);
				         break;
				case 3 : disp_list(list);
				     		 break;
				case 4 : delete_list(list);
								 break;
				case 5 : timeTableGenerator(list);
								 break;
				case 6 : 	file = fopen("ranke.csv","r");
									while(fgets(line,sizeof(line),file)!=NULL)
								 {
									 	item=atoi(strtok(line,","));
										itprio=atoi(strtok(NULL,","));
									  new=(N*)malloc(sizeof(N));
									  new->info=item;
									  new->priority=itprio;
									  new->next=NULL;
									  if(start==NULL )
									  {
									    //new->next=start;
									    start=new;
									  }
									  else if(start!=NULL&&itprio<=start->priority)
									  {
									    new->next=start;
									    start=new;
									  }
									  else
									  {
									    q=start;
									    while(q->next != NULL && q->next->priority<=itprio)
									    {q=q->next;}
									    new->next=q->next;
									    q->next=new;
									  }
								 }
								 fclose(file);
									break;
				case 7 : exit(0);
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
    list->no_of_teachers+=1;
}
void delete_element(List *list,char teacher_name[])
{
		Node *temp = list->head;
		Node* prev;
    if (temp != NULL && strcmp(temp->teacher_name,teacher_name)==0)
    {
        list->head = temp->link;
        free(temp);
				list->no_of_teachers--;
        return;
    }

		while (temp != NULL && strcmp(temp->teacher_name,teacher_name)!=0)
    {
        prev = temp;
        temp = temp->link;
    }
		if (temp == NULL)
			return;
    prev->link = temp->link;
    free(temp);
		list->no_of_teachers--;
		return;
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

void timeTableGenerator(List *list)
{
	FILE *f = fopen("final.csv","w");
	if(f == NULL)
	{
		printf("\nERROR LOADING FILE\n");
		return;
	}
	Node *timeTable;
	int check;
	int k,v,count,l,n=0;
	count = 0;
	for(int i=0;i<=4;i++)
	{
		if(i == 0)
			fprintf(f,"\nMONDAY\n");
		if(i == 1)
			fprintf(f,"\nTUESDAY\n");
		if(i == 2)
			fprintf(f,"\nWEDNESDAY\n");
		if(i == 3)
			fprintf(f,"\nTHURSDAY\n");
		if(i == 4)
			fprintf(f,"\nFRIDAY\n");
		check = 1;
		while(check)
		{
			v = 0;
			l = lengthOfLinkedList(list);
			Node *p = list->head;
			k = rand()%l;
			while(v<k && p!=NULL && l!=0)
			{
				p = p->link;
				++v;
			}
			if(list->no_of_teachers == 0)
			{
				printf("\nCurrent staff provided not sufficient.\n");
				fclose(f);
				check = 0;
				return;
			}
			if(p->hours == 0 )//&& height_name(list,p->teacher_name)!=1)
			{
				delete_element(list,p->teacher_name);
				list->no_of_teachers--;
			}
			if(p->hours!=0 && list->no_of_teachers!=0)
			{
				timeTable=p;
				fprintf(f,"%s,%s\n",timeTable->teacher_name,timeTable->subject);
				p->hours = p->hours - 1;
				count++;
				timeTable = timeTable->link;
			}
			if(count == 5)
			{
					count = 0;
					check = 0;
			}
		}
	}
	fclose(f);
	printf("\nTime Table generated.\n");
	return;
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

/*void insert(List *list,int item,int itprio)
{
  int item,itprio;
  new=(N*)malloc(sizeof(N));
  new->info=item;
  new->priority=itprio;
  new->next=NULL;
  if(start==NULL )
  {
    //new->next=start;
    start=new;
  }
  else if(start!=NULL&&itprio<=start->priority)
  {
    new->next=start;
    start=new;
  }
  else
  {
    q=start;
    while(q->next != NULL && q->next->priority<=itprio)
    {q=q->next;}
    new->next=q->next;
    q->next=new;
  }
}*/

void display()
{
  temp=start;
  if(start==NULL)
  printf("QUEUE IS EMPTY\n");
  else
  {
    printf("QUEUE IS:\n");
    if(temp!=NULL)
      for(temp=start;temp!=NULL;temp=temp->next)
      {
        printf("\n%d total =%d\n",temp->info,temp->priority);
      }
    }
}
