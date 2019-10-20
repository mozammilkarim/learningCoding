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
void checkRightPosition(int*a,int&top,int temp){
    if(top==-1){
        a[++top]=temp;
    }
    else if(a[top]>=temp)
    {
        //since temp is smallest till now
        a[++top]=temp;
    }
    else
    {
        int temp2=a[top--];
        checkRightPosition(a,top,temp);//means u have put temp at its right position
        a[++top]=temp2;
    }
}
void soritngStackRecursively(int*a,int &top){
        /*pop all elements one by one while storing them recursively*/
    if(top==-1)
        return;
    int temp=a[top--];
    soritngStackRecursively(a,top);
    //now push keeping sorted order
    if(top==-1)
        a[++top]=temp;
    else if(a[top]>=temp)
    {        //since temp is smallest till now
        a[++top]=temp;
    }
    else
    {
        int temp2=a[top--];
        checkRightPosition(a,top,temp);//means u have put temp at its right position
        a[++top]=temp2;
    }
}
int main(){
    int s,top;
   // cin>>s;//s is size of stack
    //int *a=new int [s];
    int a[]={1,-2,-3,4};
    top=3;
    soritngStackRecursively(a,top);
    //reverseStack(a,top);
    for(int i=0;i<4;i++)
        cout<<a[i];
    return 0;
}
