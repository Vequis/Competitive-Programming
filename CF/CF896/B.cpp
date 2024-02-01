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

signed main(){_

    int t;
    cin >> t;

    while(t--) {

        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vii cities(n+1);

        for(int i = 1; i <=n; i++) {
            int x, y;
            cin >> x >> y;
            cities[i] = {x, y};
        }

        int resp = abs(cities[a].fs - cities[b].fs) +  abs(cities[a].sc - cities[b].sc);

        int mina = INF;
        int minb = INF;

        mina*=1000;
        minb*=1000;
        // cout << resp << endl;
        for(int i = 1; i <= k; i++) {
            int dista = (abs(cities[a].fs - cities[i].fs) +  abs(cities[a].sc - cities[i].sc));

            if(dista < mina) mina = dista;

            int distb = (abs(cities[b].fs - cities[i].fs) +  abs(cities[b].sc - cities[i].sc));

            if(distb < minb) minb = distb;
        }

        resp = min(resp, mina + minb);

        cout << resp << endl;
    }

    return 0;
}
