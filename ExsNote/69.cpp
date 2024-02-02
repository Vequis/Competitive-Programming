#include <iostream>

using namespace std;

int main() {
    float n;
    float x1,y1,x2,y2;

    cin >> n >> x1 >> y1 >> x2 >> y2;

    if ( (x1-((n+1)/2))*(x2-((n+1)/2))>0 and (y1-((n+1)/2))*(y2-((n+1)/2))>0 ) {
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }
}
