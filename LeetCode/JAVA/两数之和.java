/*
题目：两数之和
题目思路：遍历数组，利用hash表直接找到该数所需另一个数是否存在该数组中。
*/

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mun = new HashMap<>();
        int i;
        for (i = 0;i < nums.length;i++) {
            mun.put(nums[i], i);
        }
        for (i = 0; i< nums.length;i++) {
            int temp = target - nums[i];
            if (mun.containsKey(temp)&& mun.get(temp) != i) {
                return new int[] {i, mun.get(temp)};
            }
        }
        throw new  IllegalArgumentException("No two sum solution");
    }
}