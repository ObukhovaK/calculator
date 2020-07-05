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



int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

int vl, i;                           /* vl - vector length */
float a,b,result,count,pre;       /* a,b - numbers, count - counter, pre - preliminary result*/
char oper, go, type;                          /*oper - operand, go - starts/restarts calculator,
                                                type - chooses vector of numeral operations   */
float *v1, *v2;                   /* vectors */
    pre = 1;


    printf("Press 'g' to start");
    scanf(" %c", &go);
    if (go == 'g') {
    printf("for numbers operations press 'n', for vectors press 'v'");
    scanf(" %c", &type);

if (type == 'n') {          // start numbers operation block

    printf("Enter a, operand, b. \n");
    printf(" Acceptable operands: +, -, *, /, ^, ! \n");
    printf(" Notice: for exponentiation, b must be integer and more than 1  \n");
    printf(" Notice: for factorial, a must be integer and more than 1  \n");

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
    case'!':                /* finds а factorial, if а < 1  prints "error" */
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
        puts(" = ");
        printf(" %f",result);
        } // end numbers operations block

else if (type == 'v') {     // start vector operations block
            printf("Enter vectors length ");
            scanf(" %i", &vl);
            v1 = malloc(vl*sizeof(int));
            v2 = malloc(vl*sizeof(int));

            printf("Enter vector 1 \n");
                for (i = 0; i < vl; i++) {
                    scanf(" %f", &v1[i]);
                }
            printf("Enter vector 2 \n");
            for (i = 0; i < vl; i++) {
                scanf(" %f", &v2[i]);
               }
            printf("Enter operand \n");
            printf(" Acceptable operands: +, -, * \n");
            scanf(" %c", &oper);

 switch(oper) {
 case'+':                           /* finds (v1 + v2) */
     for (i = 0; i < vl; i++) {
         printf("%f ", v1[i] + v2[i]);
     }
     break;
 case'-':                           /* finds (v1 - v2) */
     for (i = 0; i < vl; i++) {
         printf("%f ", v1[i] - v2[i]);
     }
     break;
 case'*':
      for (i = 0; i < vl; i++) {
          printf("%f ", v1[i] * v2[i]);  /* finds (v1 * v2) */
     }
     break;
 }   // end switch case
        } // end vectors operations block

}
free(v1);
free(v2);
    return EXIT_SUCCESS;
}

