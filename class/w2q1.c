#include <stdio.h>

int top = -1;
int stacks[3];
//  public void push(int element){
//         top++;
//         stacks[top] = element;
//         System.out.println(element+ "  is inserted into a stack.");
//     }

// return_type functionName(parameter){

// }
void push(int element){
    if (top == 2)
    {
        printf("Stack is full!\n");
    }else{
    top++;
    stacks[top] = element;
    printf("%d  is inserted into a stack.\n",element);
    }   
}

void peek(){
    if(top == -1){
        printf("Peek operation cannot be performed as Stack is Empty.\n");
    }
    else{
        printf("The element %d is at the top of the stack\n",stacks[top]);
    }
}

int pop(){
    if (top==-1){
            printf("Pop operation cannot be performed as Stack is Empty.\n");
        }
        else {
            printf("%d is removed from a stack.\n",stacks[top] );
            top--;
        }
    printf("%d is removed from a stack.\n",stacks[top]);
    return stacks[top--];
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("Push(Insertion) Operation……\n");
    push(10);
    push(20);
    push(30);
    // push(40);

    printf("Peek Operation ....... \n");
    peek();

    printf("Pop(Deletion) Operation…\n");
    pop();
    pop();
    pop();
    pop();

    return 0;
}
