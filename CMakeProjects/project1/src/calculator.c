// calculator.c
#include <stdio.h>
#include <math.h>

void do_next_op(char operator, double operand, double* accumulator) {
    switch (operator) {
      case '+':
        *accumulator += operand;
        break;
      case '-':
        *accumulator -= operand;
        break;
      case '*':
        *accumulator *= operand;
        break;
      case '/':
        if (operand != 0)
          *accumulator /= operand;
        else
          printf("Error: Division by zero.\n");
        break;
      case '^':
        *accumulator = pow(*accumulator, operand);
        break;
      case '#':
        *accumulator = sqrt(*accumulator);
        break;      
      case '%':
        *accumulator *= -1;
        break;
      case '!':
        *accumulator = 1/(*accumulator); 
        break;  
        default:
            printf("Error: Unsupported operator '%c'\n", operator);
            break;
    }
}
