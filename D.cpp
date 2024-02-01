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
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007

using namespace std;

int n, m, k;
int dp[505][505][15];

int hor[505][505], vert[505][505];

int dfs(int a, int b, int p){
    if (p==0 or a==0 or b==0 or a>n or b>m) return 0;
    if (dp[a][b][p] != -1){
        return dp[a][b][p];
    }

    int melhor = MODN;
    if (b!=m) melhor = min(melhor, dfs(a,b+1, p-1) + hor[a][b]); 
    if (a!=n) melhor = min(melhor, dfs(a+1,b, p-1) + vert[a][b]); 
    if (b!=1) melhor = min(melhor, dfs(a,b-1, p-1) + hor[a][b-1]); 
    if (a!=1) melhor = min(melhor, dfs(a-1,b, p-1) + vert[a-1][b]); 

    return dp[a][b][p] = melhor;
}

int main(){_

    // memset(dp, -1, 505);

    cin >> n>> m >> k;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            for (int l=1; l<=k; l++) dp[i][j][l] = -1;
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m-1; j++){
            cin >> hor[i][j]; // Entre i,j e i,j+1;
        }
    }

    for (int i=1; i<=n-1; i++){
        for (int j=1; j<=m; j++){
            cin >> vert[i][j]; // Entre i,j e i+!,j;
        }
    }
    
    if (k%2 == 1){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cout << -1 << ' ';
            }
            cout << endl;
        }
        return 0;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << 2*dfs(i,j, k/2) << ' ';
        }
        cout << endl;
    }

    return 0;
}