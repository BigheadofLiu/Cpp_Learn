// 这是一个调试测试文件，您可以直接运行检测配置是否生效
// 若配置任然无法调试，请查阅README_inProject.md

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("Congratulasions! It works!\n");
//     system("pause");
//     return 0;
// }
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
    }
};
