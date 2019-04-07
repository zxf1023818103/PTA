#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define N 10000

int an, bn, qn, rn;
double a[N], b[N], q[N], r[N], test[N];
int rindices[N], qindices[N], nrindices, nqindices;

int check(double value)
{
	char str[20];
	sprintf(str, "%.1lf", value);
	if (strcmp(str, "0.0") == 0 || strcmp(str, "-0.0") == 0)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int n, index, base;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &index, &base);
		a[index] = base;
		an = max(an, index);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &index, &base);
		b[index] = base;
		bn = max(bn, index);
	}
	
	qn = an - bn;

	rn = qn - 1;
	
	//for (int ri = an; ri >= 0; ri--)
	//{
	//	r[ri] = a[ri];
	//}

	for (int ai = an; ai >= bn; ai--)
	{
		
		int qi = ai - bn;

		//q[qi] = r[ai] / b[bn];
		q[qi] = a[ai] / b[bn];

		for (int bi = bn; bi >= 0; bi--)
		//for (int bi = bn - 1; bi >= 0; bi--)
		{
			//r[qi + bi] -= q[qi] * b[bi];
			a[qi + bi] -= q[qi] * b[bi];
		}
		
	}
	
	for (int qi = qn; qi >= 0; qi--)
	{
		if (check(q[qi]))
		{
			qindices[nqindices++] = qi;
		}
	}

	for (int ri = rn; ri >= 0; ri--)
	{
		//if (check(r[ri]))
		if (check(a[ri]))
		{
			rindices[nrindices++] = ri;
		}
	}

	if (nqindices == 0)
	{
		printf("0 0.0 0\n");
	}
	else
	{
		printf("%d ", nqindices);
		for (int i = 0; i < nqindices; i++)
		{
			printf(i == nqindices - 1 ? "%d %.1lf\n" : "%d %.1lf ", qindices[i], q[qindices[i]]);
		}
	}

	if (nrindices == 0)
	{
		printf("0 0.0 0\n");
	}
	else
	{
		printf("%d ", nrindices);
		for (int i = 0; i < nrindices; i++)
		{
			printf(i == nrindices - 1 ? "%d %.1lf\n" : "%d %.1lf ", rindices[i], a[rindices[i]]);
		}
	}

	return 0;
}
