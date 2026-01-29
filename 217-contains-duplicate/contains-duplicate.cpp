class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size()); // avoids rehashing
        seen.max_load_factor(0.7); // faster lookups
        
        for(int n : nums){
            if(seen.count(n)) return true;
            seen.insert(n);
        }
        return false;
    }
};
