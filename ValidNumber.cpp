#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:

    bool isDigit(char ch){
	return (ch>='0' && ch<='9');
    }
    
    bool isNumber(string s) {
	if(s.size() == 0)
	    return false;

	bool start_flag = false;
	bool e_flag = false;
	bool point_flag = false;
	for(int i=0; i<s.size(); i++){
	    if(s[i] <'0' || s[i] > '9'){
		if(s[i] == 'e' || s[i] == 'E'){
		    if(i-1 < 0)
			return false;
		    
		    if(s[i-1]!='.' && !isDigit(s[i-1]))
			return false;
		    else{
			if(i+1>=s.size())
			    return false;
		    }
		    
		    if(e_flag)
			return false;
		    else
			e_flag = true;

		    int sign_flag = false;
		    bool num_flag = false;
		    for(int j=i+1; j<s.size(); j++){
			if(!sign_flag && (s[j] == '+' || s[j] == '-')){
			    i++;
			    sign_flag = true;
			    if(j+1 >= s.size() || !isDigit(s[j+1]))
				return false;
			    continue;
			}

			if(!num_flag && s[j] == ' ')
			    return false;
			
			if(!isDigit(s[j]) && s[j] != ' ')
			   return false;

			num_flag = true;
		    }
		} else if(s[i] == '.'){
		    if(point_flag)
			return false;
		    else{
			point_flag = true;
		    }

		    if(i-1<0 || !isDigit(s[i-1])){ // before . is not a valid digit
			if((i+1>=s.size() || !isDigit(s[i+1]))) // after . is not a valid digit
			    return false;
		    }
		    start_flag = true;
		}else if(s[i] == ' '){
		    if(!start_flag)
			continue;
		    for(;i<s.size(); i++){
			if(s[i] != ' ')
			    return false;
		    }
		} else if(s[i] == '-' || s[i] == '+'){
		    if(!start_flag)
			start_flag = true;
		    else
			return false;
		} else{
		    return false;
		}
	    } else{
		start_flag = true;
	    }
	}
	return start_flag;
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    assert(sol.isNumber("0"));
    assert(sol.isNumber(" 0.1"));
    assert(sol.isNumber(" abc") == false);
    assert(sol.isNumber("1 a") == false);
    assert(sol.isNumber("2e10"));
    assert(sol.isNumber("e") == false);
    assert(sol.isNumber(".") == false);
    assert(sol.isNumber(" ") == false);
    assert(sol.isNumber("46.e3 "));
    assert(sol.isNumber("6e6.5 ") == false);
    assert(sol.isNumber("5e+6 "));
    assert(sol.isNumber("0e ") == false);
    assert(sol.isNumber("4e+") == false);
    return 0;
}
