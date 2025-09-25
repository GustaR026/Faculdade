#include <bits/stdc++.h>
using namespace std;
int main(){
    int opção;
    float n1,n2;
    cout<<"#######MENU#######"<<endl<<"1-Calcular n1"<<endl<<"2-Calcular n2"<<endl<<"0-Sair"<<endl;
    cin>>opção;
    while(opção!= 0){
        if(opção==1){
            cout<<"Digite n2: ";
            cin>>n2;
            n1=(60-6*n2)/4;
            cout<<n1<<endl;
        }
        else if(opção==2){
            cout<<"Digite n1: ";
            cin>>n1;
            n2=(60-4*n1)/6;
            cout<<n2<<endl;
        }
        else{
            cout<<"Opção inválida"<<endl;
        }
        cout<<"#######MENU#######"<<endl<<"1-Calcular n1"<<endl<<"2-Calcular n2"<<endl<<"0-Sair"<<endl;
        cin>>opção;
    }
    
    cout << n2 << endl;
}