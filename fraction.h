#ifndef __FRACTION_H__
#define __FRACTION_H__

typedef struct
{
	int numerator;
	int denominator;
} Fraction;

double fraction_todouble(Fraction *f);
void fraction_reduce(Fraction *f);
void fraction_add(Fraction *f0, Fraction *f1);
void fraction_sub(Fraction *f0, Fraction *f1);
void fraction_mul(Fraction *f0, Fraction *f1);
void fraction_div(Fraction *f0, Fraction *f1);
void fraction_common_denominator(Fraction *f0, Fraction *f1);
int gcd(int n, int m);

#endif /* __FRACTION_H__ */
