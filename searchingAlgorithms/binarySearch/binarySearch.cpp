#include <iostream>

using namespace std;


int binarySearch(int arr[], int size, int target);

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binarySearch(arr, sizeof(arr) / sizeof(int), 7) << endl;
}

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int stop = size -1;
    while(start <= stop){
        int middle = ((start + stop) / 2);
        if (arr[middle] == target){
            return middle;
        }else if (arr[middle] < target){
            start = middle + 1;
        }else{
            stop = middle -1;
        }
    }
    return -1;

}