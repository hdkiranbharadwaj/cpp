/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Lower(int mid,int* nums)
{
    if(mid==0||*(nums+mid)!=*(nums+mid-1))
    {
        return mid;
    }
    else
    return Lower (mid-1,nums);
}
int Upper(int mid,int* nums,int n)
{
    if(mid==n-1||(*(nums+mid)!=*(nums+mid+1)))
    {
        return mid;
    }
    else
    return Upper(mid+1,nums,n);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
int* array=(int*)malloc(2*sizeof(int));
int flag=0;
int end=numsSize-1;
int start=0;
int mid;
    if(numsSize==0)
        goto L;
while(start<=end)
{
    mid=(end+start)/2;
    if(*(nums+mid)==target) {printf("%d",mid); flag=1;break;}
    else if(target>*(nums+mid)) start=mid+1;
    else end=mid-1;
}
if(numsSize==1&&*(nums)==target)
{ printf("hi");
    *(array)=*(array+1)=0; 
     *returnSize=2;
     return array; 
}

    if(flag==0) {
        printf("hi");
   L:  *(array)=*(array+1)=-1; 
     *returnSize=2;
     return array; 
     }
    
    *array= Lower(mid,nums);
    *(array+1)= Upper(mid,nums,numsSize);
    *returnSize=2;
    return array;

}
