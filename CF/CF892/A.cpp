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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> v;

        int maior = -1;
        int menor = INT_MAX;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
            f[a]++;
            maior = max(maior, a);
            menor = min(menor, a);
        }


        if(menor == maior) {
            cout << -1 << endl;
        } else {
            cout << n-f[maior] << ' ' << f[maior] << endl;
            for (int i : v) if (i != maior) cout << i << ' ';
            cout << endl; 
            for (int i = 0; i < f[maior]; i++) cout << maior << ' ';
            cout << endl;
        }

        f.clear();
    }


    return 0;
}
