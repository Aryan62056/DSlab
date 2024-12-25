#include<stdio.h>
#include<ctype.h>
#define max_size 100
int top=-1;
int s[max_size];
int elem;
void push(char elem){
    s[++top]=elem;
}
char pop(){
    return s[top--];
}
int pr(char elem){
    switch(elem){
        case '#':
        return 0;
        case '(':
        return 1;
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        case '%':
        return 3;
        case '^':
        return 4;

    }
}
void main(){
    char infx[50],pofx[50],ch,elem;
    int k;
    printf("enter the infix expression\n");
    scanf("%s",infx);
    push('#');
    while((ch==pofx[k++])!='\0'){
        if(ch=='('){
            push(ch);
        }
            else if(isalnum(ch)){
                pofx[k++]=pop();
             }
             else if(ch==')'){
                while(ch!='()'){
                    pofx[k++]=pop();
                    elem=pop();
                }
             }
             else{
                while(pr(s[top])>=pr(ch))
                    pofx[k++]=pop();
                    push(ch);
                
             }

    }
    while(s[top]!='#')
    pofx[k++]=pop();
    pofx[k]='\0';
    printf("\n\n the given infx expression:%s is pofx expn:%s\n",infx,pofx);
}