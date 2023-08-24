

int findMaxElement(vector<int>& arr){
	int maxi = INT_MIN;
	for(int i=0;i<arr.size();i++){
		maxi = max(maxi,arr[i]);
	}
	return maxi;
}

int findThresholdValue(vector<int>& arr, int divisor){
	int totalValue = 0;

	for(int i=0;i<arr.size();i++){
		totalValue += ceil((double)arr[i]/(double)divisor);
	}
	return totalValue;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int low = 1, high = findMaxElement(arr);

	//Edge Case
	if(limit == arr.size()) return high;

	while(low<=high){
		int mid = (low+high)/2;

		int thresholdValue = findThresholdValue(arr,mid);
		
		if(thresholdValue <= limit) high = mid-1;
		else low = mid + 1;
	}
	return low;
}
//TC = O(log(max)*N)
