#include <stdio.h>

int first();
int second();
int third();
int forth();

int exercise2_1() {
  first();
  // second();
  // third();
  // forth();
  return 0;
}

int first(void) {

  int sum1 = 10 + 11 + 12, sum2 = 010 + 011 + 012, sum3 = 0x10 + 0x11 + 0x12;

  printf("sum1 =  %d\n", sum1);
  printf("sum2 =  %d\n", sum2);
  printf("sum3 =  %d\n", sum3);

  return 0;
}

int second(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%d %d %d", &x, &y, &z);

  sum = x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}

int third(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%o %o %o", &x, &y, &z);

  sum = x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}

int forth(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%o %o %o", &x, &y, &z);

  sum = x + y + z;

  printf("sum =  %o\n", sum);

  return 0;
}

int exercise2_5() {
  /*
   *  A week has 7 * 24 * 60 * 60 = 604800 seconds.
   *  650 sekunder er 0 uger, 0 dage, 0 timer, 10 minutter og 50 sekunder
   */

  int seconds;
  int sec, min, hours, days, week;

  // printf("Please enter a number: ");
  scanf("%d", &seconds);

  /*
   * calculation
   */
  sec = seconds % 60;
  min = (seconds / 60) % 60;
  hours = (seconds / 3600) % 24;
  days = (seconds / 86400) % 7;
  week = seconds / 604800; // full weeks
  // printf("*******************************\n");
  printf(
      "%d sekunder er %d uger, %d dage, %d timer, %d minutter og %d sekunder",
      seconds, week, days, hours, min, sec);
  // printf("%d seconds is: %d:%d:%d:%d:%d \n", seconds, week, days, hours,
  // min, sec); printf("*******************************\n");

  return 0;
}
