#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

void solve(float* r1, float* r2, float* r3, float* r4, float* r5, float* u1, float* u2, float* i1, float* i2, float* i3, float* ieh, float* ief, float* uac, float* udf, float* uef, float* ueh)
{
	float numerador = (*r3 * *u1 * *r4) + (*u1 * *r4 * *r2) - (*u2 * *r4 * *r2) + (*r3 * *u2 * *r1);
	float denominador = (*r3 * *r4 * *r5) + (*r3 * *r5 * *r1) + (*r3 * *r4 * *r1) + (*r5 * *r4 * *r2) + (*r3 * *r4 * *r2) + (*r5 * *r2 * *r1) + (*r4 * *r2 * *r1) + (*r3 * *r2 * *r1);
	*i3 = numerador / denominador;
	*i2 = ((*u2 + *i3 * *r3) / (*r2 + *r3));
	*i1 = ((*u1 - *u2 + (*i3 * *r4)) / (*r1 + *r4)) * -1;
	*ieh = *i1 + *i3;
	*ief = *i3 - *i2;
	*uac = *r1 * *i1;
	*udf = *r2 * *i2;
	*uef = *r3 * *ief;
	*ueh = *r4 * *ieh;
	
}