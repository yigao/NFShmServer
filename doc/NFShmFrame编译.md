# 编译前提条件:
## Ubuntu20.04编译前提条件
- sudo apt update
- sudo vim /etc/ld.so.conf 加入 /usr/local/lib, 然后执行ldconfig
- 安装git, sudo apt install git
- 安装mysqlclient, sudo apt install libmysqlclient-dev
- sudo apt install libkrb5-dev
- git clone https://gitee.com/xiaoyi445_admin/NFShmServer2.git拉取代码
## Centos7编译前提条件
- yum install krb5-devel.x86_64
## 安装CMake 2.6
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

# 下面的步骤，python模块安装, 非必要
## 安装google python模块(需要安装python2.7, centos7,ubuntu20自带)()
- 解压thirdparty/pkg目录下得protobuf-2.5.0.tar, 会有一个protobuf-2.5.0目录，里面有protobuf的源文件, cd protobuf-2.5.0
- 编译protobuf,执行:
- ./configure
- make
- make install
- 在protobuf-2.5.0目录下有一个python目录，执行下面命令:
- cd python
- python2.7 setup.py build
- python2.7 setup.py test
- python2.7 setup.py install
- 验证Python模块是否被正确安装,如果没有报错，说明安装正常, 打开python, 然后输入import google.protobuf.internal,没有报错说明安装没问题
- python2.7
>>> import google.protobuf.internal
## 安装xlrd python模块，用来读取excel之用
- 解压thirdparty/pkg目录下得xlrd-0.9.4.tar.gz, 会有一个xlrd-0.9.4目录，里面有xlrd的源文件, cd xlrd-0.9.4
- 执行python2.7 setup.py install
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
- ./Configure
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
