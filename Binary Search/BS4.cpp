int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int low = 0;
    int high = n-1;

    while(low<=high){

        int mid = (low+high)/2;

        if(arr[mid]==k) return mid;

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
    return -1;

    Tc = O(logN);
    Sc = O(1);
}
