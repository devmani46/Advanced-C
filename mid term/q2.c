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
        printf("%s \n",queues[rear]);
    }

}

void dequeue(){
    if(front == rear){
        printf("Dequeue operation cannot be performed because queue is empty.");
    }
    else{
        front++;
        printf("%s is displayed on the screen. \n",queues[front]);
    }

}

int main(int argc, char const *argv[])
{
    printf("Nabil Bank bank counter queue \n");
    enqueue("Ticket No 1");
    enqueue("Ticket No 2");
    enqueue("Ticket No 3");
    printf("-----------------------\n");
    printf("Dequeue operation.....\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}
