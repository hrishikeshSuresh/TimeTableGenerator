//Linked list to read all the teacher_name from the teacher_name file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char teacher_name[30];
	char subject;
	struct Node *link;
} Node;

typedef struct List {
	Node* head;
	int no_of_teachers;
} List;

//Create an empty linked list
List* create_list();

//Insert a new Node at the beginning of the linked list
void insert_beginning(List* list, char teacher_name[]);

//Delete the first Node having the element "teacher_name".
//No operation if there is no such Node.
void delete_element(List* list, char teacher_name[]);

//Display the elements of the linked list seperated by spaces in a single line
void disp_list(List* list);

//Delete the linked list along with any qes it has.
void delete_list(List* list);

int main()
{
	int choice=1;
	List* list = create_list();
	char *name;
	char line[30];
	FILE *fp = fopen("teachers_data.csv","r+");
	while(choice > 0 && choice < 4)
	{
		printf("1. Auto enter the details of teachers \n");
		printf("2. Delete a record of teacher\n");
		printf("3. Display the list \n");
	  scanf("%d",&choice);
		switch(choice)
		{
   			case 1 : while(fgets(line,sizeof(line),fp)!=NULL)
								 {
									  char *subject;
									 	name=strtok(line,",");
										subject=strtok(NULL,",");
										puts(name);
										puts(subject);
										insert_beginning(list,name);
								 }
								 break;
				case 2 : printf("Enter the name of the teacher to be removed from the list\n");
				         scanf("%s",&name);
				         delete_element(list, name);
				         break;
				case 3 : disp_list(list);
				     		 break;
		  }
		fclose(fp);
		}
}
List* create_list()
{
    List *list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->no_of_teachers=0;
    return list;
}
void insert_beginning(List* list,char teacher_name[])
{
    Node* p=(Node*)malloc(sizeof(Node));
		int i = 0;
		printf("\n**check**\n");
    for(i=0;i<strlen(teacher_name);i++)
			p->teacher_name[i]=teacher_name[i];
    p->link=list->head;
    list->head=p;
    list->no_of_teachers+=1;
}
void delete_element(List *list,char teacher_name[])
{
  Node *p,*temp;
  if(list->head==NULL)
  {
    printf("No elements present in the linked list.\n");
  }
  else
  {
    p=list->head;
    while(p->link!=NULL)
    {
      if(strcmp(p->teacher_name,teacher_name)==0)
      {
        p->link=NULL;
        break;
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
void delete_list(List* list)
{
    Node* p=list->head;
    Node* q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->link;
        free(q);
    }
}
