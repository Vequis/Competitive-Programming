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
int k, n, m;
int a[111], b[111], resp[222];
int ptra, ptrb, ok, cont;

signed main(){_

    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=m; i++) cin >> b[i];

        ptra=1, ptrb=1;
        ok = 1;
        cont = 1;
        while(ptra<=n){
            if(a[ptra] == 0) {
                k++;
                resp[cont] = a[ptra];
                ptra++;
                cont++;
            } else {
                while(k < a[ptra]){
                    if(ptrb>m) {
                        ok = 0;
                        break;
                    }
                    if(b[ptrb]==0) {
                        k++;
                        resp[cont] = b[ptrb];
                        ptrb++;
                        cont++;
                    } else {
                        if(k < b[ptrb]){
                            ok=0;
                            break;
                        }
                        resp[cont] = b[ptrb];
                        ptrb++;
                        cont++;
                    }
                }
                resp[cont] = a[ptra];
                ptra++;
                cont++;
            }
            if(!ok)break;
        }

        while(ptrb<=m && ok==1){
            if(b[ptrb]==0) {
                k++;
                resp[cont] = b[ptrb];
                ptrb++;
                cont++;
            } else {
                if(k < b[ptrb]){
                    ok=0;
                    break;
                }
                resp[cont] = b[ptrb];
                ptrb++;
                cont++;
            }
        }

        if(ok){
            for(int i=1; i<=n+m; i++) cout << resp[i] << ' ';
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
