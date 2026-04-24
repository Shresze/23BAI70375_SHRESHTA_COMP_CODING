class Solution {
public:
#define mod 1000000007
    int nthMagicalNumber(int n, int a, int b) {

        long lcm=a*b/__gcd(a,b);
        long l=min(a,b);
        long h=n*l;
        while(l<h){
            long m=l+((h-l)/2);
            long c=m/a+m/b-m/lcm;
            if(c<n){
                l=m+1;
            }
            else{
                h=m;
            }
        }
        return l%mod;
    }
};
