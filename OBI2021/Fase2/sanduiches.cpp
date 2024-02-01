#include<bits/stdc++.h>

#define endl '\n'
#define int long long 

using namespace std;

int vis[30];
vector<int> adj[30];

int n, m;
vector<int> temp[30];

int dfs(int node){
    int resp = 1;

    for(int x : adj[node]) {
        if(!vis[x]){
            vis[x] = 1;
            temp[node].push_back(x);
        }
    }

    for(int i=node+1; i<=n; i++){
        if(!vis[i]) resp += dfs(i);
    }
    
    for(int x : temp[node]){
       vis[x] = 0;
    }
    temp[node].clear();

    return resp;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        if(a>b) swap(a,b);
        //Sempre a<=b

        adj[a].push_back(b);
    }

    int resp = 0;

    for(int i=1; i<=n; i++){
        int atual = dfs(i);
        resp += atual;
        // resp+=dfs(i);
    }

    cout << resp << endl;

    return 0;
}