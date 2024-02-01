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

int mdc(int a, int b) {
    if (a < b) return mdc(b, a);
    if (b == 0) return a;
    return mdc(b, a%b);
}

int answer(int n) {
    if (n%2 == 1) return n/2;

    for (int i = 2; i < n; i++) {
        if (mdc(n, i) == 1) return i;
    }
}

signed main(){_

    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int ans = answer(n-1);

        cout << ans << ' ' << n-ans-1 << ' ' << 1 << endl;
    }

    return 0;
}
