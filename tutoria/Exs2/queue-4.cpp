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
    
int n, m;
    
queue<int> fila;
map<long long int,long long int> mp;
    
int main(){_
    
    cin >> n >> m;
    
    mp[n] = 1;
    
    fila.push(n);
    
    while(1){
        n = fila.front();
        fila.pop();

        if (n == m) break;
    
        if (mp[n*2]==0) {
            fila.push(n*2);
            mp[n*2] = mp[n]+1;
        }
    
        if (mp[n*3]==0) {
            fila.push(n*3);
            mp[n*3] = mp[n]+1;
        }
    
        if (mp[n/2]==0){
            fila.push(n/2);
            mp[n/2] = mp[n]+1;
        }
    
        if (mp[n/3]==0) {
            fila.push(n/3);
            mp[n/3] = mp[n]+1;
        }
    
        if (mp[n+7]==0) {
            fila.push(n+7);
            mp[n+7] = mp[n]+1;
        }
    
        if (mp[n-7]==0 ) {
            fila.push(n-7);
            mp[n-7] = mp[n]+1;
        }
    }
    
    cout << mp[m]-1 << endl;
    
    return 0;
}