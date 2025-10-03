#include<stdio.h>
#define max 5
int top=-1;
int stack[5];
void push (int val){
    if(top==max-1){
     printf("overflow");
    }else{
      stack[++top]=val;
      printf("added %d",val);
    }
}
void pop(){
    if(top==-1){
     printf("underflow");
    }else{
     int p = stack[top];
     printf("popped %d\n",p);
     top--;
    }
}
void display(){
    if(top==-1){
     printf("empty stack");
}else{
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
}
int main(){
    int t=1;
    while(t!=0){
    int c;
    printf("enter1:push,2:pop,3:display");
    scanf("%d",&c);
    switch(c){
        case 1:
        printf("enter value");
        int a;
        scanf("%d",&a);
        push(a);
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        default:printf("invalid choice");
        int t=0;
        break;
}
    }
}