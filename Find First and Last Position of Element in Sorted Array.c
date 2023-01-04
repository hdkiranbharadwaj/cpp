int* searchRange(int* nums, int numsSize, int target, int* returnSize){
int* array=(int*)malloc(2*sizeof(int));
int end=numsSize-1;
int start=0;
int mid;
while(start<end)
{
    mid=(end+start)/2;
    if(mid==target) break;
    else if(target>*(nums+mid)) low=mid+1;
    else end=mid-1;
}
    
}
int Lower(int target,int mid,int* nums)
{
    if(mid==0||*(nums+mid-1)!=*(nums+mid-1))
    {
        return mid;
    }
    return Lower (target,mid-1,nums);
}
