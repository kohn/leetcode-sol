/**
 * 需要实现的是字符串的加法, 然后乘法转换为单个字符与另一个字符串相乘, 然后将结果加起来.
 * 单个字符的相乘可以偷懒用多次加来实现, 也可以写一个专门的乘法来实现.
 */
class Solution {
public:
    string add(string num1, string num2){
        string result;
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 < len2)
            return add(num2, num1);
        int overflow = 0;
        for(int i=0; i<len1; i++){
            int d;
            if(i>=len2)
                d = num1[len1-1-i]-'0' + overflow;
            else
                d = num2[len2-1-i]-'0' + num1[len1-1-i]-'0' + overflow;
            if(d>=10){
                d -= 10;
                overflow = 1; 
            }else
                overflow = 0;
            result.insert(0, 1, d+'0');
        }
        if(overflow == 1)
            result.insert(0, 1, '1');
        return result;
    }
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 < len2)
            return multiply(num2, num1);
        string res = "0";
        if(len2 == 1){
            for(int i=0; i<num2[0]-'0'; i++)
                res = add(num1, res);
        } else{
            for(int i=0; i<len2; i++){
                string digit;
                digit.push_back(num2[len2-1-i]);
                string tmp = multiply(num1, digit);
                for(int j=0; j<i; j++)
                    tmp.push_back('0');
                res = add(res, tmp);
            }
        }
        return res;
    }
};
