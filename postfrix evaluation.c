#include<stdio.h>
int s[100];
int top = -1;
void push(int value){
    s[++top] = value;
}
int pop(){
    return s[top--];
}
int main(){
    int n[100];
    char exp[100];
    int count;
    int n1, n2;
    printf("Enter your expression : ");
    scanf("%s", &exp);
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] >= '1' && exp[i] <= '9'){
            printf("Enter your inputs : ");
            scanf("%d", &n[exp[i] - '1']);
            count++;
        }
    }
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] >= '1' && exp[i] <= '9'){
            push(n[exp[i] - '1']);
        } else {
            n2 = pop();
            n1 = pop();
            switch(exp[i]){
                case '+': push(n1+n2); break;
                case '-': push(n1-n2); break;
                case '*': push(n1*n2); break;
                case '/': push(n1/n2); break;
            }
        }
    }
    printf("Evaluate postfrix result : %d\n", pop());
return 0;
}