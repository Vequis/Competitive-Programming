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

int t, n, cont;
int v3[10000], v5[10000], v7[10000];

int main(){_

    cin >> t;
    
    v3[0] = -1;
    v3[1] = -1;
    v3[2] = -1;
    v3[3] = 1;
    v3[4] = -1;
    v5[5] = 1;
    v3[6] = 2;
    v7[7] = 1;

    for (int i=8; i<=1007; i++){
        v3[i] = v3[i-3] + 1;
        v5[i] = v5[i-3];
        v7[i] = v7[i-3];
    }

    while(t--){
        cin >> n;

        if (v3[n] == -1){
            cout << - 1 << endl;
        } else {
            cout << v3[n] << ' ' << v5[n] << ' ' << v7[n] << endl; 
        }
    }

    return 0;
}