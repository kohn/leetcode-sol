#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int s_length = s.length();
        int max = 0;
        // 遍历字符串
        for(int i=0; i<s_length; i++){
            // 每个'('向stack中push一个0
            if(s[i] == '('){
                sta.push(0);
            }
            else{ // 当遇上')'时, 开始检查stack
                int continue_count = 0;

                while(!sta.empty()){
                    // 如果stack的第一个元素是0, 表示'(', 那就凑成了一
                    // 对, 弹出这个'('然后压入1, 表示此处有一对括号
                    if(sta.top() == 0){
                        sta.pop();
                        sta.push(continue_count + 1);
                        break;
                    }
                    else{       // 如果不是0, 说明是一对或者n对匹配好
                                // 的括号, 就一直pop, 直到遇上一个'(',
                                // 然后压入共有多少个连续匹配的括号对.
                        continue_count += sta.top();
                        sta.pop();
                    }
                }
                // 如果经过上面的检查, 最后stack空了, 说明有一个匹配不
                // 到的')', 另外continue_count还保存着这个')'之前有多
                // 少个连续匹配的括号对, 和max比较一下就行.
                if(sta.empty()){
                    max = continue_count>max?continue_count:max;
                }
            }
        }
        // 遍历完字符串后, 在检查stack中剩余的元素.
        int continue_count = 0;
        while(!sta.empty()){
            if(sta.top() == 0){
                max = continue_count>max?continue_count:max;
                continue_count = 0;
            }
            else{
                continue_count += sta.top();
            }
            sta.pop();
        }
        max = continue_count>max?continue_count:max;
        return max*2;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    cout << s.longestValidParentheses("(()") << endl;
    cout << s.longestValidParentheses("()()()") << endl;
    cout << s.longestValidParentheses("((()()())") << endl;
    return 0;
}
