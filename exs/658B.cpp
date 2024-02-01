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

stack<int> fila;
int ganha[112345];
int n;

signed main(){_

    int t;
    cin >> t;
    while(t--){
        cin >> n;

        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            fila.push(num);
        }

        int cont = n-1;
        ganha[n] = 1;
        fila.pop();
        while(!fila.empty()){
            if(fila.top() > 1){
                ganha[cont] = 1;
            } else {
                ganha[cont] = 1 - ganha[cont+1];
            }
            fila.pop();
            cont--;
        }
        
        if(ganha[1]){
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }

    return 0;
}
