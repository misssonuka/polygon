#include <iostream>

bool isUnique(int arr[], int size){
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
             if (arr[i]==arr[j]){
             return false;
             }
        }
    }
    return true;
}   

int main()
{
    int arr[]={-1,-3,7,12,24,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout<< (isUnique(arr, size) ? "Yes" : "N0");

    return 0;
}