#include <iostream>

using namespace std;

void selectionSort(int arr[], int size);
void swapping(int arr[], int a, int b);

int main(){
    int arr[] = {9, 7, 1, 3, 2, 5, 4, 6, 10, 8};
    selectionSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0 ; i < sizeof(arr) / sizeof(int) ; i++){
        cout << arr[i] << endl;
    }
}

void selectionSort(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        int minIndex = i;
        for (int j = i + 1; j < size ; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swapping(arr, i, minIndex);
    }
}

void swapping(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}