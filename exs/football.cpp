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

using namespace std;

string s;
int cont=1;
char ant;

int main(){_

    cin >> s;

    ant = s[0];
    for (int i=1; i<s.size(); i++){
        if (s[i] == ant){
            cont++;
            if (cont == 7){
                cout << "YES" << endl;
                return 0;
            }
        } else {
            cont=1;
        }
        ant = s[i];
    }

    cout << "NO" << endl;

    return 0;
}