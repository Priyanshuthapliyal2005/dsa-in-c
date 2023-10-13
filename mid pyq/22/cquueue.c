#include<stdio.h>
#include<stdlib.h>
void enqueue(int q[], int *front, int *rear, int max, int val) {
    if ((*rear + 1) % max == *front) {
        printf("Queue is full");
        return;
    } else {
        if (*front == -1) {
            *front = 0;
        }
        *rear = (*rear + 1) % max;
        q[*rear] = val;
    }
}

    
void dequeue(int q[],int *front,int *rear,int max)
{
    if(*front==-1){
    printf("Queue is empty");
    return;
    }
    else{
        if(*front==*rear){  
        printf("the element to be deleted is %d\n",q[*front]);
        *front=*rear=-1;
        return;
        }else{
            printf("the element to be deleted is %d\n",q[*front]);
            *front=((*front)+1)%max;
        }
     }
}

int frontele(int q[],int front){
    int x;
    if(front==-1){
        printf("Queue is empty\n");
    }else{
        x=q[front];
    }
    return x;
}

void display(int q[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("ELEMENTS IN QUEUE ARE:");
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}



int main(){
    int max;
    printf("\nenter the no of elemnts in queue:");
    scanf("%d",&max);
    int q[max];
    int front=-1,rear=-1;
    enqueue(q,&front,&rear,max,1);
    enqueue(q,&front,&rear,max,2);
    enqueue(q,&front,&rear,max,3);
    enqueue(q,&front,&rear,max,4);
    printf("elemnt in front of queue is:%d\n",frontele(q,front));

    display(q,front,rear);
    dequeue(q,&front,&rear,max);
    printf("elemnt in front of queue is:%d\n",frontele(q,front));
    display(q,front,rear);
}