1、mudo一直推崇的是oneLoop pre thread, eventLoop 指的是poll，eventLoopThreadPool，指多个事件循环主题；可以共用一个eventloop或者，分开使用，发挥多线程编程优点；
2、mudo网络库只是实现了基于io多路复用的库，并没有解决网路编程中的，粘包，分包问题（处理分包时一定要使用while，且数据判断要copy），mudo多线程编程7.3对分包有讨论，这些在CSDN上已经总结，且mudo书上也有讨论；
3、mudo学习的重点：base文件夹的实现方式，有利于提高自己对象编程的能力；对象池的实现，有助于帮助理解多线程编程对象的声明周期；
mudo库的实现有助于理解io多路复用，这个只是库，并不是reactor模型；
4、总结网络编程的面试题；什么是短连接（链接->数据->关掉链接），什么是长链接（链接->send data->保持链接->send data->...->关掉链接）；
5、socket编程为什么上层一定要有inputbuffer and outputbuffer，看起来buffer越大，约划算，但是buffer大时，链接变多就会浪费系统资源，可以参照mudo的函数栈空间解决；





线程  DHCP  基于udp，数据比较小一整包就能发送完，不存在分包和粘包，对于pxelinux.0只发送了路径；

线程  TFTP 基于udp，会发送包头==整个数据包的大小，然后会协商每个数据包的大小，每个包都会有长度信息，根据长度信息server端解决分包；发送是整个文件，先发送大小，然后分包发送；client根据长度来解决粘包；
因为基于udp所以只适合小文件的发送；

线程  socket server端  这个分包和粘包被忽略掉了，Python：ThreadingTCPServer封装了listen and accept， c:client 每一次传输都会新建一个链接，
rfile and wfile将缓存buffer进行了封装，每次新的连接都会新建，每次发送会先发送数据大小相当于数据包头都会有数据长度，解决分包问题；粘包问题不需要解决，因为一次发送只发送同一个数据，并不需要解析；

client其实是iacsrv，在shell中阻塞时运行，所以client端每次启动都要connect


dss的分包粘包解决  包头（body size，command ID）和包体（真正的数据）protobuffer只是用来打包数据的；
