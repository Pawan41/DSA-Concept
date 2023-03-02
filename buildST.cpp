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

int queryST(vector<int> &tree, int l, int h, int index, int rs, int re)
{
    // case 1-----> no overlaping
    if (re < l || rs > h)
    {
        return 0;
    }

    // case 2------> complete overlaping
    if (l >= rs && h <= re)
    {
        return tree[index];
    }

    // partial overlaping
    int mid = (l + h) / 2;
    return queryST(tree, l, mid, 2 * index + 1, rs, re) + queryST(tree, mid + 1, h, 2 * index + 2, rs, re);
}

void pointUpdate(vector<int> &tree, int l, int h, int index, int i, int val)
{
    //base case
    if(l>h) return ;

    if(l==h){
        tree[index]=val;
        return;
    }

    int mid=(l+h)/2;
    if(i<=mid){
        pointUpdate(tree,l,mid,2*index+1,i,val);
    }else{
        pointUpdate(tree,mid+1,h,2*index+2,i,val);
    }
    tree[index]=tree[2*index+1]+tree[2*index+2];
}

int main()
{
    int arr[] = {2, 4, 1, 6, 5, 8, 10, 30};
    int n = 8;
    vector<int> tree(4 * n);

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

            int ans = queryST(tree, 0, n - 1, 0, rs, re);
            cout << "sum in the range " << rs << " to " << re << " is : " << ans << endl;
        }
        else
        {
            int index, val;
            cin >> index >> val;

            /*------------Point Update in Segment Tree--------*/
            pointUpdate(tree, 0, n - 1, 0, index, val);
        }
    }

    return 0;
}