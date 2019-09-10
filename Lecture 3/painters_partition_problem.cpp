#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int c,n,sum;
bool check(int mid){
    int p=c;
    int x=0;
    int i=0;
    while(i<n){
        // cout << i << endl;
        x+=v[i];
        if(x>=mid){
            x=0;
            if(i>0)
            i--;
            p--;
            if(p==0){
                return true;
            }
        }
        i++;
    }
    return false;
}
void find(int l){
    // cout <<l <<endl;
    int x=0;
    int i=0;
    int max=0;
    for(auto x : v){
        if(x>max){
            max=x;
        }
    }
    while(i<n){
        x+=v[i];    
        if(x>=l){
            x-=v[i];
            if(x>max){
                max=x;
             }   
            x=0;
            i--;
        }
        i++;
    }    
    cout <<max << endl;
}
void go(int l ,int r){
    if(l>=r){
        // cout << l<<endl;
       find(l);
        return ;
    }
    int mid=(r+l)/2;
    // cout << mid ;
    if(!check(mid)){
        // cout << "left " << l<<endl;
        go(l,mid);
    }else{
        // cout << "right "<<r << endl;
        go(mid+1,r);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> c >> n;
        v.resize(n,0);
        sum=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum+=v[i];
        }
    }
    sort(v.begin(),v.end());
    // for(auto x:v2){
    //     cout << x << endl ;
    // }
    go(0,sum);
    return 0;
}
