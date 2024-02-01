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

using namespace std;

map <char, int> f;
map<char,int> :: iterator it;
int k;
string resp = "";

int main(){_

    cin >> k;

    string s;
    cin >> s;

    for (int i=0; i< s.size(); i++){
        f[s[i]]++;
    }

    for (it = f.begin(); it != f.end(); it++){
        if ((*it).second%k==0){
            for (int i=0; i<(*it).second/k; i++){
                resp+=(*it).first;
            }
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    // resp *= (s.size())/k;
    string r = "";
    for (int i=0; i<k; i++){
        r.append(resp);
    }

    cout << r << endl;

    return 0;
}