#include<iostream>
//implementing reversing stacks
using namespace std;
void insertAtBottomInStack(int*a,int&top,int temp){
    /*pop all elements from stack and then push temp onto the stack*/
    if((top)==-1)
    {
        a[++(top)]=temp;
        return;
    }
    int temp2=a[(top)--];
    insertAtBottomInStack(a,top,temp);
    a[++(top)]=temp2;
}
void reverseStack(int *a,int&top){
    /*pop all elements one by one while storing them recursively*/
    if((top)==-1)
        return;
    int temp=a[(top)--];
    reverseStack(a,top);
    insertAtBottomInStack(a,top,temp);
}
int main(){
    int s,top;
   // cin>>s;//s is size of stack
    //int *a=new int [s];
    int a[]={1,2,3,4};
    top=3;
    reverseStack(a,top);
    reverseStack(a,top);
    for(int i=0;i<4;i++)
        cout<<a[i];
    return 0;
}
