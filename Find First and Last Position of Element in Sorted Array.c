class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] array=new int[2];
int flag=0;
int end=nums.length-1;
int start=0;
int mid=0;
    if(nums.length==0)
        {
            array[0]=-1;
    array[1]=-1; 
     return array; 
        }
while(start<=end)
{
    mid=(end+start)/2;
    if(nums[mid]==target) { flag=1;break;}
    else if(target>nums[mid]) start=mid+1;
    else end=mid-1;
}
if(nums.length==1&&nums[0]==target)
{ 
    array[0]=array[1]=0; 
     return array; 
}

    if(flag==0) {
        
   array[0]=-1;
    array[1]=-1; 
     return array; 
     }
while(mid>-1)
{
    if(mid==0||nums[mid-1]!=nums[mid])
       {array[0]=mid;
       break;}
    else
    mid--;
}
while(mid<nums.length)
{
    if(mid==nums.length-1)
      { array[1]=mid;
      break;}
    if((nums[mid+1]!=nums[mid]))
    {
        array[1]=mid;
      break;
    }
    else
    mid++;
}
     return array;
    }
}
