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

int soma, resp;
pair<int, ii> v[212345];

int cmp(pair<int, ii> a, pair<int, ii> b){
    return a.fs > b.fs;
}

signed main(){_

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;

        v[i] = {a-b ,{a, b}};
    }

    sort(v+1, v+n+1, cmp);

    soma = 0;
    for(int i=1; i<=n; i++){
        ii atual = v[i].sc;
        // cout << atual.fs << ' ' << atual.sc << endl;
        resp = max(resp, atual.fs + soma);
        soma += atual.sc;
    }

    cout << resp << endl;

    return 0;
}
