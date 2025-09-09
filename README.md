Code challenge: Jacto (C++/Qt QML)
===========
---
### Description
This project is a simple IPC application, build with C++11, CMake, Qt 6.7, QML, QtDBus.

- EnviarApp sends message over DBus.
- ReceberApp receives DBus messages.

### Compile requirements
- g++ (C++ >= 11)
- CMake >= 3.16
- Qt 6.7

### How to compile
```
cmake -Bbuild
cmake --build build
```

### How to run

**Run sender** ``` ./EnviarApp/build/appEnviarApp ```

**Run receiver** ``` ./ReceberApp/build/appReceberApp ```

### See also
- [*QtDBus Chat Example*](https://doc.qt.io/qt-6/qtdbus-chat-example.html)
- [*QtDBus ComplexPingPong*](https://doc.qt.io/qt-6/qtdbus-complexpingpong-example.html)
