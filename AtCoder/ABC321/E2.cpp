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

int n;


int q(int root, int k) {
    int r = root;
    int l = root;

    for(int i = 0; i < k; i++) {
        l = (l<<1);
        r = (r<<1) + 1;
        r = min(n, r);
    }
    if (l > n) return 0;

    return r - l + 1;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int x, k;
        cin >> n >> x >> k;

        int resp = q(x, k);
        int itr = x/2;
        int cnt = 0;
        while( itr > 0) {
            cnt++;

            resp += q(itr, k) - q(x, k - cnt);
        }
    }

    return 0;
}
