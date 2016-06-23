#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void print(vector<int> &v){
    for(auto i:v){
	cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:

    void toDecimal(long long numerator, long long denominator, string &str, map<long long, int> &appear, int index){
	// cout << numerator << " " << denominator << endl;
	if(numerator == 0)
	    return;
	appear[numerator] = index;
	numerator *= 10;
	long long d = numerator/denominator;
	str.push_back(d+'0');
	long long m = numerator%denominator;
	map<long long, int>::iterator iter = appear.find(m);
	if(iter == appear.end())
	    toDecimal(numerator%denominator, denominator, str, appear, index+1);
	else{
	    str.insert(iter->second, 1, '(');
	    str.push_back(')');
	}
    }
    
    string fractionToDecimal(int num, int denom) {
	if(num == 0)
	    return "0";
	long long numerator = num;
	long long denominator = denom;
	int sign = 1;
	if(numerator < 0){
	    numerator = -numerator;
	    sign = -sign;
	}
	if(denominator < 0){
	    denominator = -denominator;
	    sign = -sign;
	}

	long long d = numerator/denominator;
	char buf[32];
	sprintf(buf, "%ld", d);
	long long m = (numerator+denominator)%denominator;
	// cout << d << endl;
	map<long long, int> appear;
	string fraction_part;
	toDecimal(m, denominator, fraction_part, appear, 0);
	string result;
	if(sign == -1)
	    result.push_back('-');
	result.append(buf);
		
	if(m != 0)
	    result.push_back('.');
	result.append(fraction_part);
	return result;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    // cout << sol.fractionToDecimal(0, 2) << endl;
    // cout << sol.fractionToDecimal(1, 2) << endl;
    // cout << sol.fractionToDecimal(1, 9) << endl;
    // cout << sol.fractionToDecimal(10, 1) << endl;
    // cout << sol.fractionToDecimal(1, 7) << endl;
    // cout << sol.fractionToDecimal(3, 72) << endl;
    // cout << sol.fractionToDecimal(-2147483648, -1) << endl;
    // cout << sol.fractionToDecimal(-50, 8) << endl;
    // cout << sol.fractionToDecimal(7, -12) << endl;
    cout << sol.fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
