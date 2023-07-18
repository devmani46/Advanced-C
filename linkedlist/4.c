#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct Node
{
    /* data */
    char data[50];
    struct Node *nextNode; // ->
} Node;

Node *firstNode; // null

void insertANodeIntheStart(char data[])
{
    if (firstNode == NULL)
    {
        firstNode = malloc(sizeof(Node));
        strcpy(firstNode->data, data);
        printf("%s\n", data);
    }
    else
    {
        Node *newNode = malloc(sizeof(Node));
        strcpy(newNode->data, data);
        printf("%s\n", data);
        newNode->nextNode = firstNode;
        firstNode = newNode;
    }
}

void traverseEachNode()
{
    Node *temp = firstNode;
    while (temp->nextNode != NULL)
    {
        printf("%s ->", temp->data);
        temp = temp->nextNode;
    }
    printf("%s", temp->data);
}

void deleteANodeFromTheEnd()
{
    Node *temp = firstNode;
    Node *secondLastNode;
    while (temp->nextNode != NULL)
    {
        secondLastNode = temp;
        temp = temp->nextNode;
    }
    secondLastNode->nextNode = NULL;
}


int main(int argc, char const *argv[])
{
    // printf("Insertion operation....\n");
    insertANodeIntheStart("adskjadskj1");
    insertANodeIntheStart("asdkja2");
    insertANodeIntheStart("askjasdj3");
    // printf("Traversing operation....\n");
    traverseEachNode();
    printf("\n");
    printf("Deletion operation....\n");
    deleteANodeFromTheEnd();
    traverseEachNode();
    return 0;
}
