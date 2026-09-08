#include<bits/stdc++.h>
using namespace std;

void dfs(int value, vector<int> &datas, vector<int> &output) {
    int i = value;
    while(i < int(datas.size())-5+int(output.size())) {
        output.push_back(datas[i]);
        if(6 == int(output.size())) {
            for(int j = 0; j < 5; j++) 
                cout << output[j] << " ";
            cout << output[5] << endl;
        }
        else
            dfs(i + 1, datas, output);
        output.pop_back();
        i++;
    }
}

int main() {
    int T;
    int k;
    int tmp;
    vector<int> datas;
    cin >> T;
    while(T--) {
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> tmp;
            datas.push_back(tmp);
        }
        vector<int> output;
        dfs(0, datas, output);
        datas.clear();
    }
    return 0;
}