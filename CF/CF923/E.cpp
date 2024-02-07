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
        int n, k;
        cin >> n >> k;

        int x = 0;

        vi v(n+1);

        for(int i = 1; i <= n; i++) v[i] = -1;

        int ptmenor = 1;
        int ptmaior = n;

        int menor = 0;
        for(int i = 1; i <= k; i++){
            menor = menor xor 1;
            for(int j = i; j<=n; j+=k) {
                if (menor) {
                    v[j] = ptmenor;
                    ptmenor++;
                } else {
                    v[j] = ptmaior;
                    ptmaior--;
                }
            }
        }

        for(int i = 1; i <=n; i++) cout << v[i] << ' ';
        cout << endl;
    }

    return 0;
}
