#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {

    int a,b;
    cin >> a >> b;

    int h, m;
    cin >> h >> m;

    double Hangle;
    if (h<=12){
        Hangle = (8*atan(1)/12)*h + ((4*atan(1))/360)*m;
    } else {
        Hangle = (8*atan(1)/12)*(h-12);
    }

    double Mangle = ((8*atan(1))/60)*m;

    double angleR = abs(Hangle - Mangle);
    double cosA = cos(angleR);

    double resp;


    resp = a*a + b*b - 2*a*b*cosA;
    resp = sqrt(resp);

    printf("%.15lf", resp);

    return 0;
}
