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

vector<int> v;

bool ok = false;
int n,m, num;

int main(){_

    int t;
    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n >> m;

        ok = false;

        v = vi(10000);

        for (int j=0; j<n; j++){
            cin >> num;

            v[num] = 1; 
        }

        for (int j=0; j<m; j++){
            cin >> num;

            if (v[num] == 1){
                if(!ok){ 
                    cout << "YES" << endl;
                    cout << "1 " <<  num << endl;
                }
                ok = true;
            }
        }

        if (!ok) cout << "NO" << endl;

        v.clear();
    }

    return 0;
}