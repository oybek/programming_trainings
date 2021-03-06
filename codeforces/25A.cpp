
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int main() {
	int n, t, oddn = 0, evenn = 0, oddi, eveni;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		if (t%2) {
			++oddn;
			oddi = i;
		} else {
			++evenn;
			eveni = i;
		}
	}
	cout << (oddn == 1 ? oddi : eveni);

	return 0;
}

