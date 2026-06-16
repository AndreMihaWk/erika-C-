#include <iomanip>
#include <iostream>

using namespace std;

int main(){

int idade;
cout << "Digite sua idade: ";
cin >> idade ;
cout << "Você tem "<< idade << " anos " << endl;

cout << fixed  << setprecision(2);
cout << setw(10) << "nome " << setprecision(5);

return 0;

}