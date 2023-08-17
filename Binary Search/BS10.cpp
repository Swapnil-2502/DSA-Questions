int floorSqrt(int n)
{
    // Write your code here.

    //linear search TC = O(N)
    // int ans = 1;
    // for(int i=1;i<=n;i++){
    //     if(i*i<=n) ans = i;
    //     else break;
    // }
    // return ans;

    //Binary Search TC = O(logn)
    int low = 1, high = n;

    while(low<=high){
        long long mid = low + (high-low)/2;

        long long currSqr = mid*mid;

        if(currSqr <= n) low = mid+1;
        else high = mid-1;
    }
    return high;
}
