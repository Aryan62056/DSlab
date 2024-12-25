#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct day{
    char *name;
    char *activity;
    int date;
};
struct day* create(){
    struct day *calendar;
    calendar=(struct day*)malloc(sizeof(struct day)*7);
    return calendar;
}
void read(struct day *calendar){
    char name[20];
    char activity[20];
    int i,date;
    for(i=0;i<7;i++){
        printf("enter the day\n");
        scanf("%s",name);
        calendar[i].name=(char*)malloc(strlen(name)+1);
       strcpy(calendar[i].name,name);
       printf("enter the date:\n");
       scanf("%d",&date);
       calendar[i].date=date;
       getchar();
       printf("enter the activity\n");
       scanf("%[^\n]s",activity);
       calendar[i].activity=(char*)malloc(strlen(activity)+1);
       strcpy(calendar[i].activity,activity);
}
}
void display(struct day *calendar){
int i;
printf("\n\nYour calendar\n");
printf("\n\n your activity\n");
for(i=0;i<7;i++){
    printf("day:%d ,day name:%s,date:%d,activity:%s\n",i+1,calendar[i].name,calendar[i].date,calendar[i].activity);
}
}
void main(){
    struct day *calendar;
    calendar=create();
    read(calendar);
    display(calendar);
    free (calendar);
}