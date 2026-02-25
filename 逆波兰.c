#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100
int evalRPN(char** tokens, int tokensSize)
{
    int* stack = (int*)malloc(sizeof(int) * tokensSize);
    int top = -1;
    for (int i = 0; i < tokensSize; i++)
    {
        char* s = tokens[i];
        if (strlen(s) > 1 || s[0] >= '0' && s[0] <= '9')
        {
            stack[++top] = atoi(s);
        }
        else {
            int b = stack[top--];
            int a = stack[top--];
            switch (s[0]) {
            case '+':
                stack[++top] = a + b; break;
            case '-':
                stack[++top] = a - b; break;
            case '*':
                stack[++top] = a * b; break;
            case '/':
                stack[++top] = a / b; break;
            }
        }
    }
    int result = stack[0];
    free(stack);
    return result;
}

int main(){
    char* tokens[] = { "15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-" };
    int tokenCount = sizeof(tokens) / sizeof(tokens[0]);
    printf("¼ÆËã½á¹û: %d\n", evalRPN(tokens, tokenCount));
    return 0;
}