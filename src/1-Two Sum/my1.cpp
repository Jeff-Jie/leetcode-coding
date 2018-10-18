class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //描述一下，twoSum函数，返回类型是一个int数组容器
        //有两个形参，分别是int数组容器的引用，即传入一个数组，以及需要相加和的特定值
        
        //先显示传入的数组的内容
        for(vector<int>::iterator iter = nums.begin();iter != nums.end();iter++){
            cout << *iter << " ";
        }
        
        //我们最后需要返回哪两个数相加等于特定值的下标，也就是那两个数的下标，要把他们放到一个数组中，最后返回类型是vector<int>
        //所以我们先创建一个数组容器用来存放这两个下标：
        vector<int> arr;
        
        //让数组中两个数依次相加
        int n = nums.size();   //数组元素个数
        int i,j;            //用于遍历数组的
        int first,second;  //用于保存相加等于特定值的两个数的下标
        int s = 0;       //设置一个找到的标志
        for(i = 0;i < n -1 && s == 0;i++)
            for(j = 1;j < n && s == 0;j++)
                if(nums[i] + nums[j] == target){
                    first = i;
                    second = j;
                    s = 1;
                }
        //把找到的两个下标放进最后返回的数组容器中
        //注意,找到下标之后，又会执行一次i++，j++，所以出来需要i-1,j-1
        arr.push_back(i -1);
        arr.push_back(j -1);
        
        return arr;
    }
};
