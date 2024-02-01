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
#define vvi vector<vi>
#define vvii vector<vii>
#define endl '\n'
#define ll long long int
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int n, m, u, v, w, t, s, d;
vi dist;
int menor;
vvii bus;
vvii plane;
priority_queue<ii, vii, greater<ii> > pq;

void dijkstra(int s){
    dist[s] = 0;

    pq.push({0,s});

    while(!pq.empty()){
        ii topo = pq.top();
        pq.pop();
        d = topo.fs;
        u = topo.sc;

        if (d > dist[u]) continue;

        for (auto [v,w] : bus[u]){
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    menor = dist[n];

    pq.push({0,s});
    dist = vi(n+1, INT_MAX);
    dist[s] = 0;

    while(!pq.empty()){
        ii topo = pq.top();
        pq.pop();
        d = topo.fs;
        u = topo.sc;

        if (d > dist[u]) continue;

        for (auto [v,w] : plane[u]){
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    menor = min(menor, dist[n]);
}

int main(){_

    while(cin >> n >> m){

        plane = vvii(n+1);
        bus = vvii(n+1);
        dist = vi(n+1, INT_MAX);

        for (int i=0; i<m; i++){
            cin >> u >> v >> t >> w;
            if (t==0){//plane
                plane[u].eb(v,w);
                plane[v].eb(u,w);
            }else{
                bus[u].eb(v,w);
                bus[v].eb(u,w);
            }
        }

        dijkstra(1);

        cout << menor << endl;
    }

    return 0;
}