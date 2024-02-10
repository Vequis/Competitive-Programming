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

int sweep[112345];
int sweep2[112345];
vector<pair<ii, int>> queries;

int v[112345];

signed main(){_

    int n, m, k;
    cin >> n >> m >>k;

    for(int i = 1; i <=n; i++) {
        cin >> v[i];
    }

    for(int i = 1; i <=m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        queries.eb(make_pair(make_pair(l, r), d));
    }

    for(int i = 1; i <=k; i++) {
        int l, r;
        cin >> l >> r;
        sweep[l]+=1;
        sweep[r+1]-=1;
    }

    int cur = 0;
    for(int i = 1; i <=m; i++) {
        cur += sweep[i];
        // cout << cur << ' ';
        sweep2[queries[i-1].fs.fs] += cur*queries[i-1].sc;
        sweep2[queries[i-1].fs.sc + 1] -= cur*queries[i-1].sc;
    }

    cur= 0;
    for(int i = 1; i <=n; i++) {
        cur += sweep2[i];
        cout << v[i] + cur << ' ';
    }
    cout << endl;

    return 0;
}
