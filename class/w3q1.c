// public class Node {
//      String data;// Yaad
//     Node nextNode; // ->

// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    /* data */
    //String data;// Yaad
    char data[50];
    // Node nextNode; // ->
    /* pointer variable:
        data_type *pointer_name; */
    struct node *nextNode;
    
}
node;

// public class LinkedListImpl {
    // Node firstNode; //null
node *firstNode;

    // public void insertANodeInTheStart(String data) {
        // if(firstNode == null){
        //     firstNode = new Node(); //data-> null, nextNode->null
        //     firstNode.data = data;
        //     System.out.println(data);
        // }else{
        //     Node newNode = new Node();
        //     newNode.data = data;
        //     System.out.println(data);
        //     newNode.nextNode = firstNode;
        //     firstNode = newNode;
        // }

void insertANodeInTheStart(char data[]){
    if (firstNode == NULL){
        //     Node newNode = new Node();
        firstNode=malloc(sizeof(node));
        // firstNode->data = data;
        strcpy(firstNode->data,data);
        printf("%s \n", data);
    }
    else{
        node *newNode =malloc(sizeof(node));
        strcpy(newNode->data,data);
        printf("%s \n", data);
        newNode -> nextNode = firstNode;
    }

}
//     public void traverseEachNode(){
//         while (temp.nextNode != null){
//             System.out.print(temp.data + " ->");
//             temp = temp.nextNode;
//         }
//         System.out.print(temp.data);


//     }

void traverseEachNode(){
//         Node temp = firstNode;
    node *temp = firstNode;
while (temp->nextNode != NULL)
    {
        //  System.out.print(temp.data + " ->");
        printf("%s ->", temp->data);
        //   temp = temp.nextNode;
        temp = temp->nextNode;
    }
    //         System.out.print(temp.data);
    printf("%s", temp->data);
}

void deleteANodeFromTheEnd()
{
    node *temp = firstNode;
    node *secondLastNode;
    while (temp->nextNode != NULL)
    {
        secondLastNode = temp;
        temp = temp->nextNode;
    }
    secondLastNode->nextNode = NULL;
}
    
//     public static void main(String[] args) {
//         LinkedListImpl linkedList = new LinkedListImpl();//firstNode= null
//         System.out.println("Insertion....");
//         linkedList.insertANodeInTheStart("Yaad-Sushant KC");
//         linkedList.insertANodeInTheStart("Hawa le-Sushant KC");
//         linkedList.insertANodeInTheStart("Hit Songs-Sushant KC");
//         System.out.println("Traversing......");
//         linkedList.traverseEachNode();
//     }
// }  
    int main(int argc, char const *argv[])
    {
    printf("Insertion operation....\n");
    insertANodeIntheStart("Yaad- Sushant KC");
    insertANodeIntheStart("Hawa le- Sushant KC");
    insertANodeIntheStart("Hit Songs- Sushant KC");
    printf("Traversing operation....\n");
    traverseEachNode();
    printf("\n");
    printf("Deletion operation....\n");
    deleteANodeFromTheEnd();
    traverseEachNode();
        return 0;
    }