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

map<string, string> dic;
int t,n,m;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){

        cin >> n >> m;
        for (int j = 0; j< n; j++){
            string palavra,trad;
            cin >> palavra;
            cin.ignore();
            getline(cin, trad);
            dic[palavra] = trad;
        }

        string linha = "";
        string pal = "";
        for (int j=0; j<m; j++){
            getline(cin, linha);

            for (int k=0; k<linha.size(); k++){
                if(linha[k]!=' '){
                    pal+=linha[k];
                } else {
                    if (dic.find(pal) != dic.end()) cout << dic[pal] << " ";
                    else cout << pal << " ";
                    pal = "";
                }
            }

            if (dic.find(pal) != dic.end()) cout << dic[pal] << endl;
            else cout << pal << endl;
            pal = "";
        }

        cout << endl;

        dic.clear();
    }

    return 0;
}