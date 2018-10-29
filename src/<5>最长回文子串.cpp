给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"



class Solution {
public:
    string longestPalindrome(string s) {
        //形参是字符串s，返回一个最长回文子字符串
        
        /*************************
        //这道题类似于找最长无重复字符的字串，当时用的是哈希表方法
        //开始：
        int m[256] = {0};        //哈希表
        int maxnum = 0,left = 0;
        string s1;              //这个是最后用于返回的
        //拿babcad举例：
        for ( int i = 0; i < s.size(); i++){
            if ( m[s[i]] = 0 || m[s[i]] < left){
                //maxnum = max(maxnum, i - left + 1);
                s1[i] = s [i];
            }
            else{
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        虽然类似于那道题，可是却完全不一样
        这里的回文，回文是一个正读和反读都相同的字符串，aba就是一个回文，但是abca就不是一个回文。
        *********************/
        
        //利用网上的动态规划方法：
        /****动态规划的套路是用一个多维的数组保存中间结果，在计算时使用中间结果加速计算。所以动态规划的空间复杂度一般比较大。
        用一二维数组table保存中间结果，table[i][j]表示[i, j]的子串是否是回文。*****/
        /****************
        
        *****************/
        //拿ababa来举例：
        int longestBegin = 0;
        int longestLength = 1;
        
        bool table[1000][1000] = {false};   //用于保存中间结果，三字母需要用到一字母和二字母，四字母需要用到三字母，五字母需要用到四字母。。。
                                            //这个动态规划的解法核心就是，只要中间是回文，两头字符相等，那么这个字串就是回文。
                                            //所以为了避免重复计算，有必要保存中间的结果。
        
        if (s.empty())
            return s;                       //直接拿到vs去运行，就发现可以通过，但是这里的平台太老，需要加一个非空的判断
        
        /*
        测试：
        int main(){
        string s;
        for (int i = 0; i < 1000; i++)
            s += 'a';
        cout << Solution().longestPalindrome(s) << endl;
        }
        */
        
        for (int i = 0; i < s.size(); ++i) {   //初始化一字母的回文，这里定义了ababa每个字母都是true(也就是回文),longestLength = 1
            table[i][i] = true;                //true就代表是回文。
        }
        
        for (int i = 0; i < s.size() - 1; ++i) {  //二字母回文，看看，ab，ba，ab,ba,两个两个的字母是否有回文，是的话就ture，而且longestLength为2
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;           //为了保证数组不越界，这里要确保i + 1 < s.size(),也就是i < s.size() - 1
                longestBegin = i;
                longestLength = 2;
            }
        }
        
        for (int len = 3; len < s.size() + 1; ++len) {   //找到所有三字母回文，并以此类推，++len,四字母，五字母，等等一直到s.size（）.
            for (int i = 0; i < s.size() - len + 1; ++i) {
                if (table[i + 1][i + len - 2] == true && s[i] == s[i + len - 1]) { //判断该len字母是否是回文
                    //拿三个字母举例，如果中间的是true，两头相等，那么这个三字母就是回文。                                                                           //ada,首先d要是回文，然后a=a，两头相等。这个三字母就是回文，那么longestLength = 3
                    
                    //判断四字母的时候，会用到三字母，是否是回文，必须是才行。table[i + 1][i + len - 2]，table[1,2]必须是回文，且两头相等
                    //adda来说，首先dd要是回文，然后a=a，两头相等。这个四字母就是回文，那么longestLength = 4
                    //如果是abca，首先bc不是回文，所以这个四字母不是回文。
                    
                    //依次类推下去，直到全部判断完。
                    table[i][i + len - 1] = true;   //保存中间结果，给下一个用
                    longestLength = len;
                    longestBegin = i;
                }
            }
        }
        
        return s.substr(longestBegin, longestLength); //substr(),返回一个从指定位置开始的指定长度的子字符串
        
        //时间复杂度O(n^2),空间复杂度O(n^2),用于存储表table[][]。
        }
};
