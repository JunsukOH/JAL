#define _CRT_SECURE_NO_WARNINGS        
#define MAX_SIZE 10000    

#include<stdio.h>
#include<string.h>


typedef struct stack {    
    int arr[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack* sp) {    
    sp->top = -1;
}

int check_stack_state_empty(Stack* sp) {    
    if (sp->top == -1) {
        return 1;
    }
    return 0;
}

int check_stack_state_full(Stack* sp) {
    if (sp->top + 1 >= MAX_SIZE) {
        return 1;
    }
    return 0;
}

void push(Stack* sp, int data) {
    if (check_stack_state_full(sp) == 1) {
        return;
    }
    sp->arr[++(sp->top)] = data;
}

int pop(Stack* sp) {     
    if (check_stack_state_empty(sp) == 1) {
        return -1;
    }
    return sp->arr[(sp->top)--];
}

int size(Stack* sp) {    
    return sp->top + 1;
}

int top(Stack* sp) {    
    if (check_stack_state_empty(sp) == 1) {
        return -1;
    }
    return sp->arr[sp->top];
}


int main(void) {
    Stack stack;
    char str[6];
    int n, num;

    scanf("%d", &n);
    fgetc(stdin);    
    stack_init(&stack);   


    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        fgetc(stdin);   

        if (!strcmp(str, "push")) {   
            scanf("%d", &num);
            fgetc(stdin);     
            push(&stack, num);
        }

        else if (!strcmp(str, "pop")) {
            printf("%d\n", pop(&stack));
        }

        else if (!strcmp(str, "empty")) {
            printf("%d\n", check_stack_state_empty(&stack));
        }

        else if (!strcmp(str, "size")) {
            printf("%d\n", size(&stack));
        }

        else if (!strcmp(str, "top")) {
            printf("%d\n", top(&stack));
        }
    }
    return 0;
}

