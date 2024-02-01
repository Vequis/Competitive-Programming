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

int v[112345];

int mdc(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return mdc(b, a%b);
}

signed main(){_

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            cin >> v[i];
        }

        v[0] = 1;
        for(int i=2; i<=n; i++){
            if(mdc(v[i], v[i-1]) != 1){
                if(v[i] >= v[i-1]){
                    v[i] = v[i-1] + 1;
                } else {
                    int atual = v[i] + 1;
                    while(mdc(atual, v[i-2]) != 1) atual++;

                    }
                }
            }
        }
    }

    return 0;
}
