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


set<int> cj;
queue<int> fila;
queue<int> aux;
int resp = 0;

void f() {
    cj.clear();
    while(!fila.empty()) {
        int a = fila.front(); fila.pop();
        if (cj.find(a) != cj.end()) {
            aux.push(a);
        } else {
            cj.insert(a);
        }
    }
    resp += cj.size() - 1;
    fila = aux;

    while(!aux.empty()) aux.pop();
}

signed main(){_


    int n;
    cin >> n;

    while(n--) {
        int a;
        cin >> a;
        fila.push(a);
    }

    while(!fila.empty()) f();

    cout << resp << endl;

    return 0;
}
