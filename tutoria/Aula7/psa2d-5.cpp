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
#define MAX (1<<10)

using namespace std;

int a[MAX][MAX], psa[MAX][MAX];
int n, m, l, c,q ;
int r;
int ans = 0, atual;

//Problema das fitas 2d, dadas as fitas, qual posição tem mais fitas?;

int main(){_

    cin >> n >> m >> q;

    while(q--){
        int ia, ib, ja, jb;
        cin >> ia >> ja >> ib >> jb;

        a[ia][ja] += 1;
        a[ia][jb+1] += -1;
        a[ib+1][ja] += -1;
        a[ib+1][jb+1] += 1;       
        
    }

    ans = 0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            cout << psa[i][j] << ' ';
            ans = max(ans, psa[i][j]);
        }
        cout << endl;
    }

    cout << ans << endl;

    return 0;
}