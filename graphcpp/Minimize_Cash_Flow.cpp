#include<queue>
typedef long long ll;
ll getMxCreditIdx(vector<ll>& netAmts, int n){
    ll mxCreditIdx=0;
    for(int i=0; i<n; i++){
        if(netAmts[i]>netAmts[mxCreditIdx]){
            mxCreditIdx=i;
        }
    }
    
    return mxCreditIdx;
}
ll getMxDebitIdx(vector<ll>& netAmts, int n){
    ll miCreditIdx=0;
    for(int i=0; i<n; i++){
        if(netAmts[i]<netAmts[miCreditIdx]){
            miCreditIdx=i;
        }
    }
    
    return miCreditIdx;
}
vector<vector<int>> minCashFlow(vector<vector<int>>& txns, int n){
    vector<ll> netAmts(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            netAmts[j]+=txns[i][j];
            netAmts[i]-=txns[i][j];
        }
    }
    
    vector<vector<int>> res(n, vector<int>(n, 0));
    ll mxCreditIdx=getMxCreditIdx(netAmts, n), mxDebitIdx=getMxDebitIdx(netAmts, n);
    
    while(netAmts[mxCreditIdx]>netAmts[mxDebitIdx]){
        ll miAbs=min(abs(netAmts[mxCreditIdx]), abs(netAmts[mxDebitIdx]));
        netAmts[mxCreditIdx]-=miAbs;
        netAmts[mxDebitIdx]+=miAbs;
        
        res[mxDebitIdx][mxCreditIdx]=miAbs;
        
        mxCreditIdx=getMxCreditIdx(netAmts, n);
        mxDebitIdx=getMxDebitIdx(netAmts, n);
    }
    
    return res;
}
