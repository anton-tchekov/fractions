#include "fraction.h"

double fraction_todouble(Fraction *f)
{
	return (double)f->numerator / (double)f->denominator;
}

void fraction_reduce(Fraction *f)
{
	int d = gcd(f->numerator, f->denominator);
	f->numerator /= d;
	f->denominator /= d;
}

void fraction_add(Fraction *f0, Fraction *f1)
{
	fraction_common_denominator(f0, f1);
	f0->numerator += f1->numerator;
	fraction_reduce(f0);
}

void fraction_sub(Fraction *f0, Fraction *f1)
{
	fraction_common_denominator(f0, f1);
	f0->numerator -= f1->numerator;
	fraction_reduce(f0);
}

void fraction_mul(Fraction *f0, Fraction *f1)
{
	f0->numerator *= f1->numerator;
	f0->denominator *= f1->denominator;
	fraction_reduce(f0);
}

void fraction_div(Fraction *f0, Fraction *f1)
{
	f0->numerator *= f1->denominator;
	f0->denominator *= f1->numerator;
	fraction_reduce(f0);
}

void fraction_common_denominator(Fraction *f0, Fraction *f1)
{
	f0->numerator *= f1->denominator;
	f1->numerator *= f0->denominator;
	f0->denominator *= f1->denominator;
	f1->denominator = f0->denominator;
}

int gcd(int n, int m)
{
	int r;

	if(n == 0 && m == 0)
	{
		return -1;
	}

	if(n < 0)
	{
		n = -n;
	}

	if(m < 0)
	{
		m = -m;
	}

	while(m)
	{
		r = n % m;
		n = m;
		m = r;
	}

	return n;
}
