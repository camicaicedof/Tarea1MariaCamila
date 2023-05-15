/*La complejidad del algoritmo que resuelve el problema, suponiendo que funciona por cada palabra que se da
en el diccionario es, en el mejor caso O(1) y en el peor caso O(n). El mejor caso ocurre cuando el ciclo itera
solamente una vez ya que la primera letra de la palabra no está en las letras que dieron para formarla. En
el peor caso, todas las letras estarían, así que iteraría toda la longitud de la palabra.*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void word(vector<string> &vec, string s){
    int arr[26]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arr2[26];
    int x, y, k,contador=0;
    bool flag;
    vector<string>::iterator it;
    for (int i=0;i<s.size();i++){
        if (s[i]!=' '){
            x=s[i]-'a';
            arr[x]++;
        }
    }

    for (it=vec.begin();it!=vec.end();it++){
        for (int j=0;j<26;j++){
            arr2[j]=arr[j];
        }
        k=0;
        flag=true;
        while(k<(*it).size() && flag){
            y=(*it)[k]-'a';
            if(arr2[y]>0){
               arr2[y]-=1; 
            }
            else{
                flag=false;
            }
            k++;
        }
        if (flag){
            contador++;
        }

    }
    cout<<contador<<endl;
    
}

int main(){
    vector<string>vec;
    //vec={"ant","bee","cat","dog","ewe","fly","gnu"};
    string s,s2;

    //s="t a n c u g d";
    //word(vec,s);
    cin>>s2;
    while (s2!="#"){
        vec.push_back(s2);
        cin>>s2;
    }
    cin.ignore();
    getline(cin,s);
    while (s[0]!='#'){
        word(vec,s);
        getline(cin,s);
    }

    return 0;
}
