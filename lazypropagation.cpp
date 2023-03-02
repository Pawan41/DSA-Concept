#include <bits/stdc++.h>
using namespace std;
int buildSegmentTree(vector<int> &tree, int l, int h, int index, int arr[])
{
    // base case
    if (l > h)
    {
        return 0;
    }
    // leaf node
    if (l == h)
    {
        return tree[index] = arr[l];
    }

    int mid = (l + h) / 2;
    int leftTreeSum = buildSegmentTree(tree, l, mid, 2 * index + 1, arr);
    int rightTreeSum = buildSegmentTree(tree, mid + 1, h, 2 * index + 2, arr);
    return tree[index] = leftTreeSum + rightTreeSum;
}

int queryST(vector<int> &tree,vector<int>&lazy, int l, int h, int index, int rs, int re)
{
    // case 1-----> no overlaping
    if (re < l || rs > h)
    {
        return 0;
    }

    if(lazy[index]!=0){
        tree[index]+=lazy[index]+(h-l+1);
        lazy[2*index+1]+=lazy[index];
        lazy[2*index+2]+=lazy[index];
        lazy[index]=0;
    }

    // case 2------> complete overlaping
    if (l >= rs && h <= re)
    {
        return tree[index];
    }

    // partial overlaping
    int mid = (l + h) / 2;
    return queryST(tree,lazy, l, mid, 2 * index + 1, rs, re) + queryST(tree,lazy, mid + 1, h, 2 * index + 2, rs, re);
}

void Update(vector<int> &tree,vector<int>&lazy, int l, int h, int index, int rs,int re, int val)
{
    // case 1-----> no overlaping
    if (re < l || rs > h) return;

    if(lazy[index]!=0){
        tree[index]+=lazy[index]+(h-l+1);
        lazy[2*index+1]+=lazy[index];
        lazy[2*index+2]+=lazy[index];
        lazy[index]=0;
    }

    // case 2------> complete overlaping
    if (l >= rs && h <= re){
        tree[index]+=val*(h-l+1);
        lazy[2*index+1]+=val;
        lazy[2*index+2]+=val;
    }else{
        int mid = (l + h) / 2;
        Update(tree,lazy,l,mid,2*index+1,rs,re,val);
        Update(tree,lazy,mid+1,h,2*index+2,rs,re,val);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
}

int main()
{
    int arr[] = {2, 4, 1, 6, 5, 8, 10, 30};
    int n = 8;
    vector<int> tree(4 * n,0),lazy(4*n,0);

    /*---------------Build a Segment Tree-------------*/
    buildSegmentTree(tree, 0, n - 1, 0, arr);

    /*---------------Query in Segment Tree-------------*/
    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int rs, re;
            cin >> rs >> re;

            int ans = queryST(tree,lazy, 0, n - 1, 0, rs, re);
            cout << "sum in the range " << rs << " to " << re << " is : " << ans << endl;
        }
        else
        {
            int l,r, val;
            cin >> l>>r >> val;

            /*------------Point Update in Segment Tree--------*/
            Update(tree,lazy, 0, n - 1, 0, l,r, val);
        }
    }

    return 0;
}