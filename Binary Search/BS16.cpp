int missingK(vector < int > vec, int n, int k) {
    // Write your code here.

    // //Brute solution
    // for(int i=0;i<n;i++){
    //     if(vec[i] <= k) k++;
    //     else break;
    // }
    // return k;
    // //TC = O(N);
    // //SC = O(1);

    //Optimal Solution
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        int missing = (vec[mid] - (mid+1));

        if(missing < k) low = mid+1;
        else high = mid-1;
    }

    return high + k + 1;

    //TC = O(logN)
    //SC = O(1)
}
