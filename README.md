https://github.com/jyf-111/CompilationPrinciple
### 项目使用xmake构建
和老牌的C++ 构建工具cmake make相比语法简洁易懂
用lua描述工程非常方便
CMAKE的语法又臭又长
使用`xmake project -k cmake`生成CMakeList.txt转化为cmake项目

C++最低版本C++17
-std=c++17

编译 :`xmake`
运行
- `xmake run wordAnalysis`
- `xmake run syntaxAnalysis`

分为四个子项目 wordAnalysis syntaxAnalysis 

- 词法分析 主要是每读一个单词转移到一个状态,做相应处理
- 递归子程序 利用了栈,主要难点是处理回溯的部分
