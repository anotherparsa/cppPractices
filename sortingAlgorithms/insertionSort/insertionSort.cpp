#include <iostream>

using namespace std;

void insertionSort(int arr[], int size);

void showArray(int arr[], int size);

void swapping(int arr[], int a, int b);

int main(){
    int arr[] = {3, 5, 1, 9 , 4, 2, 7, 6, 8};
    int size = sizeof(arr) / sizeof(int);
    cout << "Before insertion sorting: " << endl;
    showArray(arr, size);
    cout << "After insertion sorting: " << endl;
    insertionSort(arr, size);
    showArray(arr, size);
}

void insertionSort(int arr[], int size){
    for (int i = 1 ; i < size ; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            swapping(arr, j+1, j);
            j--;
        }
    }
}

void showArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapping(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}