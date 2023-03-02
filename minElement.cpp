#include<bits/stdc++.h>
using namespace std;
int buildSegmentTree(vector<int>&tree,int l,int h,int index,int arr[]){
    //base case
    if(l>h){
        return 0;
    }
    //leaf node
    if(l==h){
        return tree[index]=arr[l];
    }

    int mid=(l+h)/2;
    int leftTreeSum=buildSegmentTree(tree,l,mid,2*index+1,arr);
    int rightTreeSum=buildSegmentTree(tree,mid+1,h,2*index+2,arr);
    return tree[index]= min(leftTreeSum,rightTreeSum);
}

int main(){
    int arr[]={2,4,1,6,5,8,10,30};
    int n=8;
    vector<int>tree(4*n);

    buildSegmentTree(tree,0,n-1,0,arr);
    for(int i=0;i<4*n;i++){
        cout<<i<<": "<<tree[i]<<" , ";
    }
    return 0;
}