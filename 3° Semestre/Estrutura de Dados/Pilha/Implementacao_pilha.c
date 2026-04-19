#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

bool isValidExpression(char *expression) {
    char stack[MAX_SIZE];
    int top = -1;
    for (int i = 0; expression[i] != '\0'; i++) {
        char symbol = expression[i];
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            stack[++top] = symbol;
        } else if (symbol == ')' || symbol == ']' || symbol == '}') {
            if (top == -1) return false;
            char lastOpen = stack[top--];
            if ((lastOpen == '(' && symbol != ')') || 
                (lastOpen == '[' && symbol != ']') || 
                (lastOpen == '{' && symbol != '}')) {
                return false;
            }
        }
    }
    return (top == -1);
}

int main() {
    char expression[] = "7 - ((X * ((X + Y) / (J - 3)) + Y) / (4 - 2.5))";
    if (isValidExpression(expression)) {
        printf("A expressao eh valida.\n");
    } else {
        printf("A expressao eh invalida.\n");
    }
    return 0;
}
