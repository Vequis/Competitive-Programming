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

int n;
int bom, ruim;
int a[10000];

signed main(){_

    ruim = -1;
    bom = -1;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=n-1; i>=1; i--){
        if(a[i] == 0 or a[i] == 5){
            if (a[i] < a[n]){
                bom = i;
            } else {
                if (ruim == -1){
                    ruim = i;
                }
            }
        }
    }

    if(bom == -1){
        if (ruim != -1) swap(a[ruim], a[n]);
        else {
            if (a[n] % 5 != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    } else {
        swap(a[bom], a[n]);
    }

    for(int i=1; i<=n; i++){
        cout << a[i] << ' ';
    }

    cout << endl;

    return 0;
}
