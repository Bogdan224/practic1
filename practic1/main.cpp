#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

bool IsPrimeNumber(int x, int y) {
	if (x < 2) {
		return false;
	}
	if (x == 2 || y == 1) {
		return true;
	}
	if (x % y != 0) {
		IsPrimeNumber(x, y-1);
	}
	else
	{
		return false;
	}
}

void Del(int x, int arr[]) {
	int index = 0;
	for (int i = x; i >= 1; i--)
	{
		if (IsPrimeNumber(i, i-1)) {
			if (x % i==0) {
				arr[index] = i;
				index += 1;
			}
		}
	}
}

void Programm() {
	int x;
	int arr[100];
	printf("Enter number more than 0 -------------->>>>>>>");
	scanf_s("%d", &x);
	printf("\n");
	if (x <= 0) {
		printf("Wrong number!!!\n");
		Programm();
	}
	else{
	    Del(x, arr);
		for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (arr[i] < 0) {
				break;
			}
			printf("%d ", arr[i]);
		}
	}
	return;
}

int main() {	
	Programm();
	return 0;
}