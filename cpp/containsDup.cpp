//using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> e;
        for(int i = 0; i < nums.size(); i++){
            if(e[nums[i]]){
                return true;
            }else{
                e[nums[i]] = 1;
            }
        }
        return false;
    }
};