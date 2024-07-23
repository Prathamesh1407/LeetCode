//TC:O(log2(sum-maxi)*N)
int studentsCount(vector<int>& arr, int n, int m,int maxPages)
{
    int studentsCount=1,sum=0;
    for(auto val:arr)
    {
        if(sum+val<=maxPages)
        {
            sum+=val;
        }
        else
        {
            studentsCount++;
            sum=val;
        }
    }
    return studentsCount;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int sum=0,maxi=arr[0];
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxi=max(maxi,arr[i]);
    }
    int low=maxi,high=sum;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(studentsCount(arr,n,m,mid)<=m)
        {
            //Means Pages value is more so reduce it
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
