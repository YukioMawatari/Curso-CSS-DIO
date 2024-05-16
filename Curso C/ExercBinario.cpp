#include <iostream>
#include <stack>
using namespace std;

string decimalToBinary(int decimalNumber) {
    stack<int> binaryDigits;
    
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;
        binaryDigits.push(remainder);
        decimalNumber /= 2;
    }
    
    string binaryString = "";
    while (!binaryDigits.empty()) {
        binaryString += to_string(binaryDigits.top());
        binaryDigits.pop();
    }
    
    return binaryString;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    
    string binaryNumber = decimalToBinary(decimalNumber);
    cout << "Binary equivalent: " << binaryNumber << endl;
    
    return 0;
}
