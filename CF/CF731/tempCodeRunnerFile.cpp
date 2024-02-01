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

int a[MAX];

int t;

signed main(){_

    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int maior = 0;
        int cont = 0;
        int pot;
        int resp;

        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        for(int i=1; i<=n; i++){
            int var = a[i];
            cont = 0;
            pot = 1;
            resp = 0;
            while(var>0 or cont<maior){
                cont++;
                int dig = var%2;
                if(!dig && cont<=maior){
                    resp+=pot;
                }

                pot*=2;
                var = (var>>1);
                // cout << var << ' ' << resp <<  endl;
            }
            maior = max(cont, maior);
            cout << resp << ' ';
        }

        cout << endl;
        // for(int i=1; i<n; i++){

        //     cout << (a[i] & a[i-1]) << endl;
        // }
    }
    return 0;
}
