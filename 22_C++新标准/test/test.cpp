#include <windows.h>
#include <iostream>
// 窗口名称
const char* WECHAT_WINDOW_NAME = "企业微信";
const char* BAILING_WINDOW_NAME = "ZYBWeworkHelper";
// 定位窗口并获取其句柄
HWND FindWindowByName(const char* windowName) {
    HWND hwnd = FindWindowA(NULL, windowName); // 使用 FindWindowA
    if (!hwnd) {
        std::cerr << "无法找到窗口: " << windowName << std::endl;
    }
    return hwnd;
}
// 主程序
int main() {
    HWND hwndWeChat = FindWindowByName(WECHAT_WINDOW_NAME);
    HWND hwndBailing = FindWindowByName(BAILING_WINDOW_NAME);
    if (!hwndWeChat || !hwndBailing) {
        return -1;
    }
    std::cout << "企业微信窗口句柄: " << hwndWeChat << std::endl;
    std::cout << "百灵助手窗口句柄: " << hwndBailing << std::endl;
    return 0;
}
