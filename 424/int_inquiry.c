/* 
 * Problem 424: Integer Inquiry
 * Positive bignum addition.
 */

#include <stdio.h>
#include <string.h>

#define MAXDIGITS 104           /* maximum length of a bignum */
#define MAXLINES  100           /* maximum lines of input */

#define TRUE 1
#define FALSE 0

typedef struct {
  char digits[MAXDIGITS];     /* represent the number, [0] least significant */
  int lastdigit;              /* index of high-order digit, 0 started */
} Bignum;

typedef struct {
  char digits[MAXDIGITS];
  int lastdigit;
} Big_end_bignum;

/*================================================================
 * GLOBAL DATA
 *================================================================*/
static Bignum n[MAXLINES];
static Big_end_bignum tmp;
static Bignum r;                /* result */
static int carry;

void
print_bignum(Bignum* b)
{
  int j;
  for (j = b->lastdigit; j >= 0; j--) {
    putchar(b->digits[j] + '0');
  }
  putchar('\n');
}

void
init_all_bignums()
{
  int i;
  for (i = 0; i < MAXLINES; i++) {
      memset(n[i].digits, 0, MAXDIGITS);
      n[i].lastdigit = 0;
  }
}

/* void print_all_bignums() */
/* { */
/*   int i = 0; */
/*   int j; */
/*   while (i < MAXLINES && n[i].lastdigit != 0) { */
/*     print_bignum(&n[i++]); */
/*   } */
/* } */

int
readin_big_end_bignum(Big_end_bignum* a)
{
  int c;
  int j = 0;
  while ((c = getchar()) != EOF) {
    if (j == 0 && c == '0') {   /* no valid input */
      return FALSE;
    } else if (c == '\n') {     /* end of input of a whole bignum */
      a->lastdigit = j - 1;
      return TRUE;
    } else {
      a->digits[j++] = c - '0';
    }
  }
  return FALSE;
}

void
big_end_to_little_end(Big_end_bignum* a, Bignum* b)
{
  int i;
  int j;
  b->lastdigit = a->lastdigit;
  for (i = a->lastdigit, j = 0; i >= 0 && j < MAXDIGITS; i--, j++) {
    b->digits[j] = a->digits[i];
  }
}

int
main(int argc, char* argv[])
{
  int i = 0;                    /* index of Bignums */
  int j = 0;                    /* index of digits of a Bignum */
  int count = 0;
  int t = 0;

  init_all_bignums();

  /* read all the input bignums */
  while (readin_big_end_bignum(&tmp)) {
    big_end_to_little_end(&tmp, &n[i++]);
  }
  count = i;

  /* print_all_bignums(); */

  /* add on all the Bignums */
  for (j = 0; j < MAXDIGITS; j++) {
    for (i = 0, t = 0; i < count; i++) {
      t += n[i].digits[j];
    }
    t += carry;
    carry = t / 10;
    r.digits[j] = t % 10;
  }
  for (j = MAXDIGITS - 1; j >= 0; j--) {
    if (r.digits[j] != 0) {
      r.lastdigit = j;
      break;
    }
  }

  print_bignum(&r);

  return 0;
}
