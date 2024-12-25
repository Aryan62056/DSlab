#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define max_size 5
int stack[max_size],top=-1,item,i;
void push();
void pop();
void pali();
void display();
int main(){
    int choice=1;
    while(choice){
    printf("stack operation\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.pali\n");
    printf("4.display\n");
    printf("5.exit\n");
printf("eneter your choice\n");
scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        push();
        break;
        case 2: 
        pop();
        break;
        case 3:
        pali();
        break;
        case 4:
        display();
        break;
        default:
        printf("exiting\n");
        break;

    }
}
return 0;
}
void push(){
    if(top==max_size-1){
        printf("stack overflow!!\n");

    }
    else{
        printf("enter the elements to be inserted\n");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
printf("the %d is inesrted into stack",item);
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow cannot popped an elements\n");
    }
    else{

    item=stack[top];
    top=top-1;
    printf("the popped elements are :%d\t",item);
}
}
void pali(){
    int num,revnum,i,top=-1,k;
    if(top==-1){
        printf("stack is emppty\n");


    }
    else{
        while(top!=-1){
            num=num*10+item;
            revnum=item*pow(10,k)+revnum;
            k=k+1;
            
}
printf("the reversenumber of a %d is%d:",num,revnum);
if(num==revnum){
    printf("the number cis palindrome number\n");

}
printf("the number is not a palindrome number\n");


    }
}
void display(){
    if(top==-1){
        printf("stack is empty\n");
        
    }
    else{
        for(int i=top; i>=0; i--){
            printf("%d\n",stack[i]);
        }
    }
}