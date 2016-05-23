class Solution {
public:
    int get_bit(string a, int index){
        if(index < 0)
            return 0;
        else
            return a[index]-'0';
    }

    string addBinary(string a, string b) {
        string str;
        int size_a = a.size();
        int size_b = b.size();
        int size_max = size_a>size_b?size_a:size_b;
        int overflow = 0;
        for(int i=0; i<size_max; i++){
            int bit_a = get_bit(a, size_a-i-1);
            int bit_b = get_bit(b, size_b-i-1);
            int sum = bit_a+bit_b+overflow;
            if(sum >=2){
                sum -= 2;
                overflow = 1;
            } else{
                overflow = 0;
            }
            str.insert(0, 1, sum+'0');
        }
        
        if(overflow == 1)
            str.insert(0, 1, '1');
        return str;
    }   
};
