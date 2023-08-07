#include <bits/stdc++.h>

using namespace std;
int L[30005];
int n;
int a[1005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= 30000; ++i) {
	    L[i] = -1000000000;
    }
    sort(a+1, a+n+1);
    n = unique(a+1, a+n+1) - a - 1;
    L[(a[1]^a[2])] = a[1] + a[2];
    int res = 0;
    for (int i = 3; i <= n; ++i) {
    	for (int sumxor = 0; sumxor <= 30000; ++sumxor) {
    	    int prexor = (sumxor ^ a[i]);
    	    if (prexor <= 30000)
    	    	res = max(res, L[prexor] + a[i] - sumxor);
    	}
    	for (int j = 1; j <= i-1; ++j) {
    	    L[a[i]^a[j]] = max(L[a[i]^a[j]], a[i] + a[j]);
    	}
    }
    cout << res;
    return 0;
}
