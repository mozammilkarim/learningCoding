#include<iostream>
using namespace std;
void findMaxMinSameTime(int* a, int n){
    int mx=0,mn=0;
    //if n is even follow this, otherwise go linearly step by step
    if(a[0]>a[1])//1 element is larger than second
    {
        if(mx<a[0])
            mx=a[0];
        if(mn>a[1])
            mn=a[1];
    }
    else{   //2 element is larger of two
        if(mx<a[1])
            mx=a[1];
        if(mn>a[0])
            mn=a[0];

    }
    for(int i=2;i<n-2;i+=2){/* check two elements at a time two minimise number of comparisons*/
        if(a[i]>a[1+i])//1 element is larger than second
        {
            if(mx<a[i])
                mx=a[i];
            if(mn>a[i+1])
                mn=a[i+1];
        }
        else{   //2 element is larger of two
            if(mx<a[i+1])
                mx=a[i+1];
            if(mn>a[i])
                mn=a[i];

        }
    }
    cout<<mx<<endl<<mn;
}
int main(){
    int a[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
    findMaxMinSameTime(a,9);
    return 0;
}
