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
#define int long long // -> solução divina

using namespace std;

int dx[] = {-1, -1, -1, 0,  0, 1,  1, 1};
int dy[] = {-1,  0,  1, 1, -1, 1, -1, 0};

int grade[250][250];

int n, m;

int dfs(int x, int y){
    int cont = 1;

    for(int i=0; i<8; i++){
        if(grade[x+dx[i]][y+dy[i]] == 0 && 0<x+dx[i] && x+dx[i]<=n && 0<y+dy[i] && y+dy[i]<=m){
            grade[x+dx[i]][y+dy[i]] = 1;
            cont+=dfs(x+dx[i], y + dy[i]);
        }
    }

    return cont;
}

signed main(){_

    cin >> n >> m;

    int x, y;
    cin >> x >> y;
    int k;
    cin >> k;

    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        grade[a][b] = -1;
    }

    grade[x][y] = 1;

    cout << dfs(x, y) << endl;

    return 0;
}
