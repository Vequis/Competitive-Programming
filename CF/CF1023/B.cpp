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

void solve() {
    int n, k;
    cin >> n >> k;

    vi v(n);
    int sum = 0;
    for (int i =0;i <n; i++) cin>>v[i];

    sort(all(v));

    for (int i = 0; i < n; i++) sum+= v[i];
    v[n-1]--;

    sort(all(v));

    if (v[n-1] - v[0] > k) {
        cout << "Jerry" << endl;
        return;
    }   

    if (sum%2) {
        cout << "Tom" << endl;
    } else {
        cout << "Jerry" << endl;
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}