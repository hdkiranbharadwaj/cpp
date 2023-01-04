class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] array=new int[2];
int flag=0;
int end=nums.length-1;
int start=0;
int mid;
    if(nums.length==0)
        goto L;
while(start<=end)
{
    mid=(end+start)/2;
    if(nums[mid]==target) {printf("%d",mid); flag=1;break;}
    else if(target>nums[mid]) start=mid+1;
    else end=mid-1;
}
if(nums.length==1&&nums[0]==target)
{ printf("hi");
    array[0]=array[1]=0; 
     return array; 
}

    if(flag==0) {
        printf("hi");
   L:  array[0]=-1;
    array[1]=-1; 
     return array; 
     }

     
    }
}
