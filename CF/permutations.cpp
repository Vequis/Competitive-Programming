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

    int n;
    cin >> n;

    int v[1123];
    for(int i = 0; i < n; i++) v[i] = i+1;

    int resp = -1;

    int resposta[1123];

    do{
        int maxe = -1;
        int soma = 0;

        for(int i = 0; i < n; i++) {
            soma += (i+1)*v[i];
            maxe = max(maxe, (i+1)*v[i]);
        }

        soma-=maxe;
        resp = max(soma, resp);
        if(soma == resp) {
            cout << soma << endl;
            for(int i = 0; i < n; i++) cout << v[i] << ' ';
            cout << endl;
        }
    } while(next_permutation(v, v+n));

    cout << resp << endl;

    return 0;
}
