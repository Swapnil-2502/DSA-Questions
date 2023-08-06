#include <bits/stdc++.h> 
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
int upperBound(vector<int> &arr, int n, int x){
	
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
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    //Brute
    // int first = -1;
    // int last = -1;

    // for(int i=0;i<n;i++){
    //     if(arr[i] == k){
    //         if(first == -1){
    //             first = i;
    //             last = i;
    //         }
    //         else if(first != -1) last = i;
    //     }
    // }
    // return {first,last};
    //SC = O(1);
    //TC = O(N);

    //Improve TC = O(N)
    //Apply Binary Search O(logN);
    int lb = lowerBound(arr,n,k);
    if( lb == n || arr[lb] != k) return {-1,-1};
    return {lb,upperBound(arr,n,k)-1};
    
    //TC = O(logN);
    //SC = O(1);
}

//Use the above code to find the Number of occurrence

int count(vector<int>& arr, int n, int x) {
	pair<int,int> ans = firstAndLastPosition(arr,n,x);
	if(ans.first == -1) return 0;
	return (ans.second - ans.first + 1);
}