class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=1;
        long long s=0;
        for (long long b:batteries){
            s+=b;
        }
        long long a=0;
        long long r=s/n;
        while (l<=r){
            long long m=l+(r-l)/2;
            if(check(n,batteries,m)){
                a=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return a;
    }

    bool check(int n,vector<int>& batteries,long long t) {
        long long to=0;
        for (long long b:batteries) {
            to+=min(b,t);
        }
        
        return to>=t*n;
    }

    
};
