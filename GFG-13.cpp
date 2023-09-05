#include<iostream>
using namespace std;

int majority_element(int arr[], int size) {
    if (size == 0) {
        return -1; 
    }

    int count = 1;
    int num = arr[0];

    for (int i = 1; i < size; i++) {
        if (num == arr[i]) {
            count++;
        } else {
            count--;
            if (count == 0) {
                num = arr[i];
                count = 1;
            }
        }
    }

    count = 0; 

    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            count++;
        }
    }

    if (count > size / 2) {
        return num;
    } else {
        return -1; 
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int a = majority_element(arr, size);
    if (a != -1) {
        cout << "Majority element: " << a << endl;
    } else {
        cout << "No majority element found" << endl;
    }

    return 0;
}
