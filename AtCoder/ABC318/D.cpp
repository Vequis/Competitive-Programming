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

vector<pair<int, ii>> v;

int vis[23];

signed main(){_

    int n;
    cin >> n;


    for (int i = 1; i <= n-1; i++) {
        for(int j = i+1; j<=n; j++) {
            int a;
            cin >> a;
            v.push_back({a, {i, j}});
        }
    }

    sort(all(v), greater<pair<int, ii>>());

    int escolhidos = 0;
    int soma = 0;

    int itr = 0;
    while(n - escolhidos >= 2) {
        ii p = v[itr].second;
        if(!vis[p.fs] and !vis[p.sc]) {
            soma += v[itr].first;
            vis[p.fs] = 1;
            vis[p.sc] = 1;
            escolhidos += 2;

            cout << v[itr].first << endl;
        }

        itr++;
    }

    cout << soma << endl;

    return 0;
}
