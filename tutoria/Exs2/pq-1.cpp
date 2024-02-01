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

priority_queue<ii, vii, greater<ii> > pq;
queue<int> fila;
int n, l, tempo, t;
pair <int, int> p;
vector<int> cont;

int main(){_

    cin >> n >> l;

    cont = vi(n+1);

    for (int i=0; i<l; i++){
        cin >> t;
        fila.push(t);
    }

    for (int i=1; i<=n; i++){
        if (fila.empty()) break;
        pq.push({fila.front(), i});
        fila.pop();
        cont[i] = 1;
    }

    tempo = 0;
    while(!fila.empty()){
        // cout << tempo << endl;
        p = pq.top();
        pq.pop();

        tempo = p.fs;
        cont[p.sc]++;
       
        pq.push({fila.front()+ tempo, p.sc});
        fila.pop();
    }

    for (int i=1; i<=n; i++){
        cout << i << " " << cont[i] << endl;
    }

    return 0;
}