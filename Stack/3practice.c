#include "stdio.h"
#include "string.h"

int top = -1;

char* stacks [3][200];

void push (char* number){
if (top==2){
    printf("Stack is full.%s cannot be added.\n",number);
}
else{
top++;
strcpy(stacks [top],number);
printf ("%s is inserted into stack.\n",number);
}
}



char* pop (){
    if (top==-1){
        printf("Stack is empty.\n");
     

    }
    else{
        char* r_number=stacks[top];
    top--;
    
    printf ("%s is removed from the stack.\n",r_number);
    
    }

}

void peek (){
 if (top==-1){
        printf("Stack is empty.\n");
        

    }
    else {
        printf("%s is at the top of stack.\n",stacks[top]);
    }

}


int main(int argc, char const *argv[])
{
    printf ("Push(Insertion) Operation…….\n");
push("1asd");
push("2asd");
push("3asd");
push("4asd");



peek();

    printf ("Pop(Deletion) Operation…….\n");
pop();
pop();
pop();
pop();

    return 0;
}
