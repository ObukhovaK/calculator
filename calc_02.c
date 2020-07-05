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

FILE *inFile, *outFile;
int vl, i;                           /* vl - vector length */
float a,b,result,count,pre;       /* a,b - numbers, count - counter, pre - preliminary result*/
char oper, go, type;                /*oper - operand, go - starts/restarts calculator,
                                                type - chooses vector of numeral operations   */
float *v1, *v2;                   /* vectors */
char nameIn[20], nameOut[20];
    pre = 1;

printf("Press 'g' to start");
scanf(" %c", &go);
while (go == 'g') {
    inFile = NULL;
    while (inFile == NULL) {          /* opens files, prints "error" if the input file doesn't exist*/
    printf("Enter input file name (20 characters or less):");
    scanf(" %s", &nameIn);
    inFile = fopen(nameIn, "r");
    if (inFile == NULL){
            printf("This file does not exist.\n");
        } else {
            printf("Enter output file name (20 characters or less): ");
            scanf(" %s", nameOut);
            outFile = fopen(nameOut, "w");
        }
    }
    fscanf(inFile, " %c", &oper);
    fscanf(inFile, " %c", &type);

if (type == 'n') {          // start numbers operation block
    fscanf(inFile, " %f", &a);
    fscanf(inFile, " %f", &b);

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
       else fprintf(outFile, "error: b = 0");
       break;
    case'^':        /* finds а^b, if b < 1 prints "error" */
        count = 0;
        if (b > 1) {
         while (count != b) {
            count = count + 1;
            pre = pre*a;
        }
    result = pre; }
        else fprintf(outFile,"error");
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
        else fprintf(outFile,"error");
    break;
    }
        fprintf(outFile, " %f %c %f = ", a, oper, b);
        fprintf(outFile, " %f\n",result);
        } // end numbers operations block

else if (type == 'v') {     // start vector operations block
            fscanf(inFile, " %i", &vl);
            v1 = malloc(vl*sizeof(int));
            v2 = malloc(vl*sizeof(int));
            fprintf(outFile,"( ");
            for (i = 0; i < vl; i++) {    // reads vectors and operation, puts them into output file
                    fscanf(inFile," %f", &v1[i]);
                    fprintf(outFile," %f", v1[i]);
                }
            fprintf(outFile," ) ");
            fprintf(outFile," %c", oper);
            fprintf(outFile," ( ");
            for (i = 0; i < vl; i++) {
                fscanf(inFile," %f", &v2[i]);
                fprintf(outFile," %f", v2[i]);
               }
            fprintf(outFile," )");
 switch(oper) {
 case'+':                           // finds (v1 + v2)
     fprintf(outFile,"( ");
     for (i = 0; i < vl; i++) {
         fprintf(outFile, "%f ", v1[i] + v2[i]);
     }
     fprintf(outFile," )\n");
     break;
 case'-':                           // finds (v1 - v2)
     fprintf(outFile,"( ");
     for (i = 0; i < vl; i++) {
         fprintf(outFile, "%f ", v1[i] - v2[i]);
     }
     fprintf(outFile," )\n");
     break;
 case'*':
     fprintf(outFile,"( ");
      for (i = 0; i < vl; i++) {
          fprintf(outFile, "%f ", v1[i] * v2[i]);  // finds (v1 * v2)
     }
      fprintf(outFile," )\n");
     break;
 }   // end switch case
 free(v1);
 free(v2);
} // end vectors operations block
else {
printf("Input file is incorrect. Please try again.");
}

fclose(inFile);
fclose(outFile);
printf("Press 'g' to restart. Press any other key to exit");
}

    return EXIT_SUCCESS;
}

