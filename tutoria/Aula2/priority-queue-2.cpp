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

//Muito util para dijkstra

//Tambem conhecido como heap
priority_queue<int, vector<int>, greater<int> > pq; //Sempre vai ter no topo o maior elemento
// Invertemos para min heap, ou seja, menor no topo

int n, x, y;

int main(){_

    cin >> n;
    while(n--){
        cin >> x;
        pq.push(x);
    }
    
    while(!pq.empty()){
        x = pq.top(); //menor elemento;
        pq.pop();
        cout << x << " " << endl;
    }

    //Não tem a função clear; Temos de rechamar ela para esvaziar ou aplicar a estrutura acima

    return 0;
}