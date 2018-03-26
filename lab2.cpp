#include "stdafx.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> 
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#pragma warning(disable : 4996)

void Simple_Merging_Sort(char *name) {
	int a1, a2, k, i, j, kol, tmp;
	FILE *f, *f1, *f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("\nИсходный файл не может быть прочитан...");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a1);
			kol++;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol) {
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f)) fscanf(f, "%d", &a1);
		while (!feof(f)) {
			for (i = 0; i < k && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf(f, "%d \n", &a1);
				
			}
			for (j = 0; j < k && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d ", &a1);
		if (!feof(f2)) fscanf(f2, "%d ", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {
				if (a1 < a2) {
					fprintf(f, "%d \n", a1);
					fscanf(f1, "%d \n", &a1);
					i++;
				}
				else {
					fprintf(f, "%d \n", a2);
					fscanf(f2, "%d \n", &a2);
					j++;
				}
			}
			while (i < k && !feof(f1)) {
				fprintf(f, "%d \n", a1);
				fscanf(f1, "%d \n", &a1);
				i++;
			}
			while (j < k && !feof(f2)) {
				fprintf(f, "%d \n", a2);
				fscanf(f2, "%d \n", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d \n", a1);
			fscanf(f1, "%d \n", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d \n", a2);
			fscanf(f2, "%d \n", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}



int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	
	ofstream f1;
	f1.open("data.txt");
	
	int f = 0 ;
	cin >> f;
	int *ar = new int[f];
	
	for (int i = 0; i < f; i++)
	{
		ar[i] = rand()%f;
		f1 << ar[i] << endl;
	}

	clock_t start = clock();
	getchar();

	Simple_Merging_Sort("C:\\project\\lab2\\lab2\\data.txt");

	cout << endl << " VREMYA RABOTY" << endl << " ================================== " << endl;
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);


	system("pause");
	return 0;

}

