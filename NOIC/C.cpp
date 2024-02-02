#include <iostream>
#include <vector>
#include <queue>
using namespace std;

matriz[1000][1000];

bool check(int x, int y, int n, int m){
    if (y>=0 and y<=n and x>=0 and x<=m){
        return true;
    } else return false;
}

int main(){

    int n, m;
    cin >> n >> m;

    pair<int, int> maq;

    vector< pair<int,int> > musgo;

    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){

            if (s[j-1] == 'P'){
                matriz[i][j] = -1;
            } else if (s[j-1] == 'O'){
                musgo.push_back(make_pair(i,j));
            } else if (s[j-1] == 'C'){
                maq = make_pair(i,j);
            }
        }
    }

    queue< pair<int,int> > fila;
    for (int i=0; i<musgo.size(); i++){

        fila.push(musgo[i]);

        while(!fila.empty()){
            int x = musgo.first; 
            int y = musgo.second;

            if (check(x+1, y, n, m)){}
        }

    }

}