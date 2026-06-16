#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int>valor;
    valor.push_back(10);
    valor.push_back(20);
    valor.push_back(30);

    cout <<"Primeiro: "<<valor[0]<< endl;
    cout <<"Tamanho: "<< valor.size()<<endl;
    cout <<"Elementos: ";

    for(int i=0; valor.size();i++){
        cout <<valor[i]<< " ";
    }
    cout << endl;
    valor.pop_back();
    cout<< "Após remover: ";
    for(int x : valor){
        cout<< x << " ";
    }
    cout << endl;
    return 0;
}
