给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。


//自己的思考
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //给定一个字符串s，返回一个整型数字（不含有重复字符的最长字串的长度）
        //那我们从字符串的第一个字符开始，一直遍历到'/0'
        //问题是怎么访问字符串的第一个字符：s[0],即字符串第一个字符
        
        int i = 0;
        int j = i + 1;
        int num = 1;
        int maxnum = num;   //不含有重复字符的最长字串长度为maxnum
        while (s[i] != '/0'){
            while (i < strlen(s.c_str()) && s[j] != s[i] && s[j] != '/0'){ //我比较了第二个不等于第一个，第三个只和第二个比较一下就行了，不用跟第一个再比
                                                    //strlen(s) 是字符串s的字符个数，不包括结尾的/0，注意下标从0开始，所以是到strlen(s)-1
            
                
            /*注意，这里使用strlen错误，
            s是一个std::string类型的变量，而strlen要求的参数是char*类型的
　　         如果要获取s字符串的长度，std::string自带一个size接口可以满足需求，即int i = s.size()
如果仍要继续使用strlen，则可以使用std::string的c_str接口。该接口返回一个const char*指针，正好可以作为参数传递给strlen,也就是i = strlen(s.c_str())
            */
            
                
                num++;                              //从0开始，第二个字符不等于第一个字符，那么num++
                i++;
            }
            i++;
            if(num > maxnum)
                maxnum = num;
            num = 0;  
        }
        return 0;   
    }
};


网上的方法：

