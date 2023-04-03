/*La complejidad de este ejercicio es muy cercana a O(n*m*p*q) donde n es la cantidad de carreras,
m es la cantidad de pilotos, p es la cantidad de personas premiadas que hay en cada uno de los
sistemas de premiación y q es la cantidad de sistemas de premiación.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void formula(){
    int carreras, pilotos, i, j,k,l,cantidadSistemas,premiados, arr[100][500], arr2[500], retorno[500];
    cin >> carreras;
    cin >> pilotos;    
    while (carreras !=0 && pilotos!= 0){    
        for (i=0;i<carreras;i++){
            for (j=0;j<pilotos;j++){
                cin >> arr[i][j];
            }
        }
        cin >> cantidadSistemas;
        for (i=0;i<cantidadSistemas;i++){
            cin >> premiados;
            for (j=0;j<premiados;j++){
                cin >> arr2[j];
            }
            for (j=0;j<pilotos;j++){
                retorno[j]=0;
            }

            for (j=0;j<carreras;j++){
                for (k=0;k<pilotos;k++){
                    for (l=0;l<premiados;l++){
                        if (arr[j][k]==l+1){
                            retorno[k]+=arr2[l];
                        }
                    }
                }
            }
            int mayor=-1, contador=0, contador2=1;
            for (j=0;j<pilotos;j++){
                if (retorno[j]>mayor){
                    mayor=retorno[j];
                    contador=1;
                }
                else if (retorno[j]==mayor){
                    contador+=1;
                }
            }
            int m=0;
            while (m<pilotos && contador2<=contador){
                if (retorno[m]==mayor && (contador2==contador)){
                    cout<<m+1<<endl;
                    contador2+=1;
                }
                else if(retorno[m]==mayor && (contador2<contador)){
                    cout<<m+1<<" ";
                    contador2+=1;
                }
                m++;
            }
        }
        cin >> carreras;
        cin >> pilotos;
    }
}

int main(){
    formula();
    return 0;
}