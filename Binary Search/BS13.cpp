#include<bits/stdc++.h>

int findLow(vector<int> arr){
	int mini = INT_MAX;

	for(int i=0;i<arr.size();i++){
		mini = min(mini,arr[i]);
	}
	return mini;
}

int findHigh(vector<int> arr){
	int maxi = INT_MIN;

	for(int i=0;i<arr.size();i++){
		maxi = max(maxi,arr[i]);
	}
	return maxi;
}

int findNoofBouquets(vector<int> arr, int day,int k){
	int count = 0;

	int NumBouquet = 0;

	for(int i=0;i<arr.size();i++){
		if(arr[i]<=day) count++;
		else{
			NumBouquet += count/k;
			count = 0;
		}
	}
	NumBouquet += count/k;
	return NumBouquet;
}

int roseGarden(vector<int> arr, int k, int m)
{
	//Edge Case
	if(k*m > arr.size()) return -1;

	int low = findLow(arr), high = findHigh(arr);
	int ans = -1;

	while(low<=high){
		int mid = (low+high)/2;

		int NoofBouquets = findNoofBouquets(arr,mid,k);

		if(NoofBouquets >= m){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;
}

//TC = O(N*log(max-min+1))
