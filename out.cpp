// #include <iostream>
// #include <vector>
// #include <algorithm>
//
// using namespace std;
//
// void doSum(int& flag, vector<int>& tmp, int target, int begin, int n) {
//     if (target >= 0) {
//         ++flag;
//     } else return;
//     for (int i = begin; i < n && target >= tmp[i]; i++)
//         doSum(flag, tmp, target - tmp[i], i + 1, n);
// }
//
// int main() {
//     int n, w;
//     cin >> n;
//     cin >> w;
//     vector<int> tmp(n);
//     for (int i = 0; i < n; i++)
//         cin >> tmp[i];
//     sort(tmp.begin(), tmp.end());
//     int flag = 0;
//     doSum(flag, tmp, w, 0, n);
//     cout<<flag;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Time
{
	Time(int a, int b):A(a), B(b){C = 60*A+B;}
	int A;
	int B;

	int C;
};

int main(int argc, const char * argv[])
{
	int n;
	cin >> n;
	vector<Time> vec;

	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		Time t(a, b);
		vec.push_back(t);
	}

	int x;
	cin >> x;

	int a, b;
	cin >> a;
	cin >> b;
	Time shangke(a, b);

	int diff = INT_MAX;
	Time getup(0, 0);
	for(Time t : vec)
	{
		if(shangke.C - t.C < 0)
			continue;
		else if(shangke.C - t.C < diff)
		{
			diff = shangke.C - t.C;
			getup = t;
		}
	}

	cout << getup.A << " " << getup.B << endl;

	return 0;
}
