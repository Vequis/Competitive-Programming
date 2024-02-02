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
#define MODN 998244353
#define int long long

using namespace std;

int accum[312345];
int simple[312345];
int sum[312345];
int a[312345];

int neg(int a) {
    int itr = 0;
    while((1<<itr) - 1 < a) {
        itr++;
    }

    return (1<<itr) - 1 - a;
}

int xord(int a, int b) {
    return neg(a)*b + neg(b)*a;
}

signed main(){_

    int n;
    cin >> n;

    cout << xord(1, 1) << endl;
    cout << (1LL xor 1LL) << endl;

    for(int i =0; i < n; i++) cin >> a[i+1];

    simple[1] = a[1];
    accum[1] = a[1];
    sum[1] = a[1];

    for(int i = 2; i <=n; i++) {
        accum[i] = xord((accum[i-1] + simple[i-1]), a[i]) + a[i];
        simple[i] = xord(simple[i-1], a[i]) + a[i];
        sum[i] = sum[i-1] + accum[i];
        cout << sum[i] << endl;
    }
    cout << sum[n] << endl;

    return 0;
}
