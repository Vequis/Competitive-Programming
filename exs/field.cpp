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

set<ll> cj;
ll atual, total;
int n, diag;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        atual+=num;
        cj.insert(atual);
    }

    total = atual;

    if (total%2){
        cout << "N" << endl;
        return 0;
    }

    for (int x : cj){
        if (x > total/2){
            cout << "N" << endl;
            return 0;
        }

        if(cj.find(x + total/2)!=cj.end()){
            diag++;
            // cout << x << endl;
        }
        if (diag==2){
            cout << "S" << endl;
            return 0;
        }
    }

    return 0;
}