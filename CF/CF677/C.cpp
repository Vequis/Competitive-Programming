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

int t, n, maior;
vi v;

int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        maior = 0;

        v.pb(INT_MAX);

        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            maior = max(maior, x);
            v.pb(x);
        }

        v.pb(INT_MAX);
        for (int i=1; i<=n; i++){
            if (v[i] == maior){
                if (v[i] > v[i-1] or v[i] > v[i+1]) {
                    cout << i << endl;
                    break;
                }
            }

            if (i==n) cout << -1 << endl;
        }
        v.clear();

    }

    return 0;
}