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



char pop (){
    if (top==-1){
        printf("Stack is empty.\n");
    }
    else{
        char r_number=stacks[top];
    top--;
    printf ("%c",r_number);
    }
}


int main(int argc, char const *argv[])
{
push('D');
push('A');
push('D');
push('D');

    printf ("Its reverse form is(Pop operation): \n");
pop();
pop();
pop();

    return 0;
}
