#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "fileio.h"
#include "solve.h"
int main(void)
{	
	float r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, u1 = 0, u2 = 0, i1 = 0, i2 = 0, i3 = 0, ieh = 0, ief = 0, uac = 0, udf = 0, uef = 0, ueh = 0;
	ler(&r1, &r2, &r3, &r4 , &r5 , &u1, &u2 , &i1 , &i2 , &i3 , &ieh , &ief , &uac , &udf , &uef, &ueh);
	solve(&r1, &r2, &r3, &r4, &r5, &u1, &u2, &i1, &i2, &i3, &ieh, &ief, &uac, &udf, &uef, &ueh);
	escrever(&i1, &i2, &i3, &ieh, &ief, &uac, &udf, &uef, &ueh);
	
	return 0;
}
