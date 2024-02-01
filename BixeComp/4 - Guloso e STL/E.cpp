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

int t, n, u, q;
int l, r, val;

vector<ll> psa, v;

int main(){_

    cin >> t;

    while(t--){
        cin >> n >> u;

        v = vector<ll>(n+1);
        psa = vector<ll>(n+1);
        psa[0] = 0;
        for (int i=1; i<=u; i++){
            cin >> l >> r >> val;
            v[l] += val;
            v[r+1] -= val;
        }

        psa[0] = v[0];
        for (int i=1; i<n; i++){
            psa[i] = psa[i-1] + v[i];
        }   

        cin >> q;

        for (int i=0; i<q; i++){
            int num;
            cin >> num;
            cout << psa[num] << endl;
        }
    }

    return 0;
}