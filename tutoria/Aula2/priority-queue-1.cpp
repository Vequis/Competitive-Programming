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

//Bom para ver máximos e mínimos com updates;

priority_queue<int> pq; //Sempre vai ter no topo o maior elemento

int n, x, y;

int main(){_

    cin >> n;
    while(n--){
        cin >> x;
        pq.push(x);
    }
    
    while(!pq.empty()){
        x = pq.top(); //Maior elemento;
        pq.pop();
        cout << x << " " << endl;
    }

    //Não tem a função clear; Temos de redeclarar ela para esvaziar ou aplicar a estrutura acima

    return 0;
}