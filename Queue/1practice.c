#include<stdio.h>

int queues[3];
int rear = -1;
int front = -1;

void enqueue(int element){
    if (rear==2){
        printf("%d cannot be inserted into the queue. The queue is full.\n",element);
    }else{
        rear++;
        queues[rear] = element;
        printf("%d is in the queue\n",queues[rear]);
    }

}

void dequeue(){
    if(front == rear){
        printf("cant be dequed");
    }
    else{
        front++;
        printf("%d is dequeued \n",queues[front]);
    }

}

int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}

