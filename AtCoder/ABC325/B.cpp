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

int w[1123];
int x[1123];

signed main(){_

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        cin >> w[i] >> x[i];
    }

    int resp = 0;

    for(int i = 0; i < 24; i++) {
        int cont = 0;
        for(int j = 1; j <=t; j++) {
            if ((i + x[j])%24 >= 9 and (i + x[j])%24 <= 17) cont += w[j];
        }

        resp = max(resp, cont);
    }

    cout << resp << endl;

    return 0;
}
