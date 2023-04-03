/* Este algoritmo tiene un mejor y un peor caso, en el mejor caso, la mitad superior tiene una sola
letra, entonces solo es necesario poner esa letra y ya retornaría esa única letra. Así que en el 
mejor caso la complejidad sería O(nlogn), por el sort. En el peor caso, todas las letras
de la mitad inferior, serían la z. De esa manera recorrería todo el ciclo 
en muchas ocasiones hasta llegar al final y ahí poner la misma letra. Así que tendría que la 
complejidad en ese caso sería O(n*p+nlogn) donde p sería la cantidad de letras que tiene la mitad superior
y n el recorrido que debe hacer al abecedario.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
char abecedario[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void organizar(){
    int n;
    cin >> n;
    while (n!=0){
        int i, j=0;
        string retorno="";
        string arr[1000];
        for (i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<string> vecarr(arr, arr+ n);
        sort(vecarr.begin(),vecarr.end());
        string mitadSup=vecarr[n/2-1];
        string mitadInf=vecarr[n/2];
        i=0;
        while (mitadSup>retorno){
            j=0;
            bool flag=true;
            if (mitadSup[i]==mitadInf[i]){
                retorno.push_back(mitadSup[i]);
            }
            else if (mitadSup.length()==1){
            retorno.push_back(mitadSup[i]);
            }
            else if (i==mitadSup.length()-1){
                retorno.push_back(mitadSup[i]);
            }
            else{
                while (j<26 && flag==true){
                    if (mitadSup[i]==abecedario[25]){
                        retorno.push_back(mitadSup[i]);
                        flag=false;
                    }
                    else if (mitadInf.length()==1 && abecedario[j]==mitadSup[i] && mitadInf[i]==abecedario[j+1]){
                        retorno.push_back(mitadSup[i]);
                    }
                    else if (abecedario[j]==mitadSup[i] && mitadInf[i]==abecedario[j+1] && i==mitadInf.length()-1){
                        retorno.push_back(mitadSup[i]);   
                    }
                    else if (abecedario[j]==mitadSup[i]){
                        retorno.push_back(abecedario[j+1]);
                        flag=false;
                    } 
                    j++;
                }
            }
            i++;
        }
        cout << retorno << endl;

        cin >> n;
    }

}

int main(){
    organizar();
    return 0;
}
