#include<stdio.h>
#include<stdlib.h>
void enqueue(int q[],int *front,int *rear, int max,int val)
{
    if(*rear==max-1){
        printf("Queue is full");
        return;
    }
    else{
        if(*rear==-1){ 
        *front=*rear=0;
        q[*rear]=val;
        }else{
        *rear=*rear+1;
        q[*rear]=val;
        }
    }
}
    
void dequeue(int q[],int *front,int *rear)
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
            *front=*front+1;
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

void display(int q[],int front,int rear){
    printf("ELEMENTS IN QUEUE ARE:");
    for(int i=front;i<=rear;i++){
        printf("%d ",q[i]);
        (front)++;
    }
    printf("\n");
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
    display(q,front,rear);
    dequeue(q,&front,&rear);
    printf("elemnt in front of queue is:%d\n",frontele(q,front));
    display(q,front,rear);
}