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
// #define int long long -> solução divina?

using namespace std;

ll a, b, ka, kb, var1, var2, n, m, q;

ll mdc(ll a, ll b){
    if (a<b) swap(a,b);
    if(b==0) return a;
    return mdc(b, a%b);
}

int main(){_

    cin >> a >> b >> q;
    ka = a/mdc(a,b);
    kb = b/mdc(a,b);

    for (int i=0; i<q; i++){
        ll sx,sy,ex,ey;

        cin >> sx >> sy >> ex >> ey;

        if(sx==1) var1 = (sy-1)/ka;
        else var1 = (sy-1)/kb;

        if(ex==1) var2 = (ey-1)/ka;
        else var2 = (ey-1)/kb;
    
        if(var1==var2){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}