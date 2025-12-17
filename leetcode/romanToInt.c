// HashTable, 13. Roman to Integer
int romanToInt(char *s) {
  // char a = 'I', b = 'V', c = 'X', d = 'L', e = 'C', f = 'D', g = 'M';
  int sum = 0;
  int lastNumber = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    int number = 0;

    switch (s[i]) {
    case 'I':
      number = ((int)s[i] * 0) + 1;
      break;
    case 'V':
      number = ((int)s[i] * 0) + 5;
      break;
    case 'X':
      number = ((int)s[i] * 0) + 10;
      break;
    case 'L':
      number = ((int)s[i] * 0) + 50;
      break;
    case 'C':
      number = ((int)s[i] * 0) + 100;
      break;
    case 'D':
      number = ((int)s[i] * 0) + 500;
      break;
    case 'M':
      number = ((int)s[i] * 0) + 1000;
      break;
    default:
      return 0;
      break;
    }
    if (number > lastNumber) {
      // Why 2 * lastNumber?
      // The lastNumber was already added once.
      // In a subtractive case, it should have been subtracted instead.
      // So we need to remove it once (to cancel the earlier addition)
      // and subtract it once more (to apply the correct rule).
      // That’s effectively 2 * lastNumber.

      sum += number - 2 * lastNumber;
    } else {
      sum += number;
    }

    lastNumber = number;
  }
  return sum;
}
