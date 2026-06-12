class Solution 
{
 public:vector<int> singleNumber(vector<int>& nums) 
 {
  long xorAll = 0;
  for (int num : nums) 
    xorAll ^= num;
  long diffBit = xorAll & (-xorAll);
  int num1 = 0, num2 = 0;
  for (int num : nums) 
  {
   if (num & diffBit)
    num1 ^= num;
   else
    num2 ^= num;
  }
  return {num1, num2};
 }
};