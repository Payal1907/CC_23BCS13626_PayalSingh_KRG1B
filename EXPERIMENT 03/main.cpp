class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        ll l = min(a,b);
        ll r = (1LL*n*min(a,b));
        ll lcm = (a*b)/std::gcd(a,b);
        ll res = 0;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll nums = mid/b + mid/a - mid/lcm;
            if(nums<n) l=mid+1;
            else{
                res=mid%mod;
                r=mid-1;
            }
        }
        return res;
    }
};