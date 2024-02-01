#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int lo, hi, v;
int n, k;

int f(int n) {
    return n*n + 3*n;
}

signed main(){_

    cin >> n >> k;
    v = 2*(n+k);

    lo = 0;
    hi = 112345;

    while(lo < hi) {
        int md = lo + (hi-lo)/2;

        if (v <= f(md)) hi = md;
        else lo = md + 1;
    }

    cout << n - lo << endl;

    return 0;
}
