//link:https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1
int countTriplet(int arr[], int n){
    sort(arr,arr+n);
    reverse(arr,arr+n);
    int ans=0;
    for(int i=0;i<n-2;i++){
        int beg=i+1,end=n-1;
        while(beg<end){
            if(arr[i] == arr[beg] + arr[end]){
                ans++;  
            }
            if(arr[beg] + arr[end] < arr[i])
                end--;
            else
                beg++;
        }
    }
    return ans;
}