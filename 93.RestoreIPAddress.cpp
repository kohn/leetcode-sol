class Solution {
public:

    bool check_part(string s){
        if(s.size() > 1 && s[0] == '0') return false;
        if(s.size() == 3){
            if(s[0] > '2' || s[0] == '2' && s[1] > '5' || s[0]=='2' && s[1]=='5' && s[2]>'5')
                return false;
        }
        return true;
    }

    vector<string> restore(string &s, int start_pos, int n){
        vector<string> ret;
        if(s.size()-start_pos>n*3 || s.size() == start_pos || n==0)
            return ret;
        string part = "";
        if(n == 1){
            string ip = s.substr(start_pos);
            if(check_part(ip)){
                ret.push_back(ip);
            }
        } else {
            for(int i=0; i<3 && start_pos+i<s.size(); i++){
                part.push_back(s[start_pos+i]);
                if(!check_part(part))
                    break;
                vector<string> next_ret = restore(s, start_pos+i+1, n-1);
                for(int j=0; j<next_ret.size(); j++){
                    string ip = part+"."+next_ret[j];
                    ret.push_back(ip);
                }
            }
        }
        return ret;
    }
    vector<string> restoreIpAddresses(string s) {
        return restore(s, 0, 4);
    }
};
