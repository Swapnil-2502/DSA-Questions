#include<bits/stdc++.h>
bool canwePlace(int minDist,int cows, vector<int> &arr){
    int cntCows = 1, last = arr[0]; //Index of first cows will alaways be zero

    for(int i=1;i<arr.size();i++){
        
        if((arr[i] - last) >= minDist){
            cntCows++;
            last = arr[i];
        }

        if(cntCows >= cows) return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end()); //Sorting array

    // //Range will be (1,max-min)
    // int minElement = stalls[0];
    // int maxElement = stalls[stalls.size()-1];


    // for(int i=1;i<=(maxElement - minElement);i++){

    //     if(canwePlace(i,k,stalls)) continue;
    //     else return (i-1);
    // }
    // //TC = O(max-min) * O(n)
    // //SC = O(1)

    //Using Binary Search
    int n = stalls.size();

    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while(low<=high){
        int mid = (low+high)/2;

        if(canwePlace(mid, k, stalls)) low = mid+1;
        else high = mid-1;
    }

    return high;
    //TC = O(nlogn) + (log bas2 (high) * O(n))
}