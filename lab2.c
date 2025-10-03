#include <stdio.h>
#include <ctype.h>
#define size 50

char stack[size];
int top = -1;

void push(char e) {
    stack[++top] = e;
}

char pop() {
    return stack[top--];
}

int pr(char sy) {
    if (sy == '^')
        return 3;
    else if (sy == '*' || sy == '/')
        return 2;
    else if (sy == '+' || sy == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    push('#');  // stack bottom marker

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            elem = pop(); // remove '('
        } else {
            while (pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("\nPostfix Expression : %s\n", postfix);

    return 0;
}