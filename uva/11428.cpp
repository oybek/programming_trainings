
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define cubes_sz 60
int cubes[cubes_sz];

int main() {
	for (int n = 1; n < cubes_sz; ++n)
		cubes[n] = n*n*n;

	int N;
	while (1) {
		cin >> N;
		if (N == 0)
			break;

		bool solution_found = false;
		for (int * y = cubes+1; y != cubes+cubes_sz; ++y) {
			int * x = lower_bound(cubes, cubes+cubes_sz, N+*y);
			if ((x != cubes+cubes_sz) && (*x == N+*y)) {
				solution_found = true;
				cout << x-cubes << ' ' << y-cubes << endl;
				break;
			}
		}

		if (!solution_found) {
			cout << "No solution\n";
		}
	}

	return 0;
}

