#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
	int x1, y1;
	int x2, y2;
	int x3, y3;
	float AB, BC, CA;
	float ir, r2, s, area, a1, a2;
	
	printf("Enter 1:");
	scanf("%d %d", &x1, &y1);
	
	printf("Enter 2:");
	scanf("%d %d", &x2, &y2);
	
	printf("Enter 3:");
	scanf("%d %d", &x3, &y3);
	
	area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	if (area == 0) {
		printf("Not Possible");
	} else {
		AB = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		BC = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
		CA = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
		
		s = (AB + BC + CA) / 2;
		ir = sqrt((s - AB)*(s - BC)*(s - CA) / s);
		a1 = 3.14 * pow(ir, 2);
		
		r2 = (AB*BC*CA) / sqrt((AB+BC+CA)*(BC+CA-AB)*(CA+AB-BC)*(AB+BC-CA));
		a2 = 3.14 * pow(r2, 2);
		
		printf("%f", a2-a1);
	}
}
