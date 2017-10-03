//Linked list to read all the teacher_name from the teacher_name file
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Node {
	char teacher_name[30],subject;
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

//Delete the linked list along with any nodes it has.
void delete_list(List* list);

int main()
{
	int choice = 1;
	char *name,*subject;
	List* list = create_list();
	FILE *fp = fopen("teachers_data.csv","rw");
	while(choice > 0 && choice < 4)
	{
		printf("1. Auto enter the details of teachers \n");
		printf("2. Delete a record of teacher\n");
		printf("3. Display the list \n");
	  scanf("%d",&choice);
		switch(choice)
		{
   			case 1 : if(fp!=NULL && fgets(name,sizeof(name),fp)!=NULL)
								 {
									  char line[30];
									 	name=strtok(line,",");
										subject=strtok(NULL,",");
			             /*
										for(int i=0;i<strlen(namek);i++)
											name[i]=namek[i];
										for(int i=0;i<strlen(namek);i++)
											subject[i]=subjectk[i];
										*/
            		 		insert_beginning(list,name);
            		 }
								 fclose(fp);
								 break;
			  case 2 : printf("Enter the name of the teacher to be removed from the list\n");
				         scanf("%s", &name);
				         delete_element(list, name);
				         break;
		   	case 3 : disp_list(list);
            		 break;
		}
	}
}
List* create_list()
{
    List* list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->no_of_teachers=0;
    return list;
}
void insert_beginning(List* list,char teacher_name[])
{
    Node* nd=(Node*)malloc(sizeof(Node));
    for(int i=0;i<strlen(teacher_name);i++)
			nd->teacher_name[i]=teacher_name[i];
    nd->link=list->head;
    list->head=nd;
    list->no_of_teachers+=1;
}
void delete_element(List* list,char teacher_name[])
{
    Node* nd=list->head;
    Node* nod=NULL;
    while((nd!=NULL)&&(strcmp(nd->teacher_name,teacher_name)!=0))
    {
        nod=nd;
        nd=nd->link;
    }
    if((nod!=NULL)&&(nd!=NULL))
    {
        nod->link=nd->link;
        free(nd);
        list->no_of_teachers-=1;
    }
    else if((nod==NULL)&&(nd!=NULL))
    {
        list->head=nd->link;
        free(nd);
        list->no_of_teachers-=1;
    }
}
void disp_list(List* list)
{
    Node* nd=list->head;
    int x=0;
    while(nd!=NULL)
    {
        printf("%s",nd->teacher_name);
        nd=nd->link;
	  }
}
void delete_list(List* list)
{
    Node* nd=list->head;
    Node* nod=NULL;
    while(nd!=NULL)
    {
        nod=nd;
        nd=nd->link;
        free(nod);
    }
}
