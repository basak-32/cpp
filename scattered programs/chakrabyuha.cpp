#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 

int main() {
	int n, i = 0, j = 0, k, a, b, c, d, count = 1;
	int outersquare;
	int pp = 1;
	
	
	printf("Enter the no of row and column:");
	scanf("%d", &n);
	
	outersquare = n / 2;
	
	int *arr = (int *)malloc(n * n * sizeof(int));
	
	pp = 1 + ((n * n) / 11);
	
	int *powerpointscoordinates = (int *)malloc(pp * 2 * sizeof(int));
	
	a = n;
	b = n;
	c = 0;
	d = 0;
	
	
	for (k = 0; k < outersquare; k++) {
		while (j < a - 1) {
			*(arr + i*n + j) = count;
			if (count % 11 == 0) {
				
			}
			j++;
			count++;
		}
		
		while (i < b - 1) {
			*(arr + i*n + j) = count;
			if (count % 11 == 0) {
				
			}
			i++;
			count++;
		}
		
		while (j > c) {
			*(arr + i*n + j) = count;
			if (count % 11 == 0) {
				
			}
			j--;
			count++;
		}
		
		while (i > d) {
			*(arr + i*n + j) = count;
			if (count % 11 == 0) {
				
			}
			i--;
			count++;
		}
		
		a--;
		b--;
		c++;
		d++;
		
		i++;
		j++;	
	}
	
	
	if (n > 2 && n % 2 !=0) {
		*(arr + outersquare*n + outersquare) = count;
	}
	
	
	for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("%d\t ", *(arr + i*n + j)); 
      }
      printf("\n\n");
   }
   
   free(arr);
   
   printf("Total power points: %d", pp);
}
