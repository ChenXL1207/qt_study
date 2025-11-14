# Qt Study

这是一个用于学习 Qt 框架的项目，包含了 Qt 核心功能的示例代码，适合初学者和进阶开发者参考。

## 项目结构

- `demo/chapter03/sample_3_1`：第三章的示例项目，演示了 Qt 的元对象系统、属性系统和信号与槽机制。
  - `main.cpp`：程序入口。
  - `mainwindow.*`：主窗口类，展示 UI 基本结构。
  - `qperson.*`：一个继承自 `QObject` 的类，演示属性、信号和槽的使用。
  - `ui_page1.*`：自定义 UI 页面，包含按钮和交互逻辑。
- 构建目录 `build-sample_3_1-Desktop_Qt_5_12_8_MinGW_64_bit-Debug`：编译生成的文件。

## 核心特性

- **元对象系统 (Meta-Object System)**：Qt 的核心机制，支持运行时类型信息（RTTI）、属性系统和信号与槽。
- **信号与槽 (Signals & Slots)**：用于对象间通信的机制，实现事件驱动编程。
- **属性系统 (Property System)**：允许对象暴露可读写的属性，便于集成到 Qt Designer 或 QML 中。

## 使用说明

### 构建项目

确保已安装 Qt 5.12.8 或更高版本的开发环境。使用 Qt Creator 打开 `sample_3_1.pro` 文件，然后进行构建。

### 功能演示

- `QPerson` 类展示了如何定义属性和自定义信号。
- `ui_page1` 类演示了如何绑定按钮点击事件，并与 `QPerson` 进行交互。
- 主窗口提供 UI 控件，用于测试 Qt 的元对象特性。

## 学习资源

- [Qt 官方文档](https://doc.qt.io/)
- 《C++ GUI Programming with Qt 5》
- Qt Creator 快捷键与使用技巧（见 `note.md`）

## 版权与许可

本项目基于 MIT 许可证发布。详细信息请查看项目根目录下的 LICENSE 文件。

---

如有任何问题或建议，欢迎提交 issue 或参与贡献！