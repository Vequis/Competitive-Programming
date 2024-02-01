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

int n;
ll soma, resp, total;
vector<ll> v, psa;

ll bb(ll soma, int a){
    ll ini=0, fim=a, mid;
    while(ini<fim){
        mid = ini + (fim-ini)/2;
        if (psa[mid] >= soma) fim=mid;
        else ini = mid+1;
    }

    // cout << ini << ' ' << psa[ini] << endl;

    if(psa[ini]==soma) return 1;
    return 0; 
}

int main(){_

    cin >> n;
    v = vector<ll>(n+1);
    psa = vector<ll>(n+1);

    psa[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>v[i];
        psa[i] = psa[i-1] + v[i];
    }

    for(int i=n; i>=0; i--){
        if (bb(psa[n] - psa[i], i)){
            // cout << i << psa[i] << endl;
            resp = max(psa[n] - psa[i], resp);
        }
    }

    cout << resp << endl;

    return 0;
}