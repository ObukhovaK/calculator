/*
 ============================================================================
 Name        : heyworld_01.c
 Author      : Ekaterina Obukhova
 Version     :
 Copyright   : copyleft
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float a,b,result,count,pre;       /* a,b - numbers, count - counter, pre - preliminary result*/
char oper;                          /* operand */


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    pre = 1;

    puts("insert a, operand, b.");
    puts("Acceptable operands: +, -, *, /, ^, !  ");
    puts("Notice: for exponentiation, b must be integer and more than 1  ");
    puts("Notice: for factorial, a must be integer and more than 1  ");

    scanf(" %f",&a);
    scanf(" %c",&oper);
    scanf(" %f",&b);

switch (oper) {
    case'+':                /* finds a+b */
        result = a + b;
        break;
    case'-':                /* finds a-b */
        result = a - b;
        break;
    case'*':                /* finds a*b */
        result = a * b;
        break;
    case'/':                /* finds a/b */
       if(b != 0) result = a / b;
       else puts("error: b = 0");
       break;
    case'^':        /* finds а^b, if b < 1 prints "error" */
        count = 0;
        if (b > 1) {
         while (count != b) {
            count = count + 1;
            pre = pre*a;
        }
    result = pre; }
        else puts("error");
    break;
    case'!':                /* finds а factorial, if а < 1 - prints "error" */
        count = 1;
        if (a > 1)  {
        while (count != a) {
            count = count + 1;
            pre = pre*count;
        }
        result = pre;
        }
        else puts("error");
    break;
}


    printf(" %f",result);
    return EXIT_SUCCESS;
}
