1、mudo一直推崇的是oneLoop pre thread, eventLoop 指的是poll，eventLoopThreadPool，指多个事件循环主题；
2、mudo网络库只是实现了基于io多路复用的库，并没有解决网路编程中的，粘包，分包问题，这些在CSDN上已经总结，且mudo书上也有讨论；
3、mudo学习的重点：base文件夹的实现方式，有利于提高自己对象编程的能力；对象池的实现，有助于帮助理解多线程编程对象的声明周期；
mudo库的实现有助于理解io多路复用，这个只是库，并不是reactor模型；
4、总结网络编程的面试题；
