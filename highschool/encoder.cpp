#include<iostream>
#include<string>
int main() {
    std::string mes;
    int key[8];
    std::cout << "Input the message : " << std::endl;
    std::cin >> mes;
    std::cout << "Input the key : ";
    for(int i=0;i<8;i++) {
        std::cin >> key[i];
    }
    for(int i=0;i<mes.length();i++) {
        mes[i] /= key[i%4];
        mes[i] += key[i%8-1];
    }
    if(key[1] + key[0] +key[7] <= 20) {
        for(int i=0;i<mes.length();i++) {
            mes[i] += 11;
        }
    }
    for(int i=0;i<mes.length();i++) {
        std::cout << mes[i]%93+32;
    }
}
