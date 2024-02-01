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
int n, m, l, c;
ll ans = 0, atual;

//Achar submatriz de maior soma;

int main(){_

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];

            psa[i][j] = psa[i-1][j] + psa[i][j-1] -psa[i-1][j-1] + a[i][j];
        }
    }

    cout << endl;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << psa[i][j] << ' ';
        }
        cout << endl;
    }  

    cout << endl;

    cin >> l >> c;

    for (int i=l; i<=n; i++){
        for (int j=c; j<=m; j++){
            atual = psa[i][j] - psa[i-l][j] - psa[i][j-c] + psa[i-l][j-c];
            ans = max(ans, atual);
        }

    }

    cout << ans << endl;

    return 0;
}