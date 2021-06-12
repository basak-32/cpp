#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int main () {
	int n, s;
	char brides[10];
	
	printf("Enter the no of brides: ");
	scanf("%d", &n);
	
	printf("Enter the brides: ");
	scanf("%s", brides);
	
	s = sizeof(brides);
	
	printf("Size: %d", s);
}
