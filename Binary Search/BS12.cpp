#include<bits/stdc++.h>
int findMax(vector<int> v){
    int maxi = INT_MIN;

    for(int i=0;i<v.size();i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}
//TC = O(N);

long long findHours(vector<int> v, int hours){
    long long totalHours = 0;

    for(int i=0;i<v.size();i++){
        totalHours += ceil((long double)v[i]/(long double)hours);
    }

    return totalHours;
}


int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    while(low<=high){
        int mid = (low + high)/2;

        long long totalHours = findHours(v,mid);

        if(totalHours <= h) high = mid-1;
        else low = mid+1;
    }
    return low;
}

//TC = O(N * log(maxElement))