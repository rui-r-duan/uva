#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024
typedef char String[MAX_LINE];

typedef enum PowerVarType_ {
  ePower,
  eVoltage,
  eCurrent
} PowerVarType;

double get_val(PowerVarType type, const char *str)
{
  double v;
  double scale = 1.0;
  char prefix;
  const char *p = str;
  char unit;

  v = atof(str);

  switch (type) {
  case ePower:
    unit = 'W';
    break;
  case eVoltage:
    unit = 'V';
    break;
  case eCurrent:
    unit = 'A';
    break;
  default:
    break;
  }

  while (*p != unit) {
    ++p;
  }
  prefix = *(p - 1);

  switch (prefix) {
  case 'm':
    scale = 0.001;
    break;
  case 'k':
    scale = 1000;
    break;
  case 'M':
    scale = 1000000;
    break;
  default:
    break;
  }

  return v * scale;
}

/* Return calculation target type. */
PowerVarType
parse_line(String line,
	   double *power,
	   double *voltage,
	   double *current)
{
  PowerVarType target_type = ePower;

  char *p = strstr(line, "P=");
  char *u = strstr(line, "U=");
  char *i = strstr(line, "I=");

  if (NULL == p) {
    target_type = ePower;
    *voltage = get_val(eVoltage, u + 2);
    *current = get_val(eCurrent, i + 2);
  } else if (NULL == u) {
    target_type = eVoltage;
    *power = get_val(ePower, p + 2);
    *current = get_val(eCurrent, i + 2);
  } else if (NULL == i) {
    target_type = eCurrent;
    *power = get_val(ePower, p + 2);
    *voltage = get_val(eVoltage, u + 2);
  } else {
  }

  return target_type;
}

int
main(int argc, char *argv[])
{
  int n;
  int i;
  String line;
  double P, U, I;
  PowerVarType target_type;

  scanf("%d\n", &n);

  for (i = 1; i <= n; i++) {
    double val;
    fgets(line, MAX_LINE, stdin);
    target_type = parse_line(line, &P, &U, &I);
    switch (target_type) {
    case ePower:
      P = U * I;
      printf("Problem #%d\n", i);
      printf("P=%.2fW\n\n", P);
      break;
    case eVoltage:
      U = P / I;
      printf("Problem #%d\n", i);
      printf("U=%.2fV\n\n", U);
      break;
    case eCurrent:
      I = P / U;
      printf("Problem #%d\n", i);
      printf("I=%.2fA\n\n", I);
      break;
    default:
      break;
    }
  }
  
  return 0;
}
