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

int t, n, ant;
int qtd;

int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        qtd = 0;
        ant = -1;
        for (int i=0; i<n; i++){
            int x;
            cin >> x;

            if (x==1){
                if (ant==-1){
                    ant = i;
                } else {
                    qtd+=i-ant-1;
                    ant = i;
                }
            }
        }

        cout << qtd << endl;
    }
    return 0;
}