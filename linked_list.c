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

//Delete the linked list along with any nodes it has.
void delete_list(List* list);

int main()
{
	int choice=1;
	List* list = create_list();
<<<<<<< HEAD
	char *name;
	char line[30];
=======
>>>>>>> cf54bb7808463917d749dbe3c1b36f8562c5b6dd
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
<<<<<<< HEAD
										puts(name);
										puts(subject);
=======
			             /*
										for(int i=0;i<strlen(namek);i++)  //namek not defined 
											strcpy(name[i],namek[i]);  
										for(int i=0;i<strlen(namek);i++) // subjectk not defined
											strcpy(subject[i],subjectk[i]);
										*/
>>>>>>> cf54bb7808463917d749dbe3c1b36f8562c5b6dd
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
    Node* nd=(Node*)malloc(sizeof(Node));
		int i = 0;
    for(i=0;i<strlen(teacher_name);i++)
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
    while(nd!=NULL)
    {
        printf("%s \n",nd->teacher_name);
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
