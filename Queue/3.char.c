#include<stdio.h>

char *queues[3];
int rear = -1;
int front = -1;

void enqueue(char element[]){
    if (rear==2){
        printf("%s cannot be inserted into the queue. The queue is full.\n",element);
    }else{
        rear++;
        queues[rear] = element;
        printf("%s is in the queue\n",queues[rear]);
    }

}

void dequeue(){
    if(front == rear){
        printf("cant be dequed");
    }
    else{
        front++;
        printf("%s is dequeued \n",queues[front]);
    }

}

int main(int argc, char const *argv[])
{
    enqueue("1asd");
    enqueue("2asd");
    enqueue("3asd");
    enqueue("4asd");
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}