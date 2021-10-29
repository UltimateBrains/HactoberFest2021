//implementing a circular queue using dynamic array and structures and various operations
//Operations: Enqueue, Dequeue, IsEmpty, IsFull, QueueTraversal in a circular queue

#include<iostream>
#include<iomanip>
using namespace std;

struct circularqueue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct circularqueue* q){
    if(q->f==q->r){
        return 1;
    }
    else{return 0;}
}

int isFull(struct circularqueue* q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    else{return 0;}
}

void enqueue(struct circularqueue* q,int val){
    if(isFull(q)){
        cout<<"Queue overflow"<<endl;
    }
    else{
        q->r = (q->r+1)%(q->size);
        q->arr[q->r] = val;
        cout<<"Enqueuing element "<<val<<endl;
    }
}

int dequeue(struct circularqueue* q){
    if(isEmpty(q)){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        q->f = (q->f+1)%(q->size);
        int val = q->arr[q->f];
        cout<<"Dequeuing element "<<val<<endl;
        return val;
    }
}

int queuetraversal(struct circularqueue* q){
    for(int i=q->f+1; i!=q->r+1; i=(i+1)%(q->size)){
        cout<<q->arr[i]<<endl;
    }
}

int main(){
    struct circularqueue q;
    q.f=0;
    q.r=0;
    cout<<"Enter Circular-queue size"<<endl;
    cin>>q.size;
    q.arr = new int[q.size];   //remember that number of elements is always one less than the size of queue.
  //if size of circularqueue is 6, then number of elements maximum can be stored is 5, as one slot remains empty

    enqueue(&q,4);
    enqueue(&q,3);
    enqueue(&q,6);
    dequeue(&q);    //dequeuing the elements from the top
    dequeue(&q);
    enqueue(&q,7);  //enqueuing operation in queue
    enqueue(&q,10);
    enqueue(&q,13);
    enqueue(&q,16);
    enqueue(&q,26);
    
    cout<<"Queue elements remaining: "<<endl;
    queuetraversal(&q);

    return 0;
}