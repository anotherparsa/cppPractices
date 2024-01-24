#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target);

int main(){
    int arr[] = {2, 5, 6, 7, 4, 1, 3, 8, 9};
    cout << linearSearch(arr, sizeof(arr) / sizeof(int), 7) << endl;
}

int linearSearch(int arr[], int size, int target){
    for (int i = 0; i < size ; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}