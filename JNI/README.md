参考链接：
1. JNI 学习笔记：<https://www.jianshu.com/p/f6e3dd8edb13>
2. JNI 学习笔记——通过RegisterNatives注册原生方法：<https://www.jianshu.com/p/216a41352fd8>
Steps:
1. javac XXX.java
2. gcc XXX.c -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" -fPIC -shared -o lib<System.loadlibrary传入的参数>.so
3. java -Djava.library.path=. XXX
