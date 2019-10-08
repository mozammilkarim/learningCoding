#include<iostream>
using namespace std;
void printKSmallestElementsInOrder(int* a, int n,int k){
    /*partition such that all k smallest elements are on left side but  keeping their order using insertion sort idea */
    for(int l=1;l<=k&&l+k-1<n;l++){
       //find max in left portion
       int mx=a[0],mxP=0;
       for(int i=0;i<k;i++){
            if(mx<a[i])
            {
                mx=a[i];
                mxP=i;
            }
       }
       if(mx>a[k+l-1])/*right portion has smaller element than element in left portion*/
       {
           //prepare left portion for incoming element
           int temp=a[mxP];
           /*left rotate left portion upto the index which is larger than  right portion element */
           for(int i=mxP;i<k-1;i++)
                a[i]=a[i+1];
           //now exchange a[k-1] with a[k+l-1]
           int temp1=a[k+l-1];
           a[k+l-1]=temp;
           a[k-1]=temp1;
       }
    }
    for(int i=0;i<k;i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[]={4, 2, 6, 1, 5};
    printKSmallestElementsInOrder(a,5,3);
   // for(int i=0;i<5;i++)
   //     cout<<a[i]<<" ";
    return 0;
}
