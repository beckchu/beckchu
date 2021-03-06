// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is a public header file, it must only include public header files.

#ifndef MUDUO_NET_INETADDRESS_H
#define MUDUO_NET_INETADDRESS_H

#include <muduo/base/copyable.h>
#include <muduo/base/StringPiece.h>

#include <netinet/in.h>

namespace muduo
{
namespace net
{

///
/// Wrapper of sockaddr_in.
///
/// This is an POD interface class.
class InetAddress : public muduo::copyable
{
 public:
  /// Constructs an endpoint with given port number.
  /// Mostly used in TcpServer listening.
  explicit InetAddress(uint16_t port);

  /// Constructs an endpoint with given ip and port.
  /// @c ip should be "1.2.3.4"
  InetAddress(const StringPiece& ip, uint16_t port);

  /// Constructs an endpoint with given struct @c sockaddr_in
  /// Mostly used when accepting new connections
  InetAddress(const struct sockaddr_in& addr)
    : addr_(addr)
  { }

  string toIp() const;
  string toIpPort() const;
  string toHostPort() const __attribute__ ((deprecated))
  { return toIpPort(); }

  // default copy/assignment are Okay

  const struct sockaddr_in& getSockAddrInet() const { return addr_; }
  void setSockAddrInet(const struct sockaddr_in& addr) { addr_ = addr; }

  uint32_t ipNetEndian() const { return addr_.sin_addr.s_addr; }
  uint16_t portNetEndian() const { return addr_.sin_port; }

 private:
  struct sockaddr_in addr_;
  //struct sockaddr {  
  //    unsigned short    sa_family;    // 2 bytes address family, AF_xxx  
  //    char              sa_data[14];     // 14 bytes of protocol address  
  //};  
  //
  //struct sockaddr_in {  
  //     short            sin_family;       // 2 bytes e.g. AF_INET, AF_INET6  
  //     unsigned short   sin_port;    // 2 bytes e.g. htons(3490)  
  //     struct in_addr   sin_addr;     // 4 bytes see struct in_addr, below  
  //     char             sin_zero[8];     // 8 bytes zero this if you want to  
  // };  

};

}
}

#endif  // MUDUO_NET_INETADDRESS_H
