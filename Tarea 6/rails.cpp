#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

void ImprimirStack(stack<int> s){
    for(int i=0;i<5;i++){
        cout<<s.top()<<"s ";
        s.pop();
    }
}
void ImprimirQueue(queue<int> s){
    for(int i=0;i<5;i++){
        cout<<s.front()<<"q ";
        s.pop();
    }
}

void rails(int n, queue<int> &entrada){
    queue<int> primero;
    stack<int> segundo;
    segundo.push(-1);
    int i;
    bool flag=true;
    string salida;
    for (i=0;i<n;i++){
        primero.push(i+1);
    }

    while (entrada.empty()==false && flag==true){
      
        if (entrada.front()==segundo.top() && !segundo.empty()){
            segundo.pop();
            entrada.pop();
        }
        else if (entrada.front()!=segundo.top() && primero.empty() && !segundo.empty()){
            flag=false;
        }
    
        else if (entrada.front()==primero.front() && !primero.empty()){
            primero.pop();
            entrada.pop();
        }
        else if(entrada.front()!=primero.front() && !primero.empty()){
            segundo.push(primero.front());
            primero.pop();
        
        }


    }
    if (!flag){
        salida="No";
    }
    else{
        salida="Yes";
    }
    for (int i=0;i<salida.size();i++){
        cout<<salida[i];
    }
    cout<<endl;
}

int main(){ 
    int n,x,i;
    queue<int> entrada;
    
    cin>>n;
    /*for (i=0;i<n;i++){
        cin>>x;
        entrada.push(x);
    }
    rails(n,entrada);*/
    while (n!=0){
        
        i=0;

        cin>>x;
        while (x!=0){
            while(!entrada.empty()){
            entrada.pop();
            }
            entrada.push(x);
            i = 0;
            while(i<n-1){
            i++;
            cin>>x;
            entrada.push(x);
            }
        rails(n,entrada);
        cin>>x;
        }
        cout<<endl;      
        cin>>n;
    }

    
    return 0;
}