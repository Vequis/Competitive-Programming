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

using namespace std;

map<int, int> f[101];

int n, x;

int main(){_

    // cin >> n;
    // while(n--){//Ve o valor e tira depois;
    //     cin >> x;
    //     f[x]++;
    // }

    // for (int i=0; i<=101; i++){
    //     if (f[i]){
    //         cout << i << " " << f[i] << endl;
    //     }
    // }

    cin >> n;

    while (n--){
        cin >> x;
        f[x]++;
    }

    for (auto [k,v] : f){
        cout << k << " : " << v << endl;
    }

    return 0;
}