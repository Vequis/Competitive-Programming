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

int t;
int n;
int v[2][112345];
int soma1, soma2;
int resp;

signed main(){_

    cin >> t;

    while(t--){
        cin >> n;

        soma1=0;
        for(int i=1; i<=n; i++){
            cin >> v[0][i];
            soma1+=v[0][i];
        }
        for(int i=1; i<=n; i++){
            cin >> v[1][i];
        }

        soma2=0;
        soma1-=v[0][1];
        resp = INT_MAX;
        for(int i=1; i<=n; i++){
            int atual = max(soma1, soma2);
            // cout << soma1 << ' ' << soma2 << endl;
            resp = min(resp, atual);
            soma1-=v[0][i+1];
            soma2+=v[1][i];
        }

        cout << resp << endl;
    }

    return 0;
}
