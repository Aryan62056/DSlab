#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;
struct node{
    struct node *prev;
    int ssn,phno;
    char name[20],dept[20],desg[20];
    float sal;
    struct node *next;
} *first,*last,*temp,*temp1;
void create(){
     int ssn,phno;
    char name[20],dept[20],desg[20];
    float sal;
temp=(struct node*)malloc(sizeof(struct node));
temp->next=NULL;
temp->prev=NULL;
printf("\n enter ssn, name,dept ,desg ,phno ,salary ");
scanf("%d %s %s %s %d %f",&ssn,name,dept,desg,&phno,&sal);
temp->ssn=ssn;
strcpy(temp->name,name);
strcpy(temp->dept,dept);
strcpy(temp->desg,desg);
temp->phno=phno;
temp->sal=sal;
count++;    
}
void display(){
    temp1=first;
    if(temp1==NULL){
        printf("linked list is empty\n");
        return;

    }
    else{
        printf("elements from begining \n");
        while(temp1!=NULL){
           
           printf("%d %s %s %s %f %d\n",temp1->ssn,temp1->name,temp1->dept,temp1->desg,temp1->sal,temp1->phno);
             temp1=temp1->next;
        }


    }
    printf("no of employees :%d",count);

}
void insertatlast(){
    if(first==NULL){
       create();
       first=temp;
       last=first;
    }
    else{
        create();
        last->next=temp;
        temp->prev=last;
        last=temp;
    }


}
void insertatbeg(){
    if(first==NULL){
        create();
        first=temp;
        last=first;

    }
    else{
        create();
        temp->next=first;
        first->prev=temp;

    }
    

}
void deleteend(){
struct node *temp;
temp=first;
if(temp==NULL){
    printf("list is empty\n");

}
else {

     printf("%d %s %s %s %f %d\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
     free(temp);
     first=NULL;
}

}
void deleteatbeg(){
    struct node *temp;
    if(temp==NULL){
        printf("list is empty\n");
        return;
    }
    else {
         printf("%d %s %s %s %f %d\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
         free(temp);
         first=NULL;
    }
    
    count--;
}
void main(){
    int choice=0;
    int first=NULL;
    int last=NULL;
    int temp=NULL;
    int ch,n,i;
    printf("--------------MENU-----------\n");
    printf("\n 1-create a dll\n");
    printf("\n 2-display from beg\n");
    printf("\n 3-insert from beg\n");
    printf("\n 4-delete from beg\n");
    printf("\n 5-insert at end\n");
    printf("\n 6-dlete at end\n");
    printf("\n 7-EXIT\n");
    printf("----------------------\n");
    while(1){
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the no of student\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            insertatlast();
            break;
            case 2:
				display();
				break;
			case 3:
				insertatlast();
				break;
			case 4:
				deleteend();
				break;
			case 5:
				insertatbeg();
				break;
			case 6:
				deleteatbeg();
				break;
			case 7:
				exit(0);
			default:
				printf("wrong choice\n");
        }
    }

}


