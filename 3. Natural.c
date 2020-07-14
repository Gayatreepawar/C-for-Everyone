#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list
{
    char name[20];
    char symbol[10];
    float weight;
    int num;
    struct list *next;
}list;

list* create_list(int a,char b[20],char c[10],float d)
{
    list* head=malloc(sizeof(list));
    head->num=a;
    strcpy(head->name,b);
    strcpy(head->symbol,c);
    head->weight=d;
    head->next=NULL;
    return head;
}
list* add(int a,char b[20],char c[10],float d,list* h)
{
    list* head=create_list(a,b,c,d);
    head->next=h;
    return head;
}
void print(list* h)
{
    while(h!=NULL)
    {
        printf("Number: %d, Name: %s, Symbol: %s, Weight: %f \n",h->num,h->name,h->symbol,h->weight);

        h=h->next;
    }
}
int main()
{
    list element;
    list* head=NULL;
    int a;
    char b[20];
    char c[10];
    float d;
    printf("Enter first element number,name,symbol,weight with space: \n");
    scanf( "%d %s %s %f",&a,b,c,&d);
    head=create_list(a,b,c,d);
    int i=0;
    for(i=0;i<10;i++)
    {
        printf("Enter Next Element as first: ");
        scanf( "%d %s %s %f",&a,b,c,&d);
        head=add(a,b,c,d,head);
    }
    printf("Output:\n");
    print(head);
    return 0;
}
