

int minOperations(int* nums, int numsSize){
    int step = 0;
    for (int i = 1; i < numsSize; i++){
        if (nums[i] <= nums[i-1]){
            int plus = nums[i-1] - nums[i] +1;
            nums[i] += plus;
            step += plus;
        }
    }
    return step;
}