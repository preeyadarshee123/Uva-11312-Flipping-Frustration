//
//  main.cpp
//  nik codeforces problems
//
//  Created by PREEYADARSHEE DEV on 15/06/18.
//  Copyright © 2018 PREEYADARSHEE DEV. All rights reserved.
//
// train hard win easy :D
// by the way nik is love
// nik is motivation
// going off the grid for some time
//
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n) rf(i,n,0)
#define inf (ll)1<<60
#define eps 0.000000001
#define endl '\n'
using namespace std;
bitset<10000001> vis;
int arr[10000001];
int q[10000001];
int head=0,tail=0;
void enq(int num)
{
    q[tail]=num;
    if(tail==10000000)
    {
        tail=0;
    }
    else
    {
        tail++;
    }
}
void dq()
{
    if(head==10000000)
    {
        head=0;
    }
    else
    {
       head++;
    }
}
int emp()
{
    if(tail==head)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // lets fuck bfs anf dfs
    int c;
    cin>>c;
    while(c--)
    {
        int n,l,r,t;
        cin>>n>>l>>r>>t;
        head=0;
        tail=0;
        vis.reset();
        if(t==1)
        {
            cout<<0<<endl;
            continue;
        }
        vis[1]=1;
        enq(1);
        int flag=0;
        while(!emp())
        {
            auto v=q[head];
            dq();
            int fr=0;
            if(v<=t&&v+r<=n&&vis[v+r]==0)
            {
                fr=1;
                if(v+r==t)
                {
                    flag=1;
                    cout<<arr[v]+1<<endl;
                    break;
                }
                vis[v+r]=1;
                enq(v+r);
                arr[v+r]=arr[v]+1;
            }
            else if(v>=t&&v-l>=1&&vis[v-l]==0)
            {
                fr=1;
                if(v-l==t)
                {
                    flag=1;
                    cout<<arr[v]+1<<endl;
                    break;
                }
                vis[v-l]=1;
                arr[v-l]=arr[v]+1;
                enq(v-l);
            }
            if(fr==0)
            {
                if(v+r<=n&&vis[v+r]==0)
                {
                    if(v+r==t)
                    {
                        flag=1;
                        cout<<arr[v]+1<<endl;
                        break;
                    }
                    vis[v+r]=1;
                    enq(v+r);
                    arr[v+r]=arr[v]+1;
                }
                else if(v-l>=1&&vis[v-l]==0)
                {
                    if(v-l==t)
                    {
                        flag=1;
                        cout<<arr[v]+1<<endl;
                        break;
                    }
                    vis[v-l]=1;
                    arr[v-l]=arr[v]+1;
                    enq(v-l);
                }
            }
        }
        if(flag==0)
        {
            cout<<"uh-oh!"<<endl;
        }
    }
}
