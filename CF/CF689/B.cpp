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

int t, n, m, cont;
char grid[1000][1000];
vii pontos;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n >> m;
        cont = 0;
        for (int j=1; j<=n; j++){
            for (int k=1; k<=m; k++){
                char c;
                cin >> c;
                if (c=='*'){
                    pontos.eb(k,j);
                } 
                grid[j][k] = c;
            }
        }

        for (int j=0; j<pontos.size(); j++){
            bool ok=true;
            int x=pontos[j].fs, y=pontos[j].sc;
            int var = 0;
            while(ok){
                var++;
                cont++;
                for (int l=x-var; l<=x+var;l++){
                    if (l<=0 or l>m or y+var>n or grid[y+var][l] == '.'){
                        ok=false;
                        break;
                    } 
                }
            }
        }
        cout << cont << endl;
        pontos.clear();
    }

    return 0;
}

