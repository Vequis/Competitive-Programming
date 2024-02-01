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

vector< vector<int> > grid(10010);

int n, m;

int dp[10010][10010][2];

int main(){_

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        grid[i].pb(0);
        for (int j=1; j<=m; j++){
            int num;
            cin >> num;
            grid[i].pb(num);
        }
    }

    //0 - Não vindo de cima
    //1 - Vindo de cima

    dp[1][1][0] = grid[1][1];
    dp[1][1][1] = -1;


    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (i==1 and j==1) continue;

            if (j>1){
                if (dp[i][j-1][0]!=-1 and dp[i][j-1][1]!= -1)   dp[i][j][0] = min(dp[i][j-1][0], dp[i][j-1][1]) + grid[i][j];
                else if (dp[i][j-1][0]==-1 and dp[i][j-1][1]!= -1) dp[i][j][0] = dp[i][j-1][1] + grid[i][j];
                else if (dp[i][j-1][0]!=-1 and dp[i][j-1][1]== -1) dp[i][j][0] = dp[i][j-1][0] + grid[i][j];
                else if (dp[i][j-1][0]==-1 and dp[i][j-1][1]== -1) dp[i][j][0] = -1;
            } else if (j==1){
                dp[i][j][0] = -1;
            }
        
            if (i>1){
                if (dp[i-1][j][0] == -1) dp[i][j][1] = -1;
                else dp[i][j][1] = dp[i-1][j][0] + grid[i][j];
            } else if (i==1){
                dp[i][j][1] = -1; 
            }
        }
    }

    cout << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << dp[i][j][0] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << dp[i][j][1] << ' ';
        }
        cout << endl;
    }

    cout << endl;

    cout << "O menor caminho possivel eh ";
    cout << min(dp[n][m][0],dp[n][m][1]) << endl; 

    return 0;
}