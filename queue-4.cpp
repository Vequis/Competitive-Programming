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
vector<int> v(1001000);
int ff;

int main(){_

    cin >> n >> m;

    v[n] = 1;

    fila.push(n);

    while(1){
        n = fila.front();
        fila.pop();

        if (n == m) break;

        if (n*2 <= 1000000 and n*2>=0 and v[n*2]==0) {
            fila.push(n*2);
            v[n*2] = v[n]+1;
        }

        if (n*3 <= 1000000 and n*3>=0 and v[n*3]==0) {
            fila.push(n*3);
            v[n*3] = v[n]+1;
        }

        if (n/2 <= 1000000 and n/2>=0 and v[n/2]==0){
            fila.push(n/2);
            v[n/2] = v[n]+1;
        }

        if (n/3 <= 1000000 and n/3>=0 and v[n/3]==0) {
            fila.push(n/3);
            v[n/3] = v[n]+1;
        }

        if (n+7 <= 1000000 and n+7>=0 and v[n+7]==0) {
            fila.push(n+7);
            v[n+7] = v[n]+1;
        }

        if (n-7 <= 1000000 and n-7>=0 and v[n-7]==0 ) {
            fila.push(n-7);
            v[n-7] = v[n]+1;
        }
    }

    cout << v[n]-1 << endl;

    return 0;
}