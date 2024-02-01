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
#define int long long

using namespace std;

vi v;
vi dist;

int grupos;

signed main(){_

    int n, k, x;
    cin >> n >> k >> x;

    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        v.eb(num);
    }

    sort(all(v));

    grupos=1;

    for(int i=1; i<n; i++){
        if(v[i] != v[i-1]) {
            if(v[i] - v[i-1] > x) {
                dist.eb(v[i] - v[i-1]);
                grupos++;
            }
        }
    }

    sort(all(dist));

    for(int i=0; i<sz(dist); i++){
        
        if((dist[i]-1)/x <= k){
            k-=(dist[i]-1)/x;
            grupos--;
        }
        if(k<=0) break;
    }

    cout << grupos << endl;

    return 0;
}
