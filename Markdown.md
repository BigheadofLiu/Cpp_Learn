# markdown练习  

### 1.标题
	# 标题 
	# 一级标题 
	## 二级标题 
	### 三级标题 
	#### #号与文本之间用空格隔开  

### 2.字体
	*斜体*
	**粗体**
	***斜粗体***
	~我被删除了~
	<u>我是下划线</u>

### 3.段落（换行）
	这是第一段文字  
	这是第二段文字（后面跟两个空格表示换行)  
	这是第三段文字（可以使用标识符<br>换行）<br>
	这是第四段文字  
	（也可以通过空一行进行换行）

	这是第五段文字

### 4.引用
>这是一个引用<br>
转载请标明出处：
https://tool.lu/markdown/<br>

>>>这是一个嵌套引用(感觉没有卵用)

### 5.超链接
[这是我的链接地址:](https://tool.lu/markdown/)
<https://tool.lu/markdown/>

### 6.图片
![这是一张图片示例](https://img-blog.csdnimg.cn/8bbc653f3f854023856762ed2c8e43e9.png)

### 7.列表
7.1 无序列表
+ 列表1
+ 列表2
+ 列表3
 
7.2 有序列表
1. 列表1
2. 列表2
3. 列表3

7.3 列表层级嵌套
+ 列表1
	+ 列表2
		+ 子列表
		+ 子列表
	+ 列表3
	+ 列表4
+ 列表5

### 8.分割线
你好，我是分割线
(需与正文留一个空行)

---
---
---

### 9.代码块
```
#include"iostream"
#include"math.h"
#include<ctime>
using namespace std;
//猜数字游戏 使用while嵌套if
int main(){
    srand(time(0));    //初始化随机数种子，避免生成伪随机数
    int a = rand() % 100 + 1; //随机生成1-100内的数字
    cout<<a<<endl;
    int b;
    bool tag=true;
    while(tag){
    cout<<"enter your number"<<endl;
    cin>>b;
    if(b<a)
    {
        cout<<"猜小了"<<endl;
        continue;
        /* code */
    }else if(b>a){
        cout<<"猜大了"<<endl;
        continue;
        
    }else{
        cout<<"猜对了"<<endl;
        tag=false;
    }
    }
    return 0;
}
```
### 10.表格
| 项目        | 价格   |  数量  |
| --------:   | -----:  | :----  |
| 计算机     | \$1600 |   5     |
| 手机        |   \$12   |   12   |
| 管线        |    \$1    |  234  |

|名称       |单价   |数量    |
|:--------- |:------   |:----|
|锐刻5代    | \$198|58|
|
|

### 11.脚注
我是脚注一号[^1],我是脚注二号[^2],

[^1]:我是脚注1
[^2]:我是脚注2

使用 Markdown[^1]可以效率的书写文档, 直接转换成 HTML[^2], 你可以使用 Typora[^T] 编辑器进行书写。
[^1]:Markdown是一种纯文本标记语言
[^2]:HyperText Markup Language 超文本标记语言
[^T]:NEW WAY TO READ & WRITE MARKDOWN.

### 12.特殊符号
略

### 13.高级应用
13.1 待办
	
- [ ] 待办1
- [x] 待办2
- [ ] 待办3	
- [ ] 待办4

13.2 公式
$$E=mc^2$$
$$\sum_{i=1}^n a_i=0$$
$$\sum_{i=1}^n $$








