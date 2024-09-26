// 这是一个调试测试文件，您可以直接运行检测配置是否生效
// 若配置任然无法调试，请查阅README_inProject.md

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("Congratulasions! It works!\n");
//     system("pause");
//     return 0;
// }

// #include<vector>
// using namespace std;
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             for(int j=1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     vector<int> v;
//                     v.push_back(i);
//                     v.push_back(j);
//                     return v;
//                 }
//             }
//         }
//     }
// };

// #include <iostream>
// #include <windows.h>
// #include <string>
// #include <vector>

// void AddPathToEnvVariable(const std::string& newPath) {
//     // Get the current PATH environment variable
//     char buffer[32767];
//     DWORD length = GetEnvironmentVariableA("PATH", buffer, sizeof(buffer));
//     if (length == 0) {
//         std::cerr << "Failed to get PATH environment variable." << std::endl;
//         return;
//     }

//     std::string currentPath(buffer);
//     std::string newPathStr = currentPath + ";" + newPath;

//     // Set the new PATH environment variable
//     if (SetEnvironmentVariableA("PATH", newPathStr.c_str()) == 0) {
//         std::cerr << "Failed to set PATH environment variable." << std::endl;
//     } else {
//         std::cout << "Path added successfully!" << std::endl;
//     }
// }

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         std::cerr << "Usage: AddPathToEnv.exe <path_to_add>" << std::endl;
//         return 1;
//     }

//     std::string pathToAdd = argv[1];
//     AddPathToEnvVariable(pathToAdd);
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.
}