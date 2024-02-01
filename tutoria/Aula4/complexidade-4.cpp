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

int n, m, a[1000][1000], b[1000][1000];
int ans[1000][1000];

int main(){_

    for (int i=0; i<n; ++i){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ans[i][j] = 0;

            for (int k=0; k<n; k++){
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//Complexidade O(n² + n² + n*n*(n+1) + n² + 1) -> O(n³)