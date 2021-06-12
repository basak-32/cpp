#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#define MAX 10000

int main() {
	
	int n, sum = 0, q, r, i, temp, pairs = 0, uopairs;
	int arr[100];
	int vowelCount = 0;
	char str1[10], str2[10];
	
//	strcpy(str, "abc");
//	puts(str);
	
	
	bool s[MAX] = { 0 };
	
	printf("Enter the value of n:");
	scanf("%d", &n);
	
	
//	int *arr = malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		s[arr[i]] = 1;
	}
	

	
	for (i = 0; i < n; i++) {
		if (arr[i] >= 10 && arr[i] <= 19) {
			switch(arr[i]) {
				case 10:
					vowelCount += 1;
					break;
				case 11:
					vowelCount += 3;
					break;
				case 12:
					vowelCount += 2;
					break;
				case 13:
					vowelCount += 3;
					break;
				case 14:
					vowelCount += 4;
					break;
				case 15:
					vowelCount += 3;
					break;
				case 16:
					vowelCount += 3;
					break;
				case 17:
					vowelCount += 4;
					break;
				case 18:
					vowelCount += 4;
					break;
				case 19:
					vowelCount += 4;
					break;
				default:
					vowelCount += 0;
			}
		} else {
			q = arr[i] / 10;
		r = arr[i] % 10;
		
		switch(q) {
				case 0:
					vowelCount += 0;
					break;
				case 1:
					vowelCount += 0;
					break;
				case 2:
					vowelCount += 1;
					break;
				case 3:
					vowelCount += 1;
					break;
				case 4:
					vowelCount += 1;
					break;
				case 5:
					vowelCount += 1;
					break;
				case 6:
					vowelCount += 1;
					break;
				case 7:
					vowelCount += 2;
					break;
				case 8:
					vowelCount += 2;
					break;
				case 9:
					vowelCount += 2;
					break;
				case 10:
					vowelCount += 2;
					break;
				default:
					vowelCount += 0;
			}
			
			switch(r) {
				case 0:
					vowelCount += 0;
					break;
				case 1:
					vowelCount += 2;
					break;
				case 2:
					vowelCount += 1;
					break;
				case 3:
					vowelCount += 2;
					break;
				case 4:
					vowelCount += 2;
					break;
				case 5:
					vowelCount += 2;
					break;
				case 6:
					vowelCount += 1;
					break;
				case 7:
					vowelCount += 2;
					break;
				case 8:
					vowelCount += 2;
					break;
				case 9:
					vowelCount += 2;
					break;
				default:
					vowelCount += 0;
			}
		}
	}
	
//	printf("VOwels: %d\n", vowelCount);
	
	for (i = 0; i < n; i++) {
		if (s[vowelCount - arr[i]] == 1) {
			pairs++;
		}
	}
	
	uopairs = pairs / 2;
//	printf("pairs: %d\n", uopairs);
	
	
	if (uopairs >= 10 && uopairs <= 19) {
		switch(uopairs) {
				case 10:
					strcpy(str1, "ten");
					break;
				case 11:
					strcpy(str1, "eleven");
					break;
				case 12:
					strcpy(str1, "twelve");
					break;
				case 13:
					strcpy(str1, "thirteen");
					break;
				case 14:
					strcpy(str1, "fourteen");
					break;
				case 15:
					strcpy(str1, "fifteen");
					break;
				case 16:
					strcpy(str1, "sixteen");
					break;
				case 17:
					strcpy(str1, "seventeen");
					break;
				case 18:
					strcpy(str1, "eighteen");
					break;
				case 19:
					strcpy(str1, "nineteen");
					break;
				default:
					strcpy(str1, "");
			}
	} else {
		q = uopairs / 10;
	r = uopairs % 10;
	
	switch(q) {
				case 0:
					strcpy(str2, "");
					break;
				case 1:
					strcpy(str2, "");
					break;
				case 2:
					strcpy(str2, "twenty ");
					break;
				case 3:
					strcpy(str2, "thirty ");
					break;
				case 4:
					strcpy(str2, "forty ");
					break;
				case 5:
					strcpy(str2, "fifty ");
					break;
				case 6:
					strcpy(str2, "sixty ");
					break;
				case 7:
					strcpy(str2, "seventy ");
					break;
				case 8:
					strcpy(str2, "eighty ");
					break;
				case 9:
					strcpy(str2, "ninety ");
					break;
				case 10:
					strcpy(str2, "hundred ");
					break;
				default:
					strcpy(str2, " ");
			}
			
			switch(r) {
				case 0:
				strcpy(str1, "zero");
					break;
				case 1:
					strcpy(str1, "one");
					break;
				case 2:
					strcpy(str1, "two");
					break;
				case 3:
					strcpy(str1, "three");
					break;
				case 4:
					strcpy(str1, "four");
					break;
				case 5:
					strcpy(str1, "five");
					break;
				case 6:
					strcpy(str1, "six");
					break;
				case 7:
					strcpy(str1, "seven");
					break;
				case 8:
					strcpy(str1, "eight");
					break;
				case 9:
					strcpy(str1, "nine");
					break;
				default:
					strcpy(str1, "");
			}
	}
	
	if (uopairs <= 19) {
		printf("%s", str1);
	} else {
		printf("%s", strcat(str2, str1));
	}
}























