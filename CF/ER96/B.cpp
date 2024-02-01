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

vi v;
int t, n, k, a, b;
ll soma = 0;

int main(){_

    cin >> t;
    while(t--){
        cin >> n >> k;
        soma = 0;

        for (int i=0; i<n; i++){
            int x;
            cin >> x;
            v.pb(x);
        }

        sort(all(v));

        for (int i=n-1; i>=n-1-k; i--){
            soma+=v[i];
        }

        cout << soma << endl;
        v.clear();
    }

    return 0;
}