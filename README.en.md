# Qt Study

This is a project designed for learning the Qt framework, containing example code that demonstrates Qt's core features, suitable for both beginners and advanced developers.

## Project Structure

- `demo/chapter03/sample_3_1`: Example project for Chapter 3, illustrating Qt's meta-object system, property system, and signals & slots.
  - `main.cpp`: Program entry point.
  - `mainwindow.*`: Main window class demonstrating the basic UI structure.
  - `qperson.*`: A class inheriting from `QObject`, demonstrating the use of properties, signals, and slots.
  - `ui_page1.*`: A custom UI page containing buttons and interaction logic.
- Build directory `build-sample_3_1-Desktop_Qt_5_12_8_MinGW_64_bit-Debug`: Files generated during compilation.

## Core Features

- **Meta-Object System**: Qt's core mechanism supporting runtime type information (RTTI), the property system, and signals & slots.
- **Signals & Slots**: A mechanism for inter-object communication, enabling event-driven programming.
- **Property System**: Allows objects to expose readable and writable properties, facilitating integration with Qt Designer or QML.

## Usage Instructions

### Building the Project

Ensure that a Qt development environment version 5.12.8 or higher is installed. Open the `sample_3_1.pro` file using Qt Creator and proceed with the build.

### Feature Demonstrations

- The `QPerson` class shows how to define properties and custom signals.
- The `ui_page1` class demonstrates how to bind button click events and interact with `QPerson`.
- The main window provides UI controls for testing Qt's meta-object features.

## Learning Resources

- [Qt Official Documentation](https://doc.qt.io/)
- *C++ GUI Programming with Qt 5*
- Qt Creator shortcuts and usage tips (see `note.md`)

## Copyright and License

This project is released under the MIT License. For details, see the LICENSE file in the project root directory.

---

Feel free to submit an issue or contribute if you have any questions or suggestions!