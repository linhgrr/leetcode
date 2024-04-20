int removeDuplicates(int* nums, int numsSize){
    int l = 0;
    for (int r = 1; r < numsSize; r++){
        if (nums[r] != nums[l] || (l >= 1 && nums[r] == nums[l] && nums[r] != nums[l-1])){
            l++;
            nums[l] = nums[r];
        } else if (l == 0 && nums[r] == nums[r]) l++;
    }
    return l+1;
}