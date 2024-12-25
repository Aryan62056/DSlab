#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 50
struct employee{
    int empid;
    char name[20];
    int age;
}ht[max];
int hash(int key);
void main(){
    int i;
    int choice,index,key,age,count;
    char name[20];
    for(int i=0;i<max;i++){
        ht[i].empid=-1;
    }
    printf("1:insert\n2:search\n3:exit");
    while(1){
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:if(count==max-1){
                printf("table is full");
            }
            else{
                printf("Enter the unique empid\n");
                scanf("%d",&key);
                printf("enter the name of the employee\n");
                scanf("%s",name);
                printf("ENter the age\n");
                scanf("%d",&age);
                index=hash(key);
                if(ht[index].empid==-1){
                    ht[index].empid=key;
                    strcpy(ht[index].name,name);
                    ht[index].age=age;
                   }
                   else{
                    printf("collision occured\n");
                    printf("going to perform linear probing\n");
                    for(int i=1;i<max;i++){
                        index=(hash(key)+i)%max;
                        if(ht[index].empid==-1){
                             ht[index].empid=key;
                            strcpy(ht[index].name,name);
                           ht[index].age=age;
                        }
                        else{
                            printf("not able to find any space\n");
                        }
                    }
                   }
            }break;
            case 2:printf("enter the key to be searched");
            scanf("%d",&key);
            index=hash(key);
            if(ht[index].empid==key){
                printf("Name:%s\nAge%d",ht[index].name,ht[index].age);
            }
            else if(ht[index].empid==-1){
                printf("Key not found\n");
            }
            else{
                for(int i=1;i<max;i++){
                index=(hash(key)+i)%max;
                if(ht[index].empid==key){
                    printf("successful search\n");
                     printf("Name:%s\nAge%d",ht[index].name,ht[index].age);
                     break;
                }
                else{
                    if(ht[index].empid==-1){
                        printf("unsuccessful search\n");
                    }
                }
                }
            }
            break;
            case 3:printf("EXITING");
            exit(0);
            break;
            default:printf("Invalid choice\n");
        }
    }
}
int hash(int key){
    int index;
    index=key%max;
    return index;
}