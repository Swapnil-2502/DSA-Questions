int findMin(vector<int>& arr)
{
	int n = arr.size();
	int low = 0;
	int high = n-1;
	int mini = INT_MAX;

	while(low<=high){
		int mid = (low+high)/2;

		mini = min(arr[mid],mini);

		if(arr[mid]>arr[low]){
			mini = min(arr[low],mini);
			low = mid+1;
		}
		else{
			mini = min(arr[high],mini);
			high = mid-1;
		}
	}
	return mini;
	//TC = O(logN);
	//SC = O(1);
}