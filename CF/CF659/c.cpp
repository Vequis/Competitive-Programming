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

string st1, st2;
int t, n, cont;
// vector< priority_queue<int, vi, greater<int> > > v(20);
vector< map<int, int> > v(25);
map<int, int> :: iterator it;
bool ok;

int main(){_
    cin >> t;

    for (int i=0; i<t; i++){
        ok = true;
        cin >>  n;

        v = vector< map<int,int> >(25);
        
        cin >> st1;
        cin >> st2;

        for (int j=0; j<n; j++){
            int pos1 = st1[j] - 'a';
            int num = st2[j] - st1[j];
            
            if(num<0){
                ok = false;
            } else if(num>0){
                v[pos1][num]++;
            }
        }

        if(!ok){
            cout << -1 << endl;
            continue;
        }

        cont = 0;
        for (int j=0; j<=20; j++){
            if (!v[j].empty()){
                int num = v[j].begin()->fs;
                for (auto [a,b] : v[j]){
                    if (a != num){
                        v[j+num][a - num] += b;
                    }
                }
                cont++;
            }
        }

        cout << cont << endl;

        v.clear();
    }

    return 0;
}