# Ubuntu20.04编译, 前提条件:
 - sudo apt update
 - sudo vim /etc/ld.so.conf 加入 /usr/local/lib, 然后执行ldconfig
 - 安装git, sudo apt install git
 - 安装cmake, sudo apt install cmake
 - 安装libkrb5(openssl need), sudo apt install libkrb5-dev
 - git clone https://gitee.com/xiaoyi445_admin/NFShmServer2.git拉取代码
## 安装google python模块(需要安装python2.7, centos7,ubuntu20自带)
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
- 执行python setup.py install