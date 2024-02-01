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

int n, m, a[1000][1000];

int main(){_

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    return 0;
}

//Complexidade O(n*m) -> O(n²)