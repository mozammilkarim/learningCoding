#include<iostream>
using namespace std;
void findMaxSumOfElementsWhichAreNotAdjacent(int* a, int n){
    /*start from 0 index till less than n-2 index and while traversing update max sum */
    if(n<3)//there are less than 3 elements
    {
        cout<<"sum doesnot exists"<<endl;
        return;
    }
    int mx=a[0]+a[2];
    for(int i=0;i<n-2;i++){//go till third last element
        for(int j=i+2;j<n;j+=2)//jump two steps to avoid adjacent element
        {
            if(mx<a[i]+a[j])
                mx=a[i]+a[j];
        }
    }
    cout<<mx;
}
int main(){
    int a[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
    findMaxSumOfElementsWhichAreNotAdjacent(a,9);
    return 0;
}
