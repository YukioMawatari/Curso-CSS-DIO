#include <iostream>
using namespace std;

void pedindonum(int num) {
    for(int i = 0; i < num; i++) {
        cout << "Digite um numero: ";
        int numero;
        cin >> numero;
        cout << "Numero digitado: " << numero << endl;
        
        if(numero % 2 == 0) {
            cout << "EH PAR" << endl;
        } else {
            cout << "EH IMPAR" << endl;
        }
    }
}

int main() {
    int num = 0;
    cout << "Quantos numeros deseja digitar? ";
    cin >> num;
    pedindonum(num);
    return 0;
}
