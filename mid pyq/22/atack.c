#include <stdio.h>

void push(int s[], int *top, int max, int val) {
    if (*top == max - 1) {
        printf("STACK IS FULL.\n");
        return;
    } else {
        (*top)++;
        s[*top] = val;
    }
}

int pop(int s[], int *top) {
    int x;
    if (*top == -1) {
        printf("STACK IS EMPTY.\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        x = s[*top];
        (*top)--;
    }
    return x;
}

int stackTop(int s[], int *top) {
    if (*top == -1) {
        printf("STACK IS EMPTY.\n");
        return -1; // Return a sentinel value indicating an error
    }
    return s[*top];
}

void display(int s[],int *top){
    for(int i=*top;i>-1;i--){
        printf("%d ",s[i]);
    }
    printf("\n");
}

int main() {
    int max;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);

    int st[max];
    int top = -1;

    push(st, &top, max, 1);
    push(st, &top, max, 2);
    push(st, &top, max, 4);
    push(st, &top, max, 3);

    printf("elements in stack:");
    display(st,&top);

    printf("Top of the stack: %d\n", stackTop(st, &top));

    printf("Popped element: %d\n", pop(st, &top));
    printf("Popped element: %d\n", pop(st, &top));

    printf("Top of the stack after popping: %d\n", stackTop(st, &top));

    printf("elements in stack:");
    display(st,&top);
    
    return 0;
}
