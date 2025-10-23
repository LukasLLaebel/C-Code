// calculator.c
#include <stdio.h>
#include <math.h>
// do next op takes the operator operand and accumulator and calculate them in a switch
// depending on the input 
void do_next_op(char operator, double operand, double* accumulator) {
    switch (operator) {
      // First part here is the common +, -, *, /
      // It just takes the pointer of the accumulator and do the operation of the operator
      //  with the given number (operand)
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
        // Because you cannot divide by 0, checks for 0
        if (operand != 0)
          *accumulator /= operand;
        else
          *accumulator = *accumulator;
        break;
      // First special one is ^ it takes the accumulator and gives it an exponent of the operand
      case '^':
        *accumulator = pow(*accumulator, operand);
        break;
      // # puts the accumulator into an squre root it does that using the sqrt() from math.h
      case '#':
        if (*accumulator < 0) {
          *accumulator = *accumulator;
        } else {
          *accumulator = sqrt(*accumulator);
        }
        break;      
      // the % takes the accumulator and turns it to its reverse. this is done by multipying by -1
      case '%':
        *accumulator *= -1;
        break;
      // the ! is tricky, it says to divide by 1. that part is easy. but to prevent conflict we put the accumulator into ()
      // I do not know if there would be any conflicts so just to be sure i did that also so its easy to realize its an pointer not /* or to operators
      // we divide so like same rules
      case '!':
        if (*accumulator == 0) {
          *accumulator = *accumulator;  
        } else {
          *accumulator = 1/(*accumulator); 
        }
        break; 
      // at last we just do a default so the user knows they did something wrong if they did not put in the right operator
      default:
        printf("Error: Unsupported operator '%c'\n", operator);
        break;
    }
}
