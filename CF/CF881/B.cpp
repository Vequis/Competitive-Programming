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
        int n;
        cin >> n;

        vi v;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);

        }

        int seqn = 0;
        int resp = 0;
        int soma = 0;
        for(int i = 0; i < n; i++) {
            if (v[i] < 0) {
                if(!seqn) {
                    seqn = 1;
                    resp++;
                } 
            } else if (v[i] > 0) seqn = 0;
            soma += abs(v[i]);
        }
        cout << soma << ' ' << resp << endl;
    }

    return 0;
}
