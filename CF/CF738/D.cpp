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

#define MAXN 100100

int n, k, pai[2][MAXN], peso[2][MAXN];
vii resp;

queue<int> fila1, fila2;

int find(int x, int id){
	
	if(pai[id][x]==x) return x;
	return pai[id][x]=find(pai[id][x], id);
}
 
void join(int x, int y, int id){
	
	x=find(x, id);
	y=find(y, id);
	
	if(x==y) return;
	
	if(peso[id][x]<peso[id][y]) pai[id][x]=y;
	if(peso[id][x]>peso[id][y]) pai[id][y]=x;
	
	if(peso[id][x]==peso[id][y]){
		
		pai[id][x]=y;
		peso[id][y]++;
	}
}
signed main(){_

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        pai[0][i] = i;
        pai[1][i] = i;
    }

    int m1, m2;
    cin >> m1 >> m2;

    for(int i=0; i<m1; i++){
        int a, b;
        cin >> a >> b;
        join(a,b,0);
    }

    for(int i=0; i<m2; i++){
        int a, b;
        cin >> a >> b;
        join(a,b,1);
    }

    bool ok = false;
    bool change = true;

    while(!ok && change){
        ok = true;
        change = false;

        int pai1 = find(1, 0);
        int pai2 = find(1, 1);
        for(int i=1; i<=n; i++){
            if(find(i, 0)!= pai1 || find(i, 1)!= pai2){
                if(find(i, 0)!= pai1 && find(i, 1)!= pai2){
                    join(i, pai1, 0);
                    join(i, pai2, 1);

                    resp.eb(i,1);

                    pai1 = find(1, 0);
                    pai2 = find(1, 1);

                    change =  true;
                } else {
                    ok = false;
                    if(find(i, 0)!= pai1) fila1.push(i);
                    else fila2.push(i);
                }
            }
        }

        while(!fila1.empty() && !fila2.empty()){
            while(!fila1.empty() && find(fila1.front(), 0) == find(1, 0)) fila1.pop();
            while(!fila2.empty() && find(fila2.front(), 1) == find(1, 1)) fila2.pop();

            if(!fila1.empty() && !fila2.empty()) {
                resp.eb(fila1.front(), fila2.front());

                join(1, fila1.front(), 0);
                join(1, fila2.front(), 1);

                change = true;  
            }
        }
    }

    cout << sz(resp) << endl;

    for(ii p : resp){
        cout << p.fs << ' ' << p.sc << endl;
    }

    return 0;
}
