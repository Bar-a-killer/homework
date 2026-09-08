#include <iostream>
#include <string>
using namespace std;
int trans(char c) {
    if(c == '+') return 100;
    else if(c == '-') return 100;
    else if(c == '*') return 120;
    else if(c == '/') return 120;
    else return 0;
}
int main() {
    int num[100] = {0};
    char sign[100] = {0};
    string ch;
    getline(cin, ch);
    char tmp = 0;
    int idx = 0;
    int ids = 0,idn = 0;
    tmp = ch[idx];
    while(tmp != '\n' && tmp != '\0') {
        if(tmp - '0' >= 0 && tmp - '0' <= 9) {
            cout << tmp << ' ';
            num[idn] = tmp - '0';
            idn++;
        } else if(tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
            while(ids > 0 && trans(tmp) <= trans(sign[ids - 1])) {
                cout << sign[ids - 1] << ' ';
                num[idn] = sign[ids - 1]; 
                idn++;
                ids--;
            }
            sign[ids] = tmp;
            ids++;
        }
        idx++;
        tmp = ch[idx];
    }
    while(ids > 0 && trans(tmp) <= trans(sign[ids - 1])) {
        cout << sign[ids - 1] << ' ';
        num[idn++] = sign[ids - 1]; 
        ids--;
    }
    int a, b;
    int ans[100] = {0};
    int idans = 0;
    for(int i = 0; i <= idn; i++) {
        if(num[i] >= 0 && num[i] <= 9) {
            ans[idans] = num[i];
            idans++;
        } else {
            idans--;
            int b = ans[idans];
            idans--;
            int a = ans[idans];
            if(num[i] == '+') {
                ans[idans] = a + b;
            } else if(num[i] == '-') {
                ans[idans] = a - b;
            } else if(num[i] == '*') {
                ans[idans] = a * b;
            } else if(num[i] == '/') {
                ans[idans] = a / b;
            }
            idans++;
        }
    }

    cout << endl;
    cout << ans[0];
    return 0;
}