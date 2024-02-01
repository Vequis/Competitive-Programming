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

int n;
vi v;

int main(){_

    cin >> n;

    v = vi(n);

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        v[i] = x;
    }

    v.pb(0);

    sort(all(v));

    for (int i=1; i<=n; i++){
        if (v[i] - v[i-1] > 8){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}