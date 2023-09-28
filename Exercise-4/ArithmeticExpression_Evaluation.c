#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
float calculate(char* ptr);
void push(char stack[], int n, int* top, char data){
    if (*top >= n){
        printf("Stack overflow!");
    }
    else{
        stack [++(*top)] = data;
    }
}
char pop(char stack[], int* top){
    if (*top == -1){
        printf("The stack is empty!");
    }
    else{
        char ch = stack[(*top)];
        (*top)--;
        return ch;
    }
}
void push2(float stack[], int n, int* top, float data){
    if (*top >= n){
        printf("Stack overflow!");
    }
    else{
        stack [++(*top)] = data;
    }
}
float pop2(float stack[], int* top){
    if (*top == -1){
        printf("The stack is empty!");
    }
    else{
        float f = stack[(*top)];
        (*top)--;
        return f;
    }
}
int priority(char c){
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '/' || c == '*')
        return 2;
    return 0;
}
char* convertType(char stack[], int n, int* top, char* a){
    char* arr = (char*)malloc(sizeof(char*));
    char c, ch[100];
    int i=0;
    while (*a != '\0'){
        if (isalnum(*a)){
            ch[i++] = *a; 
        }
        else if (*a == '('){
            push(stack, n, top, *a);
        }
        else if (*a == ')'){
            while ((c = pop(stack, top)) != '('){
                ch[i++] = c; 
            }
        }
        else {
            while (priority(stack[*top]) >= priority(*a)){
                ch[i++] = pop(stack, top); 
            }
            push(stack, n, top, *a);
        }
        a++;
    }
    while (*top != -1){
        ch[i++] = pop(stack, top); 
    }
    arr = ch;
    printf("\nThe result is %.2f \n\n", calculate(arr));
    return arr;
}
float calculate(char* ptr){
    float result;
    char c = *ptr;
    float stack2[100];
    int *t = (int*)malloc(sizeof(int*));
    *t = -1;
    int n = 20;
    while (c != '\0'){
        if ( c >= '0' && c <= '9'){
            push2(stack2, n, t, c - '0');
        }
        else if (c == '+'){
            float a = pop2(stack2, t);
            float b = pop2(stack2, t);
            float sum = a+b;
            push2(stack2, n, t, sum);
        }
        else if (c == '-'){
            float a = pop2(stack2, t);
            float b = pop2(stack2, t);
            float diff = b-a;
            push2(stack2, n, t, diff);
        }
        else if (c == '*'){
            float a = pop2(stack2, t);
            float b = pop2(stack2, t);
            float mul = a*b;
            push2(stack2, n, t, mul);
        }
        else if (c == '/'){
            float a = pop2(stack2, t);
            float b = pop2(stack2, t);
            float div = b/a;
            push2(stack2, n, t, div);
        }
        c = *(ptr++);
    }
    result = pop2(stack2, t);
    return result;
}
void main(){
    int *top = (int*)malloc(sizeof(int*));
    char *arr =  (char*)malloc(sizeof(char*));
    *top = -1;
    int n=20, i=0;
    char stack[10], *a, exp[100];
    printf("\nEnter the expression: ");
    gets(exp);
    a = exp;
    arr = convertType(stack, n, top, a);
}
