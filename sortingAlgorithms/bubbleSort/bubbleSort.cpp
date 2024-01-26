#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size);
void swapping(int arr[], int a, int b);

int main(){
    int arr[] = {3, 6, 1, 4, 2, 5, 9, 7, 8};
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    
    for (int i = 0 ; i < sizeof(arr) / sizeof(int) ; i++){
        cout << arr[i] << endl;
    }
}

void bubbleSort(int arr[], int size){
    for (int i = 1 ; i <= size; i++){
        for (int j = 0 ; j < size - i ; j++){
            if (arr[j] > arr[j + 1]){
                swapping(arr, j, j+1);
            }
        }
    }
}

void swapping(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}