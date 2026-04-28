class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l=0,r=n;
        int a=1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m*m<=n){
                a=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        }
        return a;
    }
};
