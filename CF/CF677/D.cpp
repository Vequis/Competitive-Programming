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

using namespace std;

int t, n;

vi dist;

int main(){_

    cin >> t;
    while(t--){
        cin >> n;

        dist = vi(n+1);

        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            dist[i]=x;
        }

        int rival = 0;
        vi amigos;
        for (int i=2; i<=n; i++){
            if (dist[i] != dist[1]){
                if (rival==0) rival = i;
            } else {
                amigos.pb(i);
            }
        }

        if (rival == 0) {
            cout << "NO" << endl;
            continue;
        } else {
            cout << "YES" << endl;
        }

        for (int i=2; i<=n; i++){
            if (dist[i] != dist[1]){
                cout << 1 << ' ' << i << endl;
            } else {
                cout << rival << ' ' << i << endl;
            }
        }

        amigos.clear();
    }

    return 0;
}