/*
WACP to evaluate an infix expression containing only two operators + and -.
The operands can be multi-digit numbers along with parentheses.
Sample input:- 200+30-(80-56)-30+(50+69)
Output must show the negative results with a sign (if it exists after evaluation).
The string length can go from 1 to 10^9
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to find precedence of operators.
int operatorPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    return 0;
}

// Function to perform arithmetic operations.
int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
    }
    return 0; // Handle other cases gracefully
}

// Function to push an element onto the integer stack.
void pushOperand(int operandStack[], int* operandTop, int value) {
    operandStack[++(*operandTop)] = value;
}

// Function to pop an element from the integer stack.
int popOperand(int operandStack[], int* operandTop) {
    return operandStack[(*operandTop)--];
}

// Function to push an element onto the operator stack.
void pushOperator(char operatorStack[], int* operatorTop, char operator) {
    operatorStack[++(*operatorTop)] = operator;
}

// Function to pop an element from the operator stack.
char popOperator(char operatorStack[], int* operatorTop) {
    return operatorStack[(*operatorTop)--];
}

// Function that returns the result of the expression as a string with the sign.
char* evaluateExpression(char *expression) {
    int i;
    
    // Stack to store integer operands.
    int operandStack[1000]; // Adjust the size as needed
    int operandTop = -1;
    
    // Stack to store operators.
    char operatorStack[1000]; // Adjust the size as needed
    int operatorTop = -1;
    
    // Variable to keep track of whether the next number is negative.
    int isNegative = 0;
    
    for (i = 0; i < strlen(expression); i++) {
        // Current token is a whitespace, skip it.
        if (expression[i] == ' ')
            continue;
        
        // Check for negative sign.
        if (expression[i] == '-' && (i == 0 || expression[i - 1] == '(')) {
            isNegative = 1;
            continue;
        }
        
        // Current token is an opening parenthesis, push it to the operator stack.
        else if (expression[i] == '(') {
            pushOperator(operatorStack, &operatorTop, expression[i]);
        }
        
        // Current token is a number, push it to the operand stack.
        else if (isdigit(expression[i])) {
            int value = 0;
            
            // There may be more than one digit in the number.
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            
            // Apply the negative sign if applicable.
            if (isNegative) {
                value = -value;
                isNegative = 0; // Reset the flag.
            }
            
            pushOperand(operandStack, &operandTop, value);
            
            // Right now, 'i' points to the character next to the digit.
            // Since the loop also increases 'i', we need to decrease it by 1 to correct the offset.
            i--;
        }
        
        // Current token is a closing parenthesis, solve the expression within the parentheses.
        else if (expression[i] == ')') {
            while (operatorTop >= 0 && operatorStack[operatorTop] != '(') {
                int operand2 = popOperand(operandStack, &operandTop);
                int operand1 = popOperand(operandStack, &operandTop);
                char operator = popOperator(operatorStack, &operatorTop);
                
                pushOperand(operandStack, &operandTop, performOperation(operand1, operand2, operator));
            }
            
            // Pop the opening parenthesis.
            if (operatorTop >= 0 && operatorStack[operatorTop] == '(')
                operatorTop--;
        }
        
        // Current token is an operator.
        else {
            // While the top operator has the same or greater precedence, apply it.
            while (operatorTop >= 0 && operatorPrecedence(operatorStack[operatorTop]) >= operatorPrecedence(expression[i])) {
                int operand2 = popOperand(operandStack, &operandTop);
                int operand1 = popOperand(operandStack, &operandTop);
                char operator = popOperator(operatorStack, &operatorTop);
                
                pushOperand(operandStack, &operandTop, performOperation(operand1, operand2, operator));
            }
            
            // Push the current operator onto the operator stack.
            pushOperator(operatorStack, &operatorTop, expression[i]);
        }
    }
    
    // Apply any remaining operators to remaining operands.
    while (operatorTop >= 0) {
        int operand2 = popOperand(operandStack, &operandTop);
        int operand1 = popOperand(operandStack, &operandTop);
        char operator = popOperator(operatorStack, &operatorTop);
                
        pushOperand(operandStack, &operandTop, performOperation(operand1, operand2, operator));
    }
    
    // The final result is at the top of the operand stack.
    int result = operandStack[operandTop];
    
    // Create a string to store the result with the sign.
    char* resultString = (char*)malloc(20); // Adjust the size as needed
    
    // Determine the sign of the result and format the string accordingly.
    if (result >= 0) {
        snprintf(resultString, 20, "+%d", result);
    } else {
        snprintf(resultString, 20, "%d", result);
    }
    
    return resultString;
}

int main() {
    printf("%s\n", evaluateExpression("200+30-(80-56)-30+(50+69)")); // Expected output: +295
    printf("%s\n", evaluateExpression("10+2-6")); // Expected output: +6
    printf("%s\n", evaluateExpression("12+13+30+230-2-7-1")); // Expected output: +275
    printf("%s\n", evaluateExpression("1+1-1+1-1-1-1+1-1")); // Expected output: -1
    printf("%s\n", evaluateExpression("-10-5+6-3")); // Expected output: -12

    return 0;
}
