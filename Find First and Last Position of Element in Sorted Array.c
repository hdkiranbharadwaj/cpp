
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
    
 while(mid>-1)
{
    if(mid==0||*(num+mid-1)!=*(nums+mid)){
       *(array)=mid;break;}
    else
    mid--;
}
while(mid<numsSize)
{
    if(mid==numsSize-1||*(num+mid+1)!=*(nums+mid))
    {
       *(array+1)=mid; break;
    }
    else
    mid++;
}
    *returnSize=2;
    return array;

}
