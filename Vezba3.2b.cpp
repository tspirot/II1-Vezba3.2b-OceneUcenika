// Vezba3.2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
// KORISNIK UNOSI BROJ UCENIKA I PREDMETA A ZATIM
// NJIHOVE OCENE, UCENIK PO UCENIK
// PRIKAZATI POSECENE OCENE UCENIKA
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXUC 35
#define MAXPR 20
int main()
{
	int bruc, brpr;
	int ocene[MAXUC][MAXPR];
	int i, j;
	printf("Unesite broj ucenika (max 35): ");
	scanf("%d", &bruc);
	printf("Unesite broj predmeta (max 20): ");
	scanf("%d", &brpr);
	// Unos matrice ocena
	for (i = 0; i < bruc; i++)
	{
		printf("Unesite ocene za ucenika %d: ", i + 1);
		for (j = 0; j < brpr; j++)
			scanf("%d", &ocene[i][j]);
	}
	// Prikaz matrice ocena
	for (i = 0; i < bruc; i++)
	{
		printf("Ocene za ucenika %d: ", i + 1);
		for (j = 0; j < brpr; j++)
			printf("%d ", ocene[i][j]);
		printf("\n");
	}
	// Prikaz prosecnih ocena ucenika
	float suma;
	float prosek[MAXUC];
	for (i = 0; i < bruc; i++)// 0, 1
	{
		suma = 0;
		for (j = 0; j < brpr; j++)// 0 1 2  0 1 2
			suma += ocene[i][j];
		printf("Prosek za ucenika %d: %.2f\n", 
			i + 1, suma / brpr);
		prosek[i] = suma / brpr;
	}
	// Ucenik sa najvecim prosekom
	float max = prosek[0];
	int poz = 0;
	for (i = 1; i < bruc; i++)
		if (prosek[i] > max)
		{
			max = prosek[i];
			poz = i;
		}
	printf("Ucenik sa najvecim prosekom %.2f je ucenik %d\n", 
		prosek[poz], poz + 1);
}
