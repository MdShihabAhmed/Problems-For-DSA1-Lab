#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int stack[n];
    int top = -1;
    int moves = 0;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(top==-1 || stack[top]>=temp){
            top++;
            stack[top]=temp;
        }
        else{
            int stack2[top+1];
            int top2 = -1;
            while(top>-1 && stack[top]<temp){
                top2++;
                stack2[top2]=stack[top];
                top--;
                moves++;
            }
            top++;
            stack[top]=temp;
            while(top2>-1){
                top++;
                stack[top]=stack2[top2];
                top2--;
                moves++;
            }
        }
        moves++;
    }
    printf("%d\n",moves);
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }

    return 0;
}