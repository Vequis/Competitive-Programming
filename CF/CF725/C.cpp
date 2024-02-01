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

int t, n, l, r;
vi v;
ll resp;

int bb1(int x){
    int ini = 0, fim = n, mid;

    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if(v[mid]>=x) fim = mid;
        else ini = mid+1;
    }
    return ini;
}

int bb2(int x){
    int ini = 0, fim = n, mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if(v[mid] > x ) fim = mid;
        else ini = mid+1;
    }
    return ini-1;
}

int main(){_

    cin >> t;

    while(t--){
        cin >> n >> l >> r;

        v = vi(n);

        for (int i=0; i<n; i++){
            cin >> v[i];
        }

        sort(all(v));

        resp = 0;

        for (int i=0; i<n; i++){
            if(bb2(r-v[i]) >= bb1(l-v[i])) resp += bb2(r-v[i]) - bb1(l-v[i]) + 1; 
        
            // cout << bb2(r-v[i]) << ' '<< n-bb1(l-v[i]) << '=' << bb2(r-v[i]) - n + bb1(l-v[i]) << endl;
            // cout << bb2(r-v[i]) << ' ' << bb1(l-v[i]) << '=' << bb2(r-v[i]) - bb1(l-v[i]) + 1 << endl;

            if (2*v[i] >= l and 2*v[i] <= r) resp--;
        
            // cout << '*' << resp << endl; 
        }
        cout << resp/2 << endl;
    }

    return 0;
}