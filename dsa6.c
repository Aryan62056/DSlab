#include<stdio.h>
#include<stdlib.h>
#define queuesize 5
int count,front,rear,item,q[queuesize];
void insert_rear(){
    if(count == queuesize){
        printf("queue is full\n");
        return;
    }
    else{
        rear = (rear+1)%queuesize;
        q[rear]=item;
        count=count+1;
    }
}
void delete_front(){
    if(count==0){
        printf("queue is empty!!\n");
        return;
    }
    else{
        item=q[front];
        printf("the deleteed item is :%d",item);
        front=(front+1)%queuesize;
        count=count-1;
    }
}
void display(){
    int f,i;
    int count;
    if(count == 0){
        printf("queue is empty\n");
}
    else{
        printf("the contents of the queue are :\n");
        for(i=1, f=front; i<=count; i++) 
        {
            printf("%d\n",q[f]);
            f=(f+1)%queuesize;
        }
    }
}
void main(){
    int count=0;
    int rear=-1;
    int front =0;
int choice =1;
while(choice){
    printf("1.insert at rear\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.exit\n");
    printf("enter your choice\n");
    scanf("%d",&choice);


switch(choice){
    case 1:
    printf("enter the item to be inserted:");
    scanf("%d",&item);
    insert_rear();
    break;
    case 2:
    delete_front();
    break;
    case 3:
    display();
    break;
    case 4:
    exit(0);
}
}
}