#include<iostream>
using namespace std;
void findFirstMissingInSortedArray(int* a, int n,int m){
    /* n is the number of integers in array and m is the range from 0 to m-1*/
    //traverse n-1 times
    if(a[0]!=0){/* 0 is missing which should be first because array is sorted */
        cout<<0<<endl;
        return;
    }

    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]>1){/*there is a gap between two consecutive elements*/
            cout<<a[i]+1<<endl;
            return;
        }
    }
}
int main(){
    int a[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
    findFirstMissingInSortedArray(a,9,11);
    return 0;
}
