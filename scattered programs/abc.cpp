#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

int main() {
	char str1[10], str2[10];
	
	strcpy(str1, "twenty ");
	strcpy(str2, "three");
	
	printf("%s", strcat(str1, str2));
}
