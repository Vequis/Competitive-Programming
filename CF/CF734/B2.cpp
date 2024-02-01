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

int t, n, k;
vii v;
vi resp;

signed main(){_

    cin >> t;
    while(t--){
        cin >> n >> k;

        resp = vi(n);

        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            v.eb(num, i);
        }

        sort(all(v));

        int ant = -1;
        int contatual = 1;
        int validos=0;
        int cont = 0;

        for(int i=0; i<sz(v); i++){
            if(v[i].fs == ant){
                contatual++;
            } else {
                contatual = 1;
            }
            ant = v[i].fs;

            if(contatual > k) continue;

            validos++;
        }

        ant = -1;
        int ultimo = 1;

        for(int i=0; i<sz(v); i++){
            if(v[i].fs == ant){
                contatual++;
            } else {
                contatual = 1;
            }
            ant = v[i].fs;

            if(contatual>k or cont>=validos/k){
                resp[v[i].sc] = 0;
                continue;
            }

            resp[v[i].sc] = ultimo;
            if(ultimo == k) {
                ultimo = 1;
                cont++;
            } else ultimo++;
        }

        for(int i=0; i<n; i++){
            cout << resp[i] << ' ';
        }        
        cout << endl;

        v.clear();
    }

    return 0;
}
