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
    
string s1, s2;
int  n, a, b, q,t;
    
void switche(int a, int b){
    char c;
    if (a<=n-1) {
        c = s1[a];
        if (b<=n-1){
            s1[a] = s1[b];
            s1[b] = c;
        } else {
            s1[a] = s2[b-n];
            s2[b-n] = c;
        }
    } else {
        c = s2[a-n];
        if (b<=n-1){
            s2[a-n] = s1[b];
            s1[b] = c;
        } else {
            s2[a-n] = s2[b-n];
            s2[b-n] = c;
        }
    }
    return;
}
    
void switchall(){
    string aux = s1;
    s1 = s2;
    s2 = aux;
}
    
int main(){_
    
    cin >> n;
    for (int i=0; i<n; i++){
        char c;
        cin >> c;
        s1+=c;
    }
    for (int i=0; i<n; i++){
        char c;
        cin >> c;
        s2+=c;
    }
    cin >> q;
    
    bool trocado

    for (int i=0; i<q; i++){
        cin >> t;
        cin >> a >> b;
        if (t==1){
            switche(a-1, b-1);
        } else {
            switchall();
        }
    }
    
    cout << s1 << s2 << endl;
    
    return 0;
}