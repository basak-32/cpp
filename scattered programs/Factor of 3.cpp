#include<stdio.h>
#include<stdlib.h>


int main() {
	int t, i, j;
	long int n;
	int k, l, pairs = 0;
	
	printf("Enter t: ");
	scanf("%d", &t);
	
	for (i = 0; i < t; i++) {
		printf("Enter size of array: ");
		scanf("%ld", &n);
		
		int *arr = (int *)malloc(sizeof(long int)*n);
		
		for (j = 0; j < n; j++) {
			scanf("%ld", &arr[j]);
		}
		
		if (n == 2) {
			if ((arr[0] + arr[1]) % 3 == 0) {
				printf("No");
			} else {
				printf("Yes");
			}
		}

		
		for (k = 0; k < n - 1; k++) {
			for (l = k + 1; l < n; l++) {
				if ((arr[k] + arr[l]) % 3 == 0) {
					pairs++;
				}
			}
		}
		
		if (n % 2 != 0) {
			if (pairs <= (n / 2) + 1) {
				printf("Yes");
			} else {
				printf("No");
			}
		} else {
			if (pairs <= n / 2) {
				printf("Yes");
			} else {
				printf("No");
			}
		}
		
		free(arr);
	}
	
	
}
