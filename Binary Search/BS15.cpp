//Least Capacity of ship packages within D days
int func(vector<int> &weights, int cap){

    int days = 1, loads = 0;

    for(auto it : weights){

        if(loads + it > cap){
            days++;
            loads = it;
        }
        else{
            loads += it;
        }
    }

    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    
    int maxiElement = INT_MIN;

    for(auto it : weights){
        if(it > maxiElement) maxiElement = it;
    }

    int sumOfElements = 0;

    for(auto it : weights){
        sumOfElements += it;
    }

    int low = maxiElement;
    int high = sumOfElements;

    while(low<=high){
        int mid = (low+high)/2;

        int days = func(weights,mid);

        if(days > d){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return low;
}

//Tc = Log base 2 (low-high+1) * O(n)
//sc = O(1)
