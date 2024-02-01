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
#define INF 1000000
using namespace std;

int dist[MAX][MAX];
int maxi[MAX];
int n, m, u, v, w;

void fw(){
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                // if (dist[i][j] != INF) maxi[i] = max(maxi[i], dist[i][j]);
            }
        }
    }
}

int main(){_

    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            dist[i][j] =INF;
        }
    }

    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }   

    fw();
 
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j) continue;

            maxi[i] = max(maxi[i], dist[i][j]);
        }
    }

    sort(maxi, maxi+n);

    cout << maxi[0] << endl;

    return 0;
}