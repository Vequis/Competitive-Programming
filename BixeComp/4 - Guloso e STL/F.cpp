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
// #define int long long -> solução divina?

using namespace std;

int n, atual, topo;

stack<int> rua;
queue<int> fila;
vi v;

int main(){_

    while((cin >> n) && (n!=0)){
        for (int i=0; i<n; i++){
            int num;
            cin >> num;
            fila.push(num);
        }   

        atual = 1;

        while(!fila.empty()){
            while (!rua.empty() and rua.top()==atual){
                rua.pop();
                atual++;
            }

            if (fila.front() == atual){
                atual++;
            } else {
                rua.push(fila.front());
            }
            fila.pop();
        }

        while (!rua.empty() and rua.top()==atual){
            rua.pop();
            atual++;
        }

        if (!rua.empty()){
            cout << "no" << endl;
            while(!rua.empty()) rua.pop();
        } else {
            cout << "yes" << endl;
        }
    }   

    return 0;
}