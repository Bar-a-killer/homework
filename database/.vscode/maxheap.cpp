#include<iostream>
using namespace std;

void build(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        int parent = i;
        while(true){
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;
            if(left < n && arr[left] > arr[largest]){
                largest = left;
            }
            if(right < n && arr[right] > arr[largest]){
                largest = right;
            }
            if(largest != parent){
                swap(arr[parent], arr[largest]);
                parent = largest;
            } else {
                break;
            }
        }
    }
}
int pop(int arr[], int &n){
    int top = arr[0];
    arr[0] = arr[n - 1];
    n--;
    int parent = 0;
    while(true){
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        int largest = parent;
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != parent){
            swap(arr[parent], arr[largest]);
            parent = largest;
        } else {
            break;
        }
    }
    return top;
}

int main(){
    int heap[1000];
    int n = 0;
    while(cin >> heap[n++]){
        ;
    }
    n--;
    int m = heap[--n];
    build(heap, n);
    for(int i = 0; i < m; i++){
        pop(heap, n);
    }
    for(int i = 0; i < n; i++){
        cout << "(" << i+1 << ", " << heap[i] << ")" << " ";
    }
    cout << endl;
}