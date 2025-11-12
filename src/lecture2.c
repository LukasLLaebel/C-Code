#include <stdio.h>

int first();
int second();
int third();
int forth();

int exercise2_1() {
  first();
  //second();
  //third();
  //forth();


}




int first(void) {

  int sum1 =    10  +   11  +  12,
      sum2  =  010 +   011 +  012,
      sum3  = 0x10 +  0x11 + 0x12;

  printf("sum1 =  %d\n", sum1);
  printf("sum2 =  %d\n", sum2);
  printf("sum3 =  %d\n", sum3);

  return 0;
}

int second(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%d %d %d", &x, &y, &z);

  sum =    x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}

int third(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%o %o %o", &x, &y, &z);

  sum =    x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}

int forth(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%o %o %o", &x, &y, &z);

  sum =    x + y + z;

  printf("sum =  %o\n", sum);

  return 0;
}

