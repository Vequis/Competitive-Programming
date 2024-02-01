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

int n, q;
vi v;

int bb(int x){
    int ini=0, fim=n-1, mid;
    while(ini<fim){
        mid = ini + (fim-ini)/2;
        // cout << ini << ' ' << fim << ' ' << mid << endl;
        if (v[mid] >= x) fim = mid;
        else if (v[mid] < x) ini = mid+1;
    }
    // cout << ini << ' ' << v[ini] << endl;
    if (v[ini] == x) return ini;
    return -1;
}

int main(){_

    cin >> n >> q;

    v = vi(n);

    for (int i=0; i<n ;i++){
        cin >> v[i];
    }

    for (int i=0; i<q; i++){
        int num;
        cin >> num;
        cout << bb(num) << endl;
    }

    return 0;
}