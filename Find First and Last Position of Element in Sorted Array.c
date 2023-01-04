/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Lower(int target,int mid,int* nums)
{
    if(mid==0||*(nums+mid-1)!=*(nums+mid-1))
    {
        return mid;
    }
    return Lower (target,mid-1,nums);
}
int Upper(int target,int mid,int* nums,int n)
{
    if(mid==n||*(nums+mid-1)!=*(nums+mid+1))
    {
        return mid;
    }
    return Upper(target,mid+1,nums,n);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
int* array=(int*)malloc(2*sizeof(int));
int end=numsSize-1;
int start=0;
int mid;
    if(numsSize==0)
        goto L;
while(start<end)
{
    mid=(end+start)/2;
    if(mid==target) break;
    else if(target>*(nums+mid)) start=mid+1;
    else end=mid-1;
}
    if(start>end) {
   L:  *(array)=*(array+1)=-1; 
     *returnSize=2;
     return array; 
     }
    *array= Lower(target,mid,nums);
    *(array+1)= Upper(target,mid+1,nums,numsSize);
    return array;
}
