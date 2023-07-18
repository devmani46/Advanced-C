#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data[50];
    struct Node *nextnode;
}node;
node *FirstNode;
void insertfromlast(char data[]){
    node *newnode= malloc(sizeof(node));
    strcpy(newnode->data,data);
    newnode->nextnode=NULL;
    if(FirstNode==NULL){
        FirstNode=newnode;
}else{
    node *temp=FirstNode;
    while(temp->nextnode!=NULL){
        temp=temp->nextnode;
        }
        temp->nextnode=newnode;
        }
        printf("%s\n",newnode->data);
}


void traverse(){
    node *temp= FirstNode;
    while (temp->nextnode!=NULL)
    {
        printf("%s ->",temp->data);
        temp =temp->nextnode;
    }
    printf("%s\n",temp->data);
}
void deleting(){
    node *temp=FirstNode;
    node *secondlast;
    while (temp->nextnode  != NULL)
    {
        secondlast=temp;
        temp=temp->nextnode;
    }
    secondlast->nextnode=NULL;
    traverse();    
}

int main(int argc, char const *argv[])
{
    printf("Sam's to-do list for today\n");
    printf("Insertion operation.....\n");
    insertfromlast("Read DSA");
    insertfromlast("Code");
    insertfromlast("Use chat gpt");
    insertfromlast("Dance");

    printf("Traversing operation....\n");
    traverse();

    printf("Deletion operation(Sam finished two of the to-do list)\n");    
    deleting();
     

    
    
    return 0;
}

