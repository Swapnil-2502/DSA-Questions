#include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here.    
    int n = arr.size();
	int low = 0;
	int high = n-1;
	int ans = INT_MAX;
    int index;
	while(low<=high){
		
        int mid = (low+high)/2;

        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                index = low;
                ans = arr[low];
            }
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index = low;
                ans = arr[low];
            }
            low = mid+1;
        }
        else{
            high = mid-1;
            if(arr[mid]<ans){
                index = mid;
                ans = arr[mid];
            }
        }
	}
	return index;
    //TC = O(logN);
    //SC = O(1)
}