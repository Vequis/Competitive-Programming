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
#define maxn 112345

using namespace std;

vi primos;
int visitados[maxn];
int var;
int l[maxn], r[maxn];
bool visprimos[maxn];
int n, m;

int crivo(int n){
    primos.pb(2);
    int cont = 1;
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            cont++;
            for(int j=i*i; j<=n; j+=i) visitados[i] = 1;
        }
    }
    return cont;
}

int dp(int x, int soma){
    int resp = 0;

    if(soma<0) return 0;
    if(x>n) return 1;

    resp += dp(x+1, soma-1);
    for(int i=0; i<=var; i++){
        int atual = 1;
        if(!visprimos[i]){
            atual = primos[i];
            while(atual<=r[x]){
                visprimos[i] = 1;
                if(atual>=l[x]) resp+=dp(x+1, soma-atual);
                atual*=primos[i];
            }
            visprimos[i] = 0;
        }
    }
    cout << x << ' ' << soma << ' ' << resp << endl;

    return resp;
}

signed main(){_

    cin >> n >> m;

    var = crivo(m+1);

    for(int i=1; i<=n; i++){
        cin >> l[i] >> r[i];
    }

    cout << dp(1, m) << endl;

    return 0;
}