#include <math.h>
#include <stdio.h>
#include <string.h>

int exercise3_1(void) {
  // define variables
  double r, x, y;
  double centerDis;

  // input
  printf("input x, y and r:\n");
  scanf("%lf %lf %lf", &y, &x, &r);

  // print værdier
  printf("Radius = %lf\n X = %lf\n Y = %lf\n", r, x, y);

  // centerDis = sqrt(pow(x, 2) + pow(y, 2));
  centerDis = sqrt((x * x) + (y * y));
  printf((centerDis < r)   ? "in Circle"
         : (centerDis > r) ? "Out of Circle"
                           : "in Perferien");

  // mindre eller større end r
  return 0;
}

int exercise3_2(void) {

  int a = 1, b = 2, c = 3;
  double x = 1.0;

  int res1, res2, res3, res4;

  res1 = ((a > b) && (c < x));
  res2 = ((a < (!b)) || (!!a));
  res3 = (((a + b)) < (!(c + c)));
  res4 = (((a - x)) || ((b * c) && (b / a)));

  printf("res1 = %d, res2 = %d, res3 = %d,  res4 = %d \n", res1, res2, res3,
         res4);

  return 0;
}

int exercise3_4() {
  /*
   *  A week has 7 * 24 * 60 * 60 = 604800 seconds.
   *  650 sekunder er 0 uger, 0 dage, 0 timer, 10 minutter og 50 sekunder
   */

  int seconds;
  int sec, min, hours;

  // printf("Please enter a number: ");
  scanf("%d", &seconds);

  /*
   * calculation
   */
  sec = seconds % 60;
  min = (seconds / 60) % 60;
  hours = (seconds / 3600) % 24;
  // printf("*******************************\n");

  printf("%d sekunder er ", seconds);

  if (hours > 0)
    printf("%d hours, ", hours);
  if (min > 0)
    printf("%d minutes, ", min);
  if (sec > 0)
    printf("%d seconds", sec);

  // printf("%d seconds is: %d:%d:%d:%d:%d \n", seconds, week,
  // days, hours,
  // min, sec); printf("*******************************\n");

  return 0;
}

int bouncer(void) {
  int alder; // Erklæring af variabel, der skal indeholde et heltal (brugerens
             // alder).
  printf(
      "Hey du! Jeg skal lige se dit ID? Indtast alder:\n>"); // Bed brugeren om
                                                             // at indtaste
                                                             // alder.
  scanf("%d", &alder); // Indlæs alder fra brugeren.

  if (alder >= 18) {
    printf("kom bare ind du!");
  } else {
    printf("Beklager, ikke i dag makker.\n");
  }

  return 0;
}
