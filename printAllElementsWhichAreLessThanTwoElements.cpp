#include<iostream>
using namespace std;
void printAllElementsWhichAreLessThanTwoElements(int* a, int n){
    //takes O(n) time with O(1) space
    /*find second largest element and print all elements which are less than this*/
    int max1=a[0],max2=a[0];int i;
    for(i=0;i<n;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(a[i]<max1&&a[i]>max2)
            max2=a[i];
    }

    for(i=0;i<n;i++){
        if(a[i]<max2)
            cout<<a[i]<<" ";
    }
}
int main(){
    int a[]={2, 3, 4, 5, 6};
    printAllElementsWhichAreLessThanTwoElements(a,5);
    return 0;
}
