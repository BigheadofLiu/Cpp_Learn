#include <windows.h>
#include <iostream>

// 百灵助手和企业微信窗口句柄
HWND hwndWeChat = NULL;
HWND hwndBaiLing = NULL;

// 吸附功能
void AttachBaiLingToWeChat() {
    if (!hwndWeChat || !hwndBaiLing) return;

    RECT rect;
    if (GetWindowRect(hwndWeChat, &rect)) {
        int widthBaiLing = 300; // 百灵助手宽度
        int heightBaiLing = rect.bottom - rect.top; // 百灵助手高度和企业微信一致

        // 移动百灵助手窗口到企业微信右侧
        MoveWindow(hwndBaiLing, rect.right, rect.top, widthBaiLing, heightBaiLing, TRUE);
    }
}

// 监听企业微信窗口位置变化
void MonitorWeChatWindow() {
    RECT oldRect = { 0 };
    while (true) {
        Sleep(100); // 定时检测，避免占用过多 CPU

        RECT newRect;
        if (GetWindowRect(hwndWeChat, &newRect)) {
            // 如果位置发生变化
            if (memcmp(&oldRect, &newRect, sizeof(RECT)) != 0) {
                oldRect = newRect;
                AttachBaiLingToWeChat();
            }
        }
    }
}

int main() {
    // 获取企业微信主窗口句柄
    hwndWeChat = FindWindow(L"WeChatMainWndForPC", NULL);
    if (!hwndWeChat) {
        std::wcout << L"未找到企业微信窗口！" << std::endl;
        return -1;
    }

    // 获取百灵助手窗口句柄（假设标题为 "百灵助手"）
    hwndBaiLing = FindWindow(NULL, L"百灵助手");
    if (!hwndBaiLing) {
        std::wcout << L"未找到百灵助手窗口！" << std::endl;
        return -1;
    }

    // 初次吸附
    AttachBaiLingToWeChat();

    // 开启监听线程
    MonitorWeChatWindow();

    return 0;
}
