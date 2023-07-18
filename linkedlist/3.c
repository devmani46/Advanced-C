#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char data[50];
    struct Node *nextnode;
}node;
node *firstnode;
node *newNode;
//insert from the beginning 
void nodeFromTheBegining(char data[]){
    if (firstnode==NULL){
        firstnode=malloc(sizeof(node));
        strcpy(firstnode->data,data);
        printf("%s \n",data);
        firstnode->nextnode=NULL;
    }else{
        node *newnode= malloc(sizeof(node));
        strcpy(newnode->data,data);
        printf("%s \n",data);
        newnode->nextnode=firstnode;
        firstnode=newnode;
    }
}

// insertion at the End
void insertANodeInTheEnd(char data[]){
    if (firstnode == NULL)
    {
        firstnode = malloc(sizeof(node));
        strcpy(firstnode->data,data);
        // printf("%s\n",data);
    }
    else{
    //traverse in the last node first
    node *temp = firstnode;
    while (temp->nextnode != NULL)
    {
        temp = temp -> nextnode;
    }
    //else part
        newNode= malloc(sizeof(node));
        strcpy(newNode->data,data);
        temp->nextnode = newNode;
    }

}

//transverse from the end
void traverse(){
    node *temp= firstnode;
    while (temp->nextnode!=NULL)
    {
        printf("%s ->",temp->data);
        temp =temp->nextnode;
    }
    printf("%s\n",temp->data);
}

//deletion from the end
void deleteANodeFromTheEnd(){
    node *temp = firstnode;
    node *secondLastNode;
    while (temp->nextnode != NULL)
    {
        // printf("%s ->",temp->data);
        secondLastNode = temp;
        temp = temp -> nextnode;
    }
    secondLastNode->nextnode = NULL;
}

void deleteANodeFromTheStart(){
    if(firstnode == NULL){
        printf("LinkedList is empty\n");
    }
    else{
        node *secondNode = firstnode->nextnode;
        firstnode=secondNode;
    }
}

int main(int argc, char const *argv[])
{
    // printf("IIMS College - DSA youtube channel playlist\n");
    // printf("Insertion operation.....\n");
    nodeFromTheBegining("Week 1 ");
    nodeFromTheBegining("Week 2");
    nodeFromTheBegining("Week 3");
    nodeFromTheBegining("Week 4");
    nodeFromTheBegining("Week 5");

    // traverse
    // printf("Traversing operation......\n");
    traverse();


//    printf("Deletion operation(Sam finished two of the to-do list)\n")
    deleteANodeFromTheStart();
    traverse();

    insertANodeInTheEnd("Week 5");
    traverse();

    deleteANodeFromTheEnd();
    traverse();    
    return 0;
}