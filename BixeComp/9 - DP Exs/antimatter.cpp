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

int memo[11234][1111];
int n;
vi v;

int dp(int soma, int ini) {//A partir de ini, de quantas formas posso alcançar soma?
    if(ini>n) return 0;

    if(memo[soma][ini]!=-1) return memo[soma][ini];

    int var = soma;
    
    int resp = 0;
    if(var - v[ini] == 0) resp = (2 + dp(abs(var-v[ini]), ini+1))%MODN;

    if(abs(var - v[ini]) != var + v[ini]) resp = (resp + (dp(var+v[ini], ini+1) + dp(abs(var-v[ini]), ini+1))%MODN)%MODN;
    else resp = dp(var+v[ini], ini+1);

    // cout << soma << ' ' << ini << ':' << resp << endl;
    return memo[soma][ini] = resp;
}

signed main(){_

    cin >> n;
    v = vi(n+1);

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++) cin>>v[i];

    int resp = 0;
    for(int i=1; i<=n; i++) resp = (resp + dp(0, i))%MODN;
    cout << resp << endl;

    return 0;
}
