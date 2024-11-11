#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<math.h>

double gfun(double g, double p0, double p1, double k, double n, double v, double a, double mas, double h, double z)
{
	return g * ((p0 - p1) / p1) - ((k * n) / (p1 / v)) * (1 + (a * mas / h)) * z;
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	double n = 0.001, p0 = 1000, g = 9.8, a = 0.01;
	double v = 0, s = 0, l = 0, h = 0, p1 = 0, skorost = 0, n1 = 1;
	printf("Введите V, S, l, H, p1, v: \n");
	scanf("%lf %lf %lf %lf %lf %lf", &v, &s, &l, &h, &p1, &skorost);

	int i = 0;
	double mas[25], z0 = 0, t[25], h1, q = 0.001 * abs(h), k = s / l, m1, m2, m3, m4, k1, k2, k3, k4, hh;
	t[0] = 0;
	mas[0] = h;

	while (i < 24)
	{
		hh = mas[i];
		k1 = z0;
		m1 = gfun(g, p0, p1, k, n, v, a, hh, h, z0);
		k2 = z0 + m1 / 2;
		m2 = gfun(g, p0, p1, k, n, v, a, (hh + k1 / 2), h, z0 + m1 / 2);
		k3 = z0 + m2 / 2;
		m3 = gfun(g, p0, p1, k, n, v, a, (hh + k2 / 2), h, z0 + m2 / 2);
		k4 = z0 + m3;
		m4 = gfun(g, p0, p1, k, n, v, a, hh + k3, h, z0 + m3);
		z0 = z0 + (q / 6) * (m1 + 2 * m2 + 2 * m3 + m4);
		mas[i + 1] = hh + (q / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		t[i + 1] = t[i] + q;
		i++;
	}
	printf("\n");
	printf("t = ");
	for (int b = 0; b < 25; b++)
	{
		printf("%lf", t[b]);
	}
	printf("\n");
	printf("\nh = ");
	for (int b = 0; b < 25; b++)
	{
		printf("%lf", mas[b]);
	}
}