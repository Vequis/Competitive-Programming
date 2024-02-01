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
#define int long long // -> solução divina

using namespace std;

stack<char> pilha;

signed main(){_

    int t;
    cin >> t;

    bool flag;

    while(t--){
        string s;

        cin >> s;
        flag = true;
        for(int i=0; i<sz(s); i++){

            char c = s[i];

            if(c == '(' || c == '[' || c == '{') pilha.push(c);

            if(c==')'){
                if(!pilha.empty() && pilha.top() == '('){
                    pilha.pop();
                } else {
                    flag = false;
                }
            }

            if(c==']'){
                if(!pilha.empty() && pilha.top() == '['){
                    pilha.pop();
                } else {
                    flag = false;
                }
            }

            if(c=='}'){
                if(!pilha.empty() && pilha.top() == '{'){
                    pilha.pop();
                } else {
                    flag = false;
                }
            }
        }


        while(!pilha.empty()) {
            pilha.pop();
            flag = false;
        }

        if(flag){
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }

    }

    return 0;
}
