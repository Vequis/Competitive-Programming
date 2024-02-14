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

map<int, int> f;
vector<int> v;

signed main(){_

    int r, g, b;
    cin >> r >> g >> b;

    int resp = 0;
    v.pb(g);
    v.pb(r);
    v.pb(b);
    sort(v.rbegin(), v.rend());
    while(v[1] != 0 and v[0] > 1){
        v[0]-=2;
        v[1]-=1;
        resp++;
        sort(v.rbegin(), v.rend());
    }

    resp += v[2];

    cout << resp << endl;

    return 0;
}
