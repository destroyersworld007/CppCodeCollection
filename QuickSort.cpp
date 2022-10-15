#include <iostream>
using namespace std;

// This Program is an Implementation of Quicksort in c++
// Input: Get an array as an Input
// Output: Prints the Sorted ouput

int partition( int a[], int lb, int ub) {
    int pivot = lb, s = lb, e=ub, temp;
    while(s<e) {
        while(a[s]<=a[pivot]) {
            s++;
        }
        while(a[e]>a[pivot]) {
            e--;
        }
        if(s<e) {
            temp=a[s];
            a[s]=a[e];
            a[e]=temp;
        }
    }
    temp=a[pivot];
    a[pivot]=a[e];
    a[e]=temp;
    return e;
}

void quick(int a[],int s,int e) {
    int loc;
    if(s<e) {
        loc=partition(a,s,e);
        quick(a,s,loc-1);
        quick(a,loc+1,e);
    }
}

int main() {
    int a[100],n,i;
    cout << "Enter the Number of Elements in the Array: ";
    cin >> n;
    cout << "Enter the Array Elements with space btw: ";
    for(i=0;i<n;i++) {
        cin >> a[i];
    }
    quick(a,0,n-1);
    cout << "Sorted Array:" << endl;
    for(i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    return 0;
}