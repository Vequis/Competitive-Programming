#include <iostream>
#include <vector>

using namespace std;

int matriz[10010][10010];

bool check(int x1,int y1,int x2,int y2,int x,int y){
    if ( x>=min(x1,x2) && x<= max(x1,x2) && y>= min(y1,y2) && y<= max(y1,y2)){
        return true;
    } else {
        return false;
    }

}

int main(){

    int x1a, y1a, x2a, y2a;
    cin >> x1a >> y1a >> x2a >> y2a;

    int x1b, y1b, x2b, y2b;
    cin >> x1b >> y1b >> x2b >> y2b;

    vector< pair<int,int> > pontos;

    if (check(x1a, y1a, x2a, y2a, min(x1b,x2b), min(y1b, y2b)) ){
        pontos.push_back(make_pair( min(x1b,x2b), min(y1b, y2b) ) );
    }
    if (check(x1a, y1a, x2a, y2a, min(x1b,x2b), max(y1b, y2b)) ){
        pontos.push_back(make_pair( min(x1b,x2b), max(y1b, y2b) ) );
    }
    if (check(x1a, y1a, x2a, y2a, max(x1b,x2b), min(y1b, y2b)) ){
        pontos.push_back(make_pair( max(x1b,x2b), min(y1b, y2b) ) );
    }
    if (check(x1a, y1a, x2a, y2a, max(x1b,x2b), max(y1b, y2b)) ){
        pontos.push_back(make_pair( max(x1b,x2b), max(y1b, y2b) ) );
    }

    int sz = pontos.size();

    if (sz == 0){
        cout << 0 << endl;
    } else if (sz == 1){
        int xfora = x2b + x1b - pontos[1].first;
        int yfora = y2b + y1b - pontos[1].second;

        if (max(x1a,x2a) >= pontos[1].first and max(x1a,x2a) <=xfora){
            
        }
    } else if (sz == 2){

    } else {

    }

    return 0;

}