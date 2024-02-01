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

int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        cout << 2 << endl;
        cout << n << ' ' << n-1 << endl;
        
        for (int i=0; i<n-2; i++){
            cout << n-i << ' ' << n-2-i << endl;
        }
    }

    return 0;
}