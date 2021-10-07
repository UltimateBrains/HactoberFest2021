//implementing a queue using a array structure

#include <iostream>
#include<iomanip>
using namespace std;

struct queue{
    int size;
    int f;
    int b;
    int * arr;
};

int isFull(struct queue *q){
    if(q->b == q->size-1){
        return 1;
    }
    else{return 0;}
}

int isEmpty(struct queue *q){
    if(q->f ==q->b){
        return 1;
    }
    else{return 0;}
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->b=q->b + 1;
        q->arr[q->b] = val;
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        q->f=q->f +1;
        int val=q->arr[q->f];
        return val;
    }
}

void queuetraversal(struct queue* q){
    cout<<"Traversing the queue elements:-- "<<endl;
    for(int i=q->f+1;i<=q->b;i++){
        cout<<q->arr[i]<<endl;
    }
}

int main(){
    struct queue q;
    cout<<"Enter size of queue"<<endl;
    cin>>q.size;
    q.f=-1;
    q.b=-1;
    q.arr = new int[q.size];
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,8);   //apply enqueue and dequeue operations
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    queuetraversal(&q);
}