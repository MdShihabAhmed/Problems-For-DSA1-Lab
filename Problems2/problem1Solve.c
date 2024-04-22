#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int queue[n];

    for(int i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }

    int moves = 0;
    while(n){
        int front = queue[0];

        //finding the minimum in the queue
        int min = 10000;
        for(int i=0;i<n;i++){
            if(queue[i]<=min){
                min = queue[i];
            }
        }

        //rearranging the queue
        for(int i=0;i<n-1;i++){
            queue[i]=queue[i+1];
        }

        //checking if the front value is the minimum value
        if(front==min){
            n--;
        }
        else{
            queue[n-1] = front;
            moves++;
        }
    }
    printf("%d\n",moves);
    return 0;
}