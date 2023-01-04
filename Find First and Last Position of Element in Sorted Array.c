
int Lower(int target,int mid,int* nums)
{
    if(mid==0||*(nums+mid-1)!=*(nums+mid-1))
    {
        return mid;
    }
    return Lower (target,mid-1,nums);
}
while(mid>-1)
{
    if(mid==0||nums[mid-1]!=nums[mid])
       array[0]=mid;
    else
    mid--;
}
while(mid<=nums.length)
{
    if(mid==nums.length||nums[mid+1]!=nums[mid])
       array[0]=mid;
    else
    mid++;
}
int Upper(int target,int mid,int* nums,int n)
{
    if(mid==n||*(nums+mid-1)!=*(nums+mid+1))
    {
        return mid;
    }
    return Upper(target,mid+1,nums,n)
}

