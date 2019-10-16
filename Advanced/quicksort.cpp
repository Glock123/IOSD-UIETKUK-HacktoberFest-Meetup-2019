#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(vector<int> &v, int low, int high) {
	int ref = high;
	int piv_index = low-1;
	for (int i = low; i <= high-1; i++) {
		if (v[ref] > v[i]) {
			piv_index++;
			swap(&v[piv_index], &v[i]);
		}
	}
	swap(&v[piv_index+1], &v[ref]);
	return piv_index+1;
}

void quicksort(vector<int> &v, int low, int high) {
	if (low < high) {
		int part = partition(v, low, high);
		quicksort(v, low, part - 1);
		quicksort(v, part + 1, high);

	}
}
int main()
{
	vector<int> v;
	int n, x;
	cout << "Enter number of elements:";
	cin >> n;
	cout << "Enter numbers:\n";
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	quicksort(v, 0, n-1);
	cout << "\nSorted array is:\n";
	for (int i = 0; i < n; i++) {
		cout << v[i] << "  ";
	}
	return 0;
}
