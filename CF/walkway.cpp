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
        int n, m, d;
        cin >> n >> m >> d;

        int pos[112345];

        for(int i = 1; i <= m; i++) {
            cin >> pos[i];
        }

        pos[0] = 1;
        pos[m+1] = n+1;

        int soma = (pos[1] != 1);

        for(int i = 1; i <= m+1; i++) {
            // cout << soma << endl;
            soma += (pos[i] - pos[i-1] - 1)/d + 1;
        } 
        soma--; //caso final

        map<int, int> f;

        int resp = INF;

        // cout << soma << endl;

        for(int i = 1; i<= m; i++) {
            int somat = soma;
            if(pos[i] == 1) somat++;
            somat -= (pos[i] - pos[i-1] -1)/d + 1;
            somat -= (pos[i+1] - pos[i] -1)/d + 1;
            somat += (pos[i+1] - pos[i-1] - 1)/d + 1;

            // cout << i << ' ' << somat << endl;

            resp = min(resp, somat);
            f[somat]++;
        }

        cout << resp << ' ' << f[resp] << endl;


        f.clear();

    }

    return 0;
}
