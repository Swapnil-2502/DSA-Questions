bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low<=high){

        int mid = (low+high)/2;

        if(arr[mid]==k) return true;

        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }

        if(arr[low]<=arr[mid]){ //right half is not sorted

            if(arr[low]<=k && k<=arr[mid]){ //Means k is in left half
                high = mid-1;
            }   
            else{
                low = mid+1;
            }

        }else{  //left half is not sorted

            if(arr[mid]<=k && k<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
    //TC = O(logN); 
    //worst case TC = O(N/2);
    //Sc = O(1);
}
