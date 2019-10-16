#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binary_search(vector<int> &v, int low, int high, int target) {
	if (low <= high) {
		int mid = (low + high) / 2;
		if (v[mid] == target)
			cout << "Target Found!!!";
		else if (v[mid] > target)
			binary_search(v, low, mid - 1, target);
		else 
			binary_search(v, mid + 1, high, target);
	}
	else cout << "Number not found :(";
}

void string_binary_search(vector<string> &vv, int low, int high, string target) {
	if (low <= high) {
		int mid = (low + high) / 2;
		if (vv[mid] == target)
			cout << "Target Found!!!";
		else if (vv[mid] > target)
			string_binary_search(vv, low, mid - 1, target);
		else
			string_binary_search(vv, mid + 1, high, target);
	}
	else cout << "Number not found :(";
}
int main()
{
	vector<int> v;
	int x;
	vector<string> vv;
	string s;
	int choice;
	cout << "Want to search in \n1.array of string or\n2.array of numbers?: ";
	cin >> choice;
	if (choice == 2) {
		cout << "Enter number of elements:";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int target;
		cout << "Enter target integer to search:";
		cin >> target;
		binary_search(v, 0, n - 1, target);
	}
	else {
		cout << "Enter different strings including spaces, press enter after successive distinct strings\n ";
		cout << "Type '.' to terminate\n";
		while (true) {
			cin >> s;
			if (s != ".")
				vv.push_back(s);
			else
				break;
		}
		
		cout << "Enter target string to search :";
		cin >> s;
		sort(vv.begin(), vv.end());
		string_binary_search(vv, 0, vv.size() - 1, s);

	}
	return 0;
}
