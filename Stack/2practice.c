#include <stdio.h>

int top = -1;

char stacks [3];

void push (char number){
if (top==2){
    printf("%c cannot be inserted into a stack as stack is full.\n",number);
}
else{
top++;
stacks [top] = number;
printf ("%c is inserted into stack.\n",number);
}
}

char peek(){
    if (top == -1)
    {
        printf("PEEK: Stack is empty.\n");
    }
    else{
        char r_number=stacks[top];
        printf("The element %c is at the top of the stack\n",r_number);
    }
}

char pop (){
    if (top==-1){
        printf("Stack is empty.\n");
     

    }
    else{
        char r_number=stacks[top];
    top--;
    
    printf ("%c \n",r_number);
    }

}


int main(int argc, char const *argv[])
{
push('D');
push('A');
push('D');
push('D');

peek();

    printf ("Its reverse form is(Pop operation): \n");
pop();
pop();
pop();

peek();

    return 0;
}
