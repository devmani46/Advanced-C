#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char data[50];
    struct Node *nextNode;

}Node;

// for reference variable use *
    Node *firstNode;
    Node *newNode;

//insertion at the beginning of the linkedlist
void insertANodeInTheStart(char data[]){
    if (firstNode == NULL)
    {
        firstNode = malloc(sizeof(Node));
        strcpy(firstNode->data,data);
        printf("%s\n",data);
    }
    else{
        newNode= malloc(sizeof(Node));
        strcpy(newNode->data,data);
        printf("%s\n",data);
        newNode->nextNode = firstNode;
        firstNode = newNode;
    }
}

// insertion at the End
void insertANodeInTheEnd(char data[]){
    if (firstNode == NULL)
    {
        firstNode = malloc(sizeof(Node));
        strcpy(firstNode->data,data);
        // printf("%s\n",data);
    }
    else{
    //traverse in the last node first
    Node *temp = firstNode;
    while (temp->nextNode != NULL)
    {
        temp = temp -> nextNode;
    }
    //else part
        newNode= malloc(sizeof(Node));
        strcpy(newNode->data,data);
        temp->nextNode = newNode;
    }

}

//traversing
void traverseEachNode(){
    Node *temp = firstNode;
    while (temp->nextNode != NULL)
    {
        printf("%s ->",temp->data);
        temp = temp -> nextNode;
    }
    printf("%s",temp->data);
}

//delete from last
void deleteANodeFromTheEnd(){
    Node *temp = firstNode;
    Node *secondLastNode;
    while (temp->nextNode != NULL)
    {
        printf("%s ->",temp->data);
        secondLastNode = temp;
        temp = temp -> nextNode;
    }
    secondLastNode->nextNode = NULL;
}

//delete from first
void deleteANodeFromTheStart(){
    if(firstNode == NULL){
        printf("LinkedList is empty\n");
    }
    else{
        Node *secondNode = firstNode->nextNode;
        firstNode=secondNode;
    }
}

    
    int main(int argc, char const *argv[])
    {
        insertANodeInTheStart("asd1");
        insertANodeInTheStart("asd2");
        insertANodeInTheStart("asd3");
        traverseEachNode();
        printf("\n");
        deleteANodeFromTheEnd();
        traverseEachNode();
        // printf("\n");
        // insertANodeInTheEnd("asd4");
        // traverseEachNode();
        // printf("\n");
        // deleteANodeFromTheStart();
        // traverseEachNode();
        return 0;
    }
