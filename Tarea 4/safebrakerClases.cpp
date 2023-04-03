#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class safebraker{
public:
    string numero;
    int digitosCorr;
    string digitosSinPos;

    safebraker(string numero,int correctos,int incorrectos){
        this->numero=numero;
        int digitosCorr=0;
        int digitosSinPos=0;
    }
}

int main(){
    vector<safebraker> vecsafe;
    int casos, pistas;
    string numero;
    cin >> casos >> pistas;
    for (int i=0;i<casos;i++){
        for(int j=0;j<pistas;j++){
            cin >> numero;
            safebraker(numero)
        }
    }


    return 0;
}