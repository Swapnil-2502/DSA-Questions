//Iterative Method

int search(vector<int>& nums, int target) {
    int n = nums.size();

    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(target == nums[mid]) return mid;

       else if(target > nums[mid]) low = mid+1;
       else high = mid-1;
    }

    return -1;
}
//TC = O(logn)
//SC = O(1)

//Recursion 
int binarySearch(vector<int>& nums, int target, int low, int high){
    if(low > high) return -1;

    int mid = (low+high)/2;

    if(target == nums[mid]) return mid;

    else if(target > nums[mid]) return binarySearch(nums,target,mid+1,high);

    else return binarySearch(nums,target,low,mid-1);
}   

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    int ans = binarySearch(nums,target,low,high);

    return ans;
}
// //TC = O(logn)
// //SC = O(logn) for auxiliary space