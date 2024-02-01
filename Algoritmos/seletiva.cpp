#include<bits/stdc++.h>

using namespace std;
#define pi 4*atan(1)

double resp;

//b 760mmhg - nivel do mar

double vetor[20] = {10,20,30,40,50,60,70,80,81,82,83, 84, 85, 86, 87, 88, 89, 89.517, 90};
double respostas[20] = {10, 21, 34, 49, 70,101, 159, 319, 353, 394, 444, 509, 593, 700, 863, 1103, 1481, 1760, 2123};

int main(){

    cout << pi << endl;

    cout << fixed;
    cout << std::setprecision(12);

    resp = 60.25;
    resp*= 273;
    resp/=283;
    resp*=tan(vetor[0] *  pi/180.0);
    cout << resp << endl;

    for (int i=0; i<20; i++){
        cout << vetor[i] << " : ";
        resp = 60.25;
        resp*= 273;
        resp/=283;
        resp*=tan(vetor[i] *  pi/180.0);
        cout << resp;
    
        if (abs(respostas[i] - resp) > 1) cout << " <- IMPRECISO";

        cout << endl;
    }

}