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

int mark[112345];
vi primos;

void crivo(int n) {
    primos.pb(2);
    for(int i = 3; i <=n; i+=2) {
        if (!mark[i]) {
            primos.pb(i);
            for(int j = i*i; j<=n; j+=i) mark[j] = 1; 
        }
    }
}

map<vii, int> f;

signed main(){_

    int n;
    cin >> n;
    int k;
    cin >> k;

    crivo(112340);

    int resp = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        vii key;
        vii comp;
        for(int x : primos) {
            if (a == 1) break;
            
            int cnt = 0;
            while(a%x == 0) {
                cnt++;
                a/=x;
            }

            cnt = cnt%k;
            if (cnt != 0) {
                key.eb(x, cnt);
                comp.eb(x, k - cnt);
            }
        }

        resp += f[comp];
        f[key]++;
    }

    cout << resp << endl;

    return 0;
}
