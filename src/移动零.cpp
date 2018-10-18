给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
  必须在原数组上操作，不能拷贝额外的数组。
  尽量减少操作次数。

class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    void moveZeroes(vector<int>& nums) {
        //void该函数没有return
        //形参是传入一个vector数组
        int k = 0;  //nums中，[0...k)的元素均为非0元素
        
        //遍历到第i个元素后，保证[0...i]中全为非0元素
        //都按照顺序排列在[0...k]中
        //同时，[k...i]为0
        
        for(int i = 0;i < nums.size(); i++){
            if (nums[i])
                if(i != k)   //防止数组中全是非0的元素，还依然进行交换操作
                    swap(nums[i], nums[k++]);     //先交换nums[i]和nums[k]，然后再k++
                else     //即 i = k,自己和自己不需要进行交换操作
                    k++;
        }
    }
};
