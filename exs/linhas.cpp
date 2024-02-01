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
// #define endl '\n'
#define ll long long int

using namespace std;

vector< vi > adj;

int t, l, o, d, n;

int visitados[1000];
int dist[1000];
vector< vi > linhas;

queue<int> fila;

int bfs(int ini){

    fila.push(ini);

    visitados[ini] = 1;

    while(!fila.empty()){

        int node = fila.front();

        for (int i=0; i<sz(adj[node]); i++){
            for (int j=0; j<sz(linhas[adj[node][i]]); j++){
                int num = linhas[adj[node][i]][j];

                if (!visitados[num]){
                    visitados[num] = 1;
                    fila.push(num);
                    dist[num] = dist[node] + 1;
                }

                if(num == d) return dist[d]; 
            }
        }
        fila.pop();
    }
    
    return -1;
}

int main(){_

    cin >> t >> l >> o >> d;

    linhas = vector < vi > (l+1);
    adj = vector< vi >(t+1);

    for (int i=0; i<l; i++){
        cin >> n;

        while(n--){
            int x;
            cin >> x;
            adj[x].pb(i+1);
            linhas[i+1].pb(x);
        }
    }

    dist[o] = 0;



    cout << bfs(o) << endl;

    return 0;
}

