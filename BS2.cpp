//Lower Bound
int lowerBound(vector<int> arr, int n, int x) {
	
	int ans = n;

	int low = 0;
	int high = n-1;

	while(low <= high){
		int mid = (low + high)/2;

        //May be an ans
		if(arr[mid] >= x){
			ans = mid;
            
			high = mid-1; //Look for more small index in left 
		}
		else low = mid+1; //Look for right 
	}

	return ans;
}
//TC = O(log n)
//SC = O(1)

//Upper Bound
int upperBound(vector<int> &arr, int x, int n){
	
	int ans = n;

	int low = 0;
	int high = n-1;

	while(low <= high){
		int mid = (low + high)/2;

		if(arr[mid] > x){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}

	return ans;
}
//TC = O(log n)
//SC = O(1)