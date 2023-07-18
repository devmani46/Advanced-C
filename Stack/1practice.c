#include<stdio.h>

int top = -1;
int stacks[3];


void push(int element){
    if (top == 2)
    {
        printf("PUSH: Stack is full\n");
    }
    else{
        top++;
        stacks[top] = element;
        printf("%d is inserted in stack\n",element);
    }
}

void peek(){
    if (top == -1)
    {
        printf("PEEK: Stack is empty.\n");
    }
    else{
    printf("The element %d is at the top of the stack\n",stacks[top]);
    }
}

void pop(){
    if(top == -1){
        printf("POP: Stack is empty \n");
    }
    else{
        printf("The element %d is removed from the stack\n",stacks[top]);
        top--;
    }
}

int main(int argc, char const *argv[])
{
    push(10);
    push(20);    
    push(30);
    push(40);
    peek();
    pop();
    pop();
    pop();
    pop();
    peek();
    return 0;
}
