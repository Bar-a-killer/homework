#include<iostream>
#include<string>

using namespace std;

int main() {
    string mes;
    int key[8];
    cout << "Input the message : " << endl;
    cin >> mes;
    cout << "Input the key : ";
    for(int i=0;i<8;i++) {
        cin >> key[i];
    }

    // Encode
    string encoded;
    if(key[1] + key[0] + key[7] <= 20) {
        for(int i=0;i<mes.length();i++) {
            mes[i] -= 11;
        }
    }
    for(int i=0;i<mes.length();i++) {
        mes[i] -= key[i%8-1];
        mes[i] *= key[i%4];
        encoded += to_string(mes[i] - 400);
    }

    // Decode
    string decoded;
    for(int i=0;i<encoded.length();i++) {
        int num = stoi(encoded.substr(i, 3));
        mes[i] = num + 400;
        mes[i] /= key[i%4];
        mes[i] += key[i%8-1];
        decoded += mes[i];
    }
    if(key[1] + key[0] + key[7] <= 20) {
        for(int i=0;i<decoded.length();i++) {
            decoded[i] += 11;
        }
    }
    cout << "encoded: " << encoded << endl;
    cout << "decoded: " << decoded << endl;
    return 0;
}






