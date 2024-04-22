#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int n;
    scanf("%d",&n);
    struct node *head = NULL;
    int input = n;
    while(input){
        int temp;
        scanf("%d",&temp);
        struct node *newNode;
        newNode = malloc(sizeof(struct node));
        newNode->data = temp;
        newNode->next = NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            struct node *track;
            track = head;
            while(track->next!=NULL){
                track=track->next;
            }
            track->next=newNode;
        }
        input--;
    }
    int b;
    scanf("%d",&b);
    
    //last node
    struct node *last;
    struct node *lastPrevious;
    lastPrevious = head;
    last = lastPrevious->next;
    while(last->next!=NULL){
        lastPrevious = lastPrevious->next;
        last = lastPrevious->next;
    }

    //insertion node
    struct node *point;
    struct node *pointPrevious;
    pointPrevious = head;
    if(b!=1){
        point = pointPrevious->next;
        for(int i=1;i<b-1;i++){
            pointPrevious = pointPrevious->next;
            point = pointPrevious->next;
        }

        //inserting
        pointPrevious->next = last;
    }
    else{
        point = head;
    }

    last->next = point->next;
    if(b==1) head = last;
    
    lastPrevious->next = point;
    point->next = NULL;

    //printing

    struct node *current;
    current = head;
    while(current!=NULL){
        printf("%d ",current->data);
        current = current->next;
    }

    return 0;
}