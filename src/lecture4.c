#include <math.h>
#include <stdio.h>
/*int exercise4_1(void) {
  int i = 0, power = 1;

  while (i++ <= 10)
    printf("%5d", power = power * 2);
  printf("\n");

  return 0;
} */

int exercise4_1(void) {
  int i = 0, power = 1;

  while (i < 10) {
    i++;
    printf("%5d", power *= 2);
  }
  printf("\n");

  return 0;
}

/*
 * i
 * 1 2 3 4  5  6  7   8   9   10
 * power
 * 2 4 8 16 32 64 128 256 512 1028
 */

/*
 * When ++i is used ++ happens first therefore pricely iterations happens
 * otherwise when i++ is used one extra iteration will happen,
 * meaning the condiction < gets used on 1++ and = gets used when ++1 is used
 * The computer sees it like this:
 * while -> add 1 to i -> less than or equal to 10 -> true
 * happens 10 times then it return false
 * if i ++ then the comouter ses this:
 * while -> 0 is less than or equal to 10 -> add 1 -> true
 * happens 11 times because i starts at 0 instead because the incremention
 * happens later than the compareson
 * */

/*
 * I denne opgave gives tre positive heltal m, n og k, hvor k er større end 1.
 * Skriv et program der adderer alle heltal mellem m og n (begge inklusive) hvor
 * i k går op.
 */

// Hvis m er 5, n er 13 og k er 3 er resultatet 6 + 9 + 12 = 27.
// Hvis m er 5, n er 10 og k er 5 er resultatet 5 + 10 = 15.
// Hvis m er 10, n er 5 og k er 3 ønsker vi at resultatet er 0, idet m er større
// end n.

int exercise4_2(unsigned int m, unsigned int n, unsigned int k) {
  // When n is greater than m list from m to n
  // When m is greater than n list from n to m
  // Add all the numbers where % to k is 0

  // unsigned int m = 5, n = 13, k = 3;
  //  Tjek om k er gyldigt (skal være større end 1)
  if (k <= 1) {
    printf("ERROR\n");
    return 0;
  }

  unsigned int sum = 0;

  // Tjek om m > n (special case)
  if (m > n) {
    printf("%u\n", sum); // Print 0
    return 0;
  }

  // Loop fra m til n (begge inklusive)
  for (unsigned int i = m; i <= n; i++) {
    if (i % k == 0) { // Hvis k går op i i (ingen rest)
      sum += i;
    }
  }

  printf("%u\n", sum);
  return 0;
}

int exercise4_3(int n) {
  int sum = 0;

  if (n < 0) {
    // n er negativ:  addér fra 2*n til n
    // Eksempel: n=-5, så fra -10 til -5
    for (int i = n * 2; i <= n; i++) {
      sum += i;
    }
  } else {
    // n er ikke negativ: addér fra n til 2*n
    // Eksempel: n=5, så fra 5 til 10
    for (int i = n; i <= n * 2; i++) {
      sum += i;
    }
  }

  return sum;
}

// TEMPLATE using PNM portable anymap
/*int exercise4_4(void) {

  FILE *image_file; // The file on which to write the image
  int i, j;

  image_file = fopen("image-file-1.pnm", "wb"); // Open a file for writing.

  fputs("P6\n", image_file);      // Write the header, including the
                                  // so-called magic number P6
  fputs("500 500\n", image_file); // Width: 500, Height: 500
  fputs("255\n", image_file);     // 255 colors per byte.

  for (i = 0; i < 500; i++)
    for (j = 0; j < 500; j++) {
      fputc(255, image_file); // Writing the red byte
      fputc(0, image_file);   // Write the green byte
      fputc(0, image_file);   // Write the blue byte
    }

  fclose(image_file); // Close the file.
  return 0;
} */

// MOUSE DRAWING using PPM Portable pixelmap used only for colors
int exercise4_4(void) {
  FILE *image_file;
  int i, j;
  int width = 500, height = 500;

  image_file = fopen("cat.ppm", "wb");

  /* PPM header */
  fprintf(image_file, "P6\n%d %d\n255\n", width, height);

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      int x = j - 250; /* Center coordinates */
      int y = i - 250;

      unsigned char r = 255, g = 255, b = 255; /* Default:  white background */

      /* Cat's head (circle) */
      if (x * x + y * y < 150 * 150) {
        r = 255;
        g = 200;
        b = 100; /* Orange cat */
      }

      /* Left ear (triangle) */
      if (x > -180 && x < -100 && y > -250 && y < -150 &&
          (y + 250) < -1.5 * (x + 180)) {
        r = 255;
        g = 200;
        b = 100;
      }

      /* Right ear (triangle) */
      if (x > 100 && x < 180 && y > -250 && y < -150 &&
          (y + 250) < 1.5 * (x - 180)) {
        r = 255;
        g = 200;
        b = 100;
      }

      /* Left eye */
      if ((x + 60) * (x + 60) + (y + 30) * (y + 30) < 25 * 25) {
        r = 0;
        g = 0;
        b = 0; /* Black */
      }

      /* Right eye */
      if ((x - 60) * (x - 60) + (y + 30) * (y + 30) < 25 * 25) {
        r = 0;
        g = 0;
        b = 0; /* Black */
      }

      /* Eye pupils (green) */
      if ((x + 60) * (x + 60) + (y + 30) * (y + 30) < 12 * 12) {
        r = 0;
        g = 255;
        b = 0; /* Green eyes */
      }
      if ((x - 60) * (x - 60) + (y + 30) * (y + 30) < 12 * 12) {
        r = 0;
        g = 255;
        b = 0;
      }

      /* Nose (small triangle) */
      if (x > -15 && x < 15 && y > 50 && y < 80 && fabs(x) < (80 - y) / 2) {
        r = 255;
        g = 150;
        b = 150; /* Pink nose */
      }

      /* Mouth - left side */
      if (x > -60 && x < 0 && y > 80 && y < 120 &&
          fabs(y - 80) < fabs(x + 30) / 2) {
        r = 0;
        g = 0;
        b = 0;
      }

      /* Mouth - right side */
      if (x > 0 && x < 60 && y > 80 && y < 120 &&
          fabs(y - 80) < fabs(x - 30) / 2) {
        r = 0;
        g = 0;
        b = 0;
      }

      /* Whiskers (left) */
      if ((fabs(y) < 2 && x > -250 && x < -150) ||
          (fabs(y - 20) < 2 && x > -250 && x < -150) ||
          (fabs(y + 20) < 2 && x > -250 && x < -150)) {
        r = 50;
        g = 50;
        b = 50;
      }

      /* Whiskers (right) */
      if ((fabs(y) < 2 && x > 150 && x < 250) ||
          (fabs(y - 20) < 2 && x > 150 && x < 250) ||
          (fabs(y + 20) < 2 && x > 150 && x < 250)) {
        r = 50;
        g = 50;
        b = 50;
      }

      fputc(r, image_file);
      fputc(g, image_file);
      fputc(b, image_file);
    }
  }

  fclose(image_file);
  printf("Cat image created as cat.ppm\n");
  return 0;
}

/*
 * simplyfied Euclids algorithm
 * Understand the thing.
 */

int exercise4_5(void) {
  // First one!
  /*
   * - Explicit sorting using ternary operators
   * - Better variable naming (small and large vs i and j)
   * - Trade-off: More code upfront, but semantically clearer
   */
  int i, j, small, large, remainder;

  printf("Enter two positive integers: ");
  scanf("%d %d", &i, &j);

  small = i <= j ? i : j;
  large = i <= j ? j : i;

  while (small > 0) {
    remainder = large % small;
    large = small;
    small = remainder;
  }

  printf("GCD of %d and %d is %d\n\n", i, j, large);

  return 0;
}

int exercise4_5V2() {
  // second one!
  /*
   * Assumes no order - works regardless of which number is larger Works
   * because: Euclid's algorithm naturally handles the case where a < b by
   * swapping them in the first iteration
   *  If a = 12,
   *  b = 18 : First iteration sets i = 18, j = 12 (effectively swapping them)
   */
  int a, b, i, j, remainder;

  printf("Enter two non-negative integers: ");
  scanf("%d %d", &a, &b);

  i = a;
  j = b; /* We don't know if i > j */
  while (j > 0) {
    remainder = i % j;
    i = j;
    j = remainder;
  }

  printf("GCD of %d and %d is %d\n\n", a, b, i);

  return 0;
}

// Greatest common divisor
int exercise4_6(void) {
  unsigned int num1, num2, original1, original2, temp;

  printf("Enter two positive integers: ");
  scanf("%u %u", &num1, &num2);

  // Save original values for printing
  original1 = num1;
  original2 = num2;

  // Euclidean algorithm
  // V1
  /*
  while (num2 != 0) {
    temp = num2;
    num2 = num1 % num2;
    num1 = temp;
  }
  */
  // V2
  while (num1 != num2) {
    if (num1 > num2)
      num1 -= num2;
    else
      num2 -= num1;
  }
  /*
  // V3 - Stein's algorithm (Binary GCD)
  if (num1 == 0) {
    num1 = num2;
  } else if (num2 != 0) {
    unsigned int shift = 0;

    // Remove common factors of 2
    while (((num1 | num2) & 1) == 0) {
      num1 >>= 1;
      num2 >>= 1;
      shift++;
    }

    // Remove remaining factors of 2 from num1
    while ((num1 & 1) == 0)
      num1 >>= 1;

    while (num2 != 0) {
      // Remove factors of 2 from num2
      while ((num2 & 1) == 0)
        num2 >>= 1;

      // Ensure num1 <= num2
      if (num1 > num2) {
        unsigned int temp = num1;
        num1 = num2;
        num2 = temp;
      }

      num2 -= num1;
    }

    num1 <<= shift; // Restore common factors of 2
  }
  */

  printf("GCD of %u and %u is %u\n\n", original1, original2, num1);

  return 0;
}

// with recursion:
int gcd(int a, int b) {
  if (b < 0) {
    return gcd(-b, a);
  }
  if (b == 0) {
    return gcd(b, a % b);
  }
  return 0;
}
