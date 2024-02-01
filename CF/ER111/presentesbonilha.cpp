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

bool memo[100005][10005];
int v[11234];
int n, t;
int ok, soma;

int dp(int soma, int x){
    if(x==n+1 && soma==0) return 1;
    if(x==n+1) return 0;
    if(soma<0) return 0;

    if(memo[soma][x] != -1 ) return memo[soma][x];

    return memo[soma][x] = (dp(soma, x+1) || dp(soma-v[x], x+1));
}

signed main(){_

    cin >> t;
    while(t--){
        cin >> n;

        soma=0;
        for(int i=1; i<=n; i++){
            cin >> v[i];
            soma+=v[i];
        }

        int ptr = soma/2;

        memset(memo, -1, sizeof(memo));

        ok=0;
        while(ptr>=0 && abs( (soma - ptr) - ptr) <= 5){
            ok = (ok || dp(ptr, 1));

            if(ok) break;
            ptr--;
        }

        if(ok){
            cout << "Feliz Natal!" << endl;
        } else {
            cout << "Ho Ho Ho!" << endl;
        }
    }

    return 0;
}
