/*En este problema, la solución consiste de una función llamada Morse,
esta consiste en un peor y un mejor caso. En el peor caso, un espacio que traducir
por lo que el input sería "  ". En ese caso solo entraría a dos condicionales, para
decir al final que el retorno es simplemente un espacio. En este caso la complejidad sería
O(n) ya que se recorre una vez el vector de morse y al no encontrarlo retorna el espacio.
Como la longitud de la cadena sería 2, entonces en el segundo caso ya simplemente no entraría
al primer while.

En el peor caso es de una complejidad muy cercana a O(n^2) donde n es la cantidad de letras que hay
y es cuando todas las letras son @ o todos son espacios y hay 53 o más letras que traducir
ya que sería necesario recorrer todo el vector n veces.
*/
#include<iostream>  
#include<vector>
#include<string>
using namespace std;
string morse[]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-",
     "--..--", "..--..", ".----.", "-.-.--","-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
vector<string> vecMorse(morse, morse + 53); 
char letras[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                    '0','1','2','3','4','5','6','7','8','9','.',',','?','\'','!','/','(',')','&',':',';','=','+','-','_', '"' ,'@'};
vector<char> vecLetras(letras, letras + 53); 
string Morse(string palabra){
    int j=0;
    string retornoFinal="";
    string retorno="";
    while(j<=palabra.length()){
        bool flag=true;
        int i=0;

        if(palabra[j]!=' '){
            retorno.push_back(palabra[j]);
        }

        if(palabra[j]==' ' || j==palabra.length()-1){
            while (i<53 && flag==true){
                if (retorno==vecMorse[i]){
                    retornoFinal.push_back(vecLetras[i]);
                    flag=false;
                }
                i++;
            }
            retorno="";
            if (j!=palabra.length()){
                if (palabra[j]==' ' && palabra[j+1]==' '){
                    retornoFinal.push_back(' ');   
                }
            }

        }

        j++;
    }
    return retornoFinal;
    }

void leer(){
    int cantidadCasos, i;
    cin >> cantidadCasos;
    cin.ignore();
    for (i=0;i<cantidadCasos;i++){
        string entrada;
        string salida;
        getline(cin,entrada);
        salida=Morse(entrada);
        cout<<"Message #"<<(i+1)<<endl;
        if (i==cantidadCasos-1){
            cout<<salida<<endl;
        }
        else{
            cout<<salida<<endl<<endl;
        }


    }
}

int main(){
    leer();
    return 0;
}