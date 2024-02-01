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
vii v;

int bb(int x){
    int ini = 0, fim = sz(v), mid;
    while(ini < fim){
        mid = (fim+ini)/2;
        if(v[mid].fs == x) return mid;
        else if (v[mid].fs > x) fim = mid;
        else ini = mid+1;
    }

    if(ini!=0 && ini<sz(v) && v[ini].fs == x) return ini;
    else return -1;
}

signed main(){_

    cin >> t;

    while(t--){
        int p;
        cin >> p;

        v = vii();

        for(int i=2; i<=p; i++){
            if(bb(p%i) != -1){
                cout << v[bb(p%i)].sc << ' ' << i << endl;
                break;
            } else {
                v.eb(p%i, i);
                sort(all(v));
                // for(int j=2; j<=i; j++){
                //     cout << 
                // }
            }
        }

        v.clear();
    }

    return 0;
}
