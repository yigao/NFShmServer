## 安装google python模块(需要安装python2.7, centos7自带)
- 解压thirdparty/pkg目录下得protobuf-2.5.0.tar, 会有一个protobuf-2.5.0目录，里面有protobuf的源文件, cd protobuf-2.5.0
- 编译protobuf,执行:
- ./configure
- make
- make install
- 在protobuf-2.5.0目录下有一个python目录，执行下面命令:
- cd python 
- python setup.py build 
- python setup.py test 
- python setup.py install
- 验证Python模块是否被正确安装,如果没有报错，说明安装正常, 打开python, 然后输入import google.protobuf.internal,没有报错说明安装没问题
- python 
>>> import google.protobuf.internal

## 安装xlrd python模块，用来读取excel之用
- 解压thirdparty/pkg目录下得xlrd-0.9.4.tar.gz, 会有一个xlrd-0.9.4目录，里面有xlrd的源文件, cd xlrd-0.9.4
- 执行python setup.py install

## windows安装make, 执行tools/mingw-get-setup
- 安装MinGW的时候选择Basic setup下选择mingw32-base包就可以了。
- 打开MinGW的安装目录，打开bin文件夹，将mingw32-make.exe重命名为make.exe。
- 设置环境变量，只需把bin文件夹的路径放到用户变量中去。
