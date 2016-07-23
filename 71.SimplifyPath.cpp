class Solution {
public:
    vector<string> split(string path){
        vector<string> vec;
        string tmp;
        for(int i=0; i<path.size(); i++){
            if(path[i] == '/'){
                if(tmp != ""){
                    vec.push_back(tmp);
                    tmp = "";
                }
            } else 
                tmp.push_back(path[i]);
        }
        if(tmp != "")
            vec.push_back(tmp);
        return vec;
    }

    string simplifyPath(string path) {
        string simple_path;
        vector<string> vec = split(path);
        int parent_count = 0;
        for(int i=vec.size()-1; i>=0; i--){
            if(vec[i] == ".."){
                parent_count++;
            } else if(vec[i] == "."){
                continue;
            } else {
                if(parent_count == 0){
                    vec[i].insert(0, 1, '/');
                    simple_path.insert(0, vec[i]);
                } else{
                    parent_count--;
                }
            }
        }
        if(simple_path == "")
            simple_path = "/";
        return simple_path;
    }
};
