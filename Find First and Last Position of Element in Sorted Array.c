int* searchRange(int* nums, int numsSize, int target, int* returnSize){
int* array=(int*)malloc(2*sizeof(int));
int end=numsSize;
int start=0;
while(start<end)
{
    int mid=(end+start)/2;
    if(mid==target) break;
    else if(target>*(nums+mid)) low=mid+1;
    else end=mid-1;
}
}
