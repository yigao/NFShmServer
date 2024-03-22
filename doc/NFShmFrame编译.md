# 编译前提条件:
## Ubuntu20.04编译前提条件
- sudo apt update
- sudo vim /etc/ld.so.conf 加入 /usr/local/lib, 然后执行ldconfig
- 安装git, sudo apt install git
- sudo apt install libkrb5-dev
- git clone https://gitee.com/xiaoyi445_admin/NFShmServer2.git拉取代码
## Centos7编译前提条件
- yum install gcc-c++
- yum install krb5-devel.x86_64
  
## 
## 安装mysqlclient(不要安装系统默认的libmysqlclient)
- sudo apt install cmake (低版本cmake, 先不要安装cmake3.26)
- thirdparty目录下有一个mysql目录，cd mysql
- mkdir build
- cd build
- cmake ..
- make
- make install
- sudo apt remove cmake (卸载低版本的cmake)
## 安装CMake 3.26(如果你不想安装cmake的话，又不是centos7, ubuntu用户可以修改CMakeLists.txt的set(DISTRO_ID "centos")为set(DISTRO_ID "ubuntu"))
- 解压thirdparty/pkg目录下得cmake-3.26.3.tar.gz(tar -xvf cmake-3.26.3.tar.gz), 会有一个cmake-3.26.3目录，, cd cmake-3.26.3
- 编译cmake,执行:
- ./configure
- make
- sudo make install
## 安装protobuf
- 解压thirdparty/pkg目录下得protobuf-2.5.0.tar, 会有一个protobuf-2.5.0目录，里面有protobuf的源文件, cd protobuf-2.5.0
- 编译protobuf,执行:
- ./configure
- make
- make install

# 下面的步骤，对cento7,ubuntu20来说，可以不执行，需要的库文件已经编译好

## 安装libevent-release-2.1.8
- 解压thirdparty/pkg目录下得libevent-release-2.1.8-stable.tar.gz(tar -xvf libevent-release-2.1.8-stable.tar.gz), 会有一个libevent-release-2.1.8-stable目录，cd libevent-release-2.1.8-stable
- 编译libevent, 注意-with-pic， 一定要带:
- ./configure -with-pic
- make
- sudo make install
## 安装 curl-7.60.0
- 解压thirdparty/pkg目录下得 curl-7.60.0.tar.bz2(tar -xvf  curl-7.60.0.tar.bz2), 会有一个curl-7.60.0目录，cd curl-7.60.0
- 编译curl, 注意-with-pic， 一定要带::
- ./configure -with-pic
- make
- sudo make install
## 安装  openssl-1.0.2n
- 解压thirdparty/pkg目录下得  openssl-1.0.2n.tar.gz(tar -xvf   openssl-1.0.2n.tar.gz), 会有一个openssl-1.0.2n目录，cd openssl-1.0.2n
- 编译openssl:
- ./config
- 找到Makefile文件，在CFLAG=这一行，加入-fPIC
- make
- sudo make install
## 安装zlib(系统自带的zlib库编译的时候没有-fPIC， 所有我们要自己编译安装一个带-fPIC的)
- thirdparty目录下有一个zlib目录，cd zlib
- 编译zlib:
- ./configure -with-pic
- make
- sudo make install
## 安装Theron
- thirdparty目录下有一个Theron目录，cd Theron
- 编译Theron:
- make
- 编译好的库在文件Theron/Lib目录下，把libtheron.a复制到合适的地方
## 安装  lua-5.3.0.tar.gz(非必要，如果你想要Linux系统使用LuaPanda调试lua的话，才需要)
- 解压thirdparty/pkg目录下得  lua-5.3.0.tar.gz(tar -xvf   lua-5.3.0.tar.gz), 会有一个lua-5.3.0目录，cd lua-5.3.0
- 编译lua:
-  make posix
- sudo make install
## 安装  luasocket-3.1.0(非必要，如果你想要Linux系统使用LuaPanda调试lua的话，才需要)
- 解压thirdparty/pkg目录下得  luasocket-3.1.0.tar.gz(tar -xvf   luasocket-3.1.0.tar.gz), 会有一个luasocket-3.1.0目录，cd luasocket-3.1.0
- 编译lua:
-  make
- sudo make install
