#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string suma(string cad){
    int n1,n2,n3,n4, j;
    string retorno;
    char x;

    n1=cad[0]-'0';
    n2=cad[1]-'0';
    n3=cad[2]-'0';
    n4=cad[3]-'0';

    if (n4!=9){
        x=n4+49;
        for (j=0;j<3;j++){
            retorno.push_back(cad[j]);
            }
        retorno.push_back(x);
    }
    else if (n4==9 and n3!=9 and n2!=9 and n1!=9){
        x=n3+49;
        for (j=0;j<2;j++){
            retorno.push_back(cad[j]);
            }
        retorno.push_back(x);
        retorno.push_back('0');
    }
    else if (n4==9 and n3==9 and n2!=9 and n1!=9){
        x=n2+49;
        retorno.push_back(cad[0]);
        retorno.push_back(x);
        retorno.push_back('0');
        retorno.push_back('0');
    }
    else if (n4==9 and n3==9 and n2==9 and n1!=9){
        x=n1+49;
        retorno.push_back(x);
        retorno.push_back('0');
        retorno.push_back('0');
        retorno.push_back('0');
    }
    else if (n4==9 and n3==9 and n2==9 and n1==9){
        retorno.push_back('1');
        retorno.push_back('0');
        retorno.push_back('0');
        retorno.push_back('0');
        retorno.push_back('0');
    }
    return retorno;
}   



void mastermind(){
    int casos, pistas, i,j,k,l,prov;
    string arr[11][2],forbArr[10],retorno="0000";
    cin >> casos;
    cin >> pistas;
    for (i=0;i<pistas;i++){
        for (j=0;j<2;j++)
            cin >> arr[i][j];
    }
    if (arr[0][1][2]!=0){
        prov=arr[0][1][2]-'0';
        while (prov!=0){
            for(k=2;k>-1;k--){
                if (retorno[3]!=arr[0][0][k]){
                    retorno=suma(retorno);
                }
                else if (retorno[3]==arr[0][0][k])
                prov--;
            }
        }
    cout<<retorno;    
    
}
}
int main(){
    mastermind();
    return 0;
}