#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, temp, lim;
	vector<int> arr;
	
	cout << "Enter total count: ";
	cin >> n;
	
	cout << "Enter the integers: ";
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	};
	
	for (int i = 1; i < n; i+=2) {
		if (arr[i] > arr[i-1]) {
			temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = temp;
		};
		
		if (arr[i] > arr[i+1] && i < n-1) {
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		};
	};
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	};
};
