class Solution {
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    
    int min(int a, int b){
        return a>b?b:a;
    }
    
    int asb(int a){
        return a>0?a:-a;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int s_a = abs(C-A) * abs(D-B);
        int s_b = abs(G-E) * abs(H-F);
        
        if(C<=E || G <= A)
            return s_a + s_b;
        if(B>=H || D<=F)
            return s_a + s_b;
            
        int s_common = abs((min(H, D)-max(B, F)) * (min(C, G) - max(A, E)));
        return s_a + s_b - s_common;
    }
};
