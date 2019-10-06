#include<iostream>
using namespace std;
//basic idea is to apply partition of quick sort with modification
int minSwap(int* a, int n,int target ){
    /*all elements less than or equal to target should be placed
    together in minimum swaps */
    int i=-1,j=0,minimum=0;
    for(;i<n&&j<n;j++){
        if(a[j]<=target&&j!=i+1)//need for exchange
        {
            //swap a[i+1] with a[j]
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            minimum++;
        }
        else if(a[j]<=target)
            i++;
    }
    return minimum;
}

int main(){
    int a[]={2, 7, 9, 5, 8, 7, 4};
    cout<<minSwap(a,7,5);

    return 0;
}
