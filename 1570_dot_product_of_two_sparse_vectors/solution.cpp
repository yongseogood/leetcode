class SparseVector {
public:
    
    SparseVector(vector<int> &nums) : nums_ {nums} {
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        
        for(int i = 0; i < nums_.size() && vec.nums_.size() ; ++i)
            res += nums_[i] * vec.nums_[i];
        
        return res;
    }
public:
    vector<int> nums_;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
