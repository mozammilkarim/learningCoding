#include<iostream>
using namespace std;
void f1(int* a, int n){
    //takes O(n) time with O(1) space
    /*replace-every-array-element-by-multiplication-of-previous-and-next*/
    int temp1=a[0],temp=a[0];int i;
    for(i=0;i<n-1;i++){
        temp1=a[i]; //for storing current element
        a[i]=temp*a[i+1];
        temp=temp1;
    }

    a[i]=temp*a[i];
}
int main(){
    int a[]={2, 3, 4, 5, 6};
    f1(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
