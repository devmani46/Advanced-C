#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[50];
    struct Node *nextNode;
} 
node;
node *firstNode;
node *newNode;
void insertfromlast(char data[])
{
    newNode = malloc(sizeof(node));
    strcpy(newNode->data, data);
    newNode->nextNode = NULL;
    if (firstNode == NULL)
    {
        firstNode = newNode;
    }
    else{
        node *uNode = firstNode;
        while (uNode->nextNode != NULL)
        {
            uNode = uNode->nextNode;
        }
            uNode->nextNode = newNode;
    }
    printf("%s\n", newNode->data);
}
void traverse(){
    node *node = firstNode;
    while (node->nextNode != NULL)
    {
        printf("%s =>", node->data);
        node = node->nextNode;
    }
    printf("%s\n", node->data);
}

void removeFromLast(){
    if (firstNode == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *nodetodelete = firstNode;
    firstNode = firstNode->nextNode;
    nodetodelete->nextNode = NULL;
}

int main(int argc, char const *argv[]){
    printf("Insertion Operation in the linkedlist.....\n");
    insertfromlast("Wash Face");
    insertfromlast("Drink Coffee");
    insertfromlast("Code");
    printf("Traversing operation in the linkedlist....\n");
    traverse();

    printf("Deletion operation from the linkedlist....\n");
    removeFromLast();
    traverse();
  
    return 0;
}