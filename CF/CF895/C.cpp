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

vi primos;
int visitados[112345];

void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[i] = 1;
        }
    }
}


signed main(){_

    int t;
    cin >> t;
    crivo(112300);

    while(t--) {
        int l, r;
        cin >> l >> r;

        if (r > 3 and r-l>=1) {
            int itr = l;
            while(itr%2 or itr==2){

                itr++;
            }

            cout << itr - 2 << ' ' << 2 << endl;
        } else if (l==r) {
            bool ehprimo = 1;
            for (int i = 0; i < sz(primos); i++) {
                if (l%primos[i] == 0 and l!=primos[i]) {
                    cout << l-primos[i] << ' ' << primos[i] << endl;
                    ehprimo=0;
                    break;
                }

            }
            if(ehprimo) {
                cout << -1 << endl;
            }
        } else if (r<=3) {
            cout << -1 << endl;
        }

        
    }

    return 0;
}
