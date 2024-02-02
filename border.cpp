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
// #define int long long -> solução divina?

using namespace std;

int mdc(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return (mdc(b, a%b));
}

int main(){_

    int n, k;
    cin >> n >> k;

    int a[112345];

    int resp = k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int var = a[i] % k;

        resp = mdc(resp, var);
    }

    cout << k / resp << endl;
    for (int i = 0; i< k; i++) {
        if (i%resp  == 0) {
            cout << i << ' ';
        }
    }

    return 0;
}
