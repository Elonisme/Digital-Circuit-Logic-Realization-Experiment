# PyQT6 和 Arduino UNO R3 数字电路实验

该仓库包含使用 PyQT6 和 Arduino UNO R3 实现的 9 个常见数字电路实验。这些实验从逻辑的角度来实现了全加器、半加器、编码器、译码器等电路。

仓库地址：[https://github.com/Elonisme/Digital-Circuit-Logic-Realization-Experiment.git](https://github.com/Elonisme/Digital-Circuit-Logic-Realization-Experiment.git)

## 环境要求
要运行这些实验，您需要以下环境：

- Python 3.11
- PyQT6 库
- Arduino UNO R3
- Arduino IDE
- 操作系统：Arch Linux

## 安装步骤

1. 克隆或下载本仓库的代码到您的本地环境。
   ```
   git clone https://github.com/Elonisme/Digital-Circuit-Logic-Realization-Experiment.git
   ```
2. 在计算机上安装 Python 3.11。
3. 安装 PyQT6 库。您可以使用以下命令通过 pip 安装：
   ```
   pip install PyQt6
   ```
4. 连接 Arduino UNO R3 开发板到计算机，并确保安装了 Arduino IDE。
5. 打开 Arduino IDE，将对应的电路图加载到 Arduino IDE 中。
6. 将 Arduino UNO R3 开发板与计算机进行连接，并上传相应的代码到开发板。

## 串口通讯

本项目使用串口进行通讯来与 Arduino UNO R3 开发板进行数据交互。默认串口端口为 `/dev/ttyACM0`。如果您的串口端口不同，您可以根据实际情况在代码中进行相应的修改。

## 电路图

本仓库中的电路图是使用自绘图或维基百科插图制作的，它们提供了与数字电路实验相关的电路图示例。您可以在对应的实验文件夹中找到相应的电路图。

## 实验内容

以下是本仓库中包含的实验内容：

1. 全加器（Full Adder）
2. 半加器（Half Adder）
3. 编码器（Encoder）
4. 译码器（Decoder）
5. 多数表决器（Majority Voter）
6. 优先级多数表决器（Priority Majority Voter）
7. 1 位比较器（1-Bit Comparator）
8. 4-2 编码器（4-to-2 Encoder）
9. 2-4 译码器（2-to-4 Decoder）
10. 4-1 选择器（4-to-1 Selector）
11. 4 位奇偶校验器（4-Bit Parity Checker）

## 使用许可

本软件使用 [GPLv3](https://www.gnu.org/licenses/gpl-3.0.html) 协议。

## 贡献

如果您有任何问题、建议或改进意见，欢迎贡献您的代码或提出问题。请在 GitHub 上提交 issue 或 pull request，我们将非常乐意与您合作。

## 鸣谢

感谢您对该项目的兴趣和支持！祝您学习愉快！

## 参考资料

如果您对数字电路感兴趣，以下是一些有用的参考资料：

- 《数字逻辑与计算机设计》（M. Morris Mano，Michael D. Ciletti 著）
- 《数字系统设计与VHDL》（斯蒂芬·布朗，托马斯·费洛维蒂 著）
