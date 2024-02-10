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

vi fim;
vi resposta;

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        if (k < n*(n-1)/2 or k > (n-1)*(n-1)) {
            cout << -1 << endl;
            continue;
        }

        int sobra = (k - n*(n-1)/2);
        // cout << sobra << endl;
        resposta.pb(1);
        for(int i = 2; i <=n; i++) {
            if (sobra > n - i){
                sobra-=n-i;
            }
            else {

                for(int cnt = 1; cnt <= sobra; cnt++) resposta.pb(i + cnt);
                
                for(int j = i; j>=2; j--) resposta.pb(j);
                break;
            }
        }

        for(int x : resposta) cout << x << ' ';
        cout << endl;

        fim.clear();
        resposta.clear();
    }

    return 0;
}
