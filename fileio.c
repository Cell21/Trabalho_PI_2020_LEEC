#define _CRT_SECURE_NO_WARNINGS
#define MAXCHAR 1000
#include <stdio.h>
#include <math.h>
#include <string.h>



void ler(float  *r1, float *r2, float *r3, float *r4, float *r5, float *u1, float *u2, float *i1, float *i2, float *i3, float *ieh, float *ief, float *uac, float *udf, float *uef, float *ueh)
{
	int x = 0;
	
	FILE* fp;
	char str[MAXCHAR];

	struct {
		char nome[20], letra1, letra2;
		float valor;
	}elemento[10];

	

	

	//abre o ficheiro e efetua alguns processos como: tirar os nos e os valores das tensoes e resistencias
	char* filename = "C:\\Users\\Celestino\\Desktop\\Tudo\\Universidade\\PI\\Circuito.txt";
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s", filename);
		return 1;
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		//extrai os dados do ficheiro para a estrutura elementos
		if (str[0] != 'C' && strcmp(str, ".end") != 0)
		{
			
			sscanf(str, "%s %c %c %f\n", elemento[x].nome, &elemento[x].letra1, &elemento[x].letra2, &elemento[x].valor);
			if (x != 0)
				printf("%s %c %c %f \n", elemento[x].nome, elemento[x].letra1, elemento[x].letra2, elemento[x].valor);
			x++;
			
		}

	}
	fclose(fp);
	//SOLVE.C TENHO DE METER LÁ
	for (int i = 0; i < 8; i++)
	{
		if ((elemento[i].nome[0] == 'U' || elemento[i].nome[0] == 'u') && elemento[i].letra1 == 'a' && elemento[i].letra2 == 'b')
		{
			*u1 = elemento[i].valor;
			printf("%f %s\n", *u1, elemento[i].nome);
		}
		else if ((elemento[i].nome[0] == 'U' || elemento[i].nome[0] == 'u') && elemento[i].letra1 == 'e' && elemento[i].letra2 == 'c')
		{
			*u2 = elemento[i].valor;
			printf("%f %s\n", *u2, elemento[i].nome);
		}
		else if ((elemento[i].nome[0] == 'R' || elemento[i].nome[0] == 'r') && elemento[i].letra1 == 'a' && elemento[i].letra2 == 'c')
		{
			*r1 = elemento[i].valor;
			printf("%f %s\n", *r1, elemento[i].nome);
		}
		else if ((elemento[i].nome[0] == 'R' || elemento[i].nome[0] == 'r') && elemento[i].letra1 == 'd' && elemento[i].letra2 == 'f')
		{
			*r2 = elemento[i].valor;
			printf("%f %s\n", *r2, elemento[i].nome);
		}
		else if ((elemento[i].nome[0] == 'R' || elemento[i].nome[0] == 'r') && elemento[i].letra1 == 'f' && elemento[i].letra2 == 'e')
		{
			*r3 = elemento[i].valor;
			printf("%f %s\n", *r3, elemento[i].nome);
		}
		else if ((elemento[i].nome[0] == 'R' || elemento[i].nome[0] == 'r') && elemento[i].letra1 == 'e' && elemento[i].letra2 == 'h')
		{
			*r4 = elemento[i].valor;
			printf("%f %s\n", *r4, elemento[i].nome);
		}
		else if ((elemento[i].nome[0] == 'R' || elemento[i].nome[0] == 'r') && elemento[i].letra1 == 'f' && elemento[i].letra2 == 'g')
		{
			*r5 = elemento[i].valor;
			printf("%f %s\n", *r5, elemento[i].nome);
		}

				

	}	
	
	
}


//OUTPUT ABRIR E ESCREVER NO FICHEIRO
void escrever(float* i1, float* i2, float* i3, float* ieh, float* ief, float* uac, float* udf, float* uef, float* ueh)
{
	FILE* of;
	char* filename = "C:\\Users\\Celestino\\Desktop\\Tudo\\Universidade\\PI\\Output.txt";
	of = fopen(filename, "w");
	printf("I1: %f\nI2: %f\nI3: %f\nUAC: %f\nUDF: %f\nUEF: %f\nUEH: %f\nIEH: %f\nIEF: %f\n", *i1, *i2, *i3, *uac, *udf, *uef, *ueh, *ieh, *ief);
	if (of == NULL)
	{
		printf("Could not open file %s", filename);
		return 1;
	}
	else
	{
		fprintf(of, "I1: %f\nI2: %f\nI3: %f\nUAC: %f\nUDF: %f\nUEF: %f\nUEH: %f\nIEH: %f\nIEF: %f\n", *i1, *i2, *i3, *uac, *udf, *uef, *ueh, *ieh, *ief);
	}
	
	fclose(of);
}