简体中文

<p align="right">当前版本: <strong>v1.0.0</strong></p>
<p align="center"><img src="https://github.com/yigao/NFShmServer/blob/master/doc/logo.png" alt="nfshmserver" width="300"/></p>
NFShmServer 是一个使用C++开发的轻量级,敏捷型,弹性的,分布式的共享内存的插件开发框架, 让你更快更简单的开发服务端应用. 部分思路来自UE4和Ogre.(当前主要用在游戏领域) 我写的开源架构，前几年开源过，后来自己做项目，又没开源了，现在没搞项目了，加上修改了2年了，打算重新开源

---

[![License](https://img.shields.io/github/license/yigao/NFShmServer.svg?colorB=f48041&style=flat-square)](https://opensource.org/licenses/Apache-2.0)
![GitHub stars](https://img.shields.io/github/stars/yigao/NFShmServer.svg?style=flat-square&label=Stars&style=flat-square)
![GitHub issues](https://img.shields.io/github/issues-raw/yigao/NFShmServer.svg?style=flat-square)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/yigao/NFShmServer.svg?style=flat-square)  
[![SonarCloud](https://sonarcloud.io/api/project_badges/measure?project=ark&metric=alert_status)](https://sonarcloud.io/dashboard/index/ark)
[![codecov](https://codecov.io/gh/OpenArkStudio/ARK/branch/master/graph/badge.svg)](https://codecov.io/gh/OpenArkStudio/ARK)
[![QQ Group](https://img.shields.io/badge/Chat%20on-QQ%20Group-orange.svg?longCache=true&style=flat-square)](https://shang.qq.com/wpa/qunwpa?idkey=1b8394bd9a42ba46606200a44911c1c6161235a38aecce95158ca646c2bafd81)
[![Discord](https://img.shields.io/discord/471890201124536320.svg?label=Discord&style=flat-square)](https://discord.gg/GmyBbcv)
[![996.icu](https://img.shields.io/badge/Link-996.icu-red.svg?&style=flat-square)](https://996.icu)

</center>

**Copyright © [NFShmServer]**  
GitHub: https://github.com/yigao/NFShmServer

码云: https://gitee.com/xiaoyi445_admin/NFShmServer

QQ 群: [点击加群762414765](https://shang.qq.com/wpa/qunwpa?idkey=3dShwRu-nyiWUWLw3iWzCyn-3ZU8EFfi)  


| CI             | master分支                                                                                                                | develop分支                                                                                                                         |
| -------------- | ------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| Github Actions | [![Github Action](https://github.com/yigao/NFShmServer/workflows/Github-CI/badge.svg)](https://github.com/yigao/NFShmServer/actions)      | [![Github Action](https://github.com/yigao/NFShmServer/workflows/Github-CI/badge.svg?branch=develop)](https://github.com/yigao/NFShmServer/actions) |
## 特性

- 可以做到分布式架构不需要修改任何源码的情况下，做到单进程运行，加快平时的服务器开发。分布式运行只需要程序启动是参数修改即可
- C++热更，服务器崩溃后重启，玩家无感知，无影响，不丢任何物价数据，甚至连内网协议数据都不会有丢失，游戏数据均放在共享内存里，共享内存架构经过很多MMO大项目验证无问题，内网通讯采用共享内存通讯的话，服务器异常时，玩家协议数据不会丢失。如果你水平足够的话，理论上还可以做到服务器不重启so热更，当然不建议你这么做。
- 服务器游戏配置数据，从excel到共享内存代码，到sql语句，只需定义一个protobuf结构，就可以生成大量有用代码，你可以用这个protobuf结构去读取excel数据，生成对应的共享内存结构类，来存放数据，也可以生成sql数据，把excel表导入到数据库，不需要修改源码，可以从本地文件读取excel数据，可以直接从数据库读取配置。
- 玩家个人数据，只需定义一个protobuf结构，自动生成共享内存数据，sql数据，通过protobuf发射来完成mysql数据的存取，无需你自己写sql语句。
- 类似腾讯内部服务器，每一个服务器进程都有一个独立的类似网络IP的ID，来代表这个服务器，你不需要知道任何一个服务器进程部署在哪里，只要知道这个服务器的独立ID，就可以相互通讯
- 友好的日志控制，你可以单独控制，一个小模块的日志，甚至一个玩家的日志
- 跨平台(Windows, Linux, MacOS)
- 高可用的系统架构
- 高并发和高性能的网络模块
- 配套的 U3D 客户端，一个捕鱼项目，暂时没有上传
- 丰富的插件(DB, script, HTTP, WebSocket 等)

## Dependencies

- libevent
- spdlog
- google protobuf
- hiredis
- rapidjson
- concurrentqueue
- RapidXML
- LuaIntf
- navigation
- lua
- mysql
- mysqlpp
- curl
- evpp
- openssl
- theron
- zookeeper

## linux centos 安装可能需要的环境:

* sudo apt-get install g++
* sudo apt-get install cmake
* sudo apt-get install automake
* sudo apt-get install zip unzip

## （非必须，除非你要修改excel,或修改proto文件）安装Excel工具, 需要安装protobuf python模块， xlrd python模块
* 请参考文档https://github.com/yigao/NFShmServer/blob/master/doc/README.md, 安装需要的protobuf库
* 也可以看看文档https://github.com/yigao/NFShmServer/blob/master/doc/Excel工具使用.doc

## Supported Compilers

* GCC >= 7 (**Tested on Centos 7**)
* MSVC >= VS2017 (Tested on Win10)

## Build and Install
### FOR WINDOWS, MSVC >= 2017

1. Git pull all source
2. Build the solution
3. Run the binary file by **Install/Bin/Debug/rund_allserver.bat**
4. win上采用的静态编译方式，而不是动态加载so/dll文件，只共大家平时开发用，会把所有的程序都打包的到NFPluginLoader，
然后通过配置文件来选择不同的程序运行，配置和在linux上的配置一样，到不用改动.

### FOR LINUX(UBUNTU, CENTOS) ---- please use administrator(or sudo) to do these:
1. Git pull all source
2. Run **build_dynamic_debug.sh** to build Debug of NFShmServer
3. Run **build_dynamic_release.sh** to build Release of NFShmServer
4. Run the server， 分几种情况执行:
    - 根据使用master服务器来做分布式还是使用zookpeer，需要先配置好zookpeer，分几种种执行方式：
    -  如果你想把所有的分布式进程放到一个进程一个线程里执行的话，只要是方便调试:
    -    内网使用TCP通信,master服务器来做分布式:./NFPluginLoader --Server=AllServer --ID=1.1.1.1 --Config=../../Config --Plugin=../../TcpPlugin --restart
    -    内网使用Bus通信,master服务器来做分布式:./NFPluginLoader --Server=AllServer --ID=1.1.1.1 --Config=../../Config --Plugin=../../BusPlugin --restart
    -    内网使用TCP通信,zookpeer服务器来做分布式:./NFPluginLoader --Server=AllServer --ID=1.1.1.1 --Config=../../Config --Plugin=../../TcpPlugin_Zookpeer --restart
    -    内网使用Bus通信,zookpeer服务器来做分布式:./NFPluginLoader --Server=AllServer --ID=1.1.1.1 --Config=../../Config --Plugin=../../BusPlugin_Zookpeer --restart
    - 如果你想分布式执行:
    -    内网使用TCP通信,master服务器来做分布式:执行脚本CreateScript.sh或CreateScript_TcpPlugin.sh，会生成Start.sh,Stop.sh,ReStart.sh,Alllog.sh等脚本，执行Start.sh，会一个一个启动服务器，执行Alllog.sh可以查看所有服务器的日志。
    -    内网使用Bus通信,master服务器来做分布式:执行脚本CreateScript_BusPlugin.sh，会生成Start.sh,Stop.sh,ReStart.sh,Alllog.sh等脚本，执行Start.sh，会一个一个启动服务器，执行Alllog.sh可以查看所有服务器的日志。
    -    内网使用TCP通信,zookpeer服务器来做分布式:执行脚本CreateScript_TcpPlugin_Zookpeer.sh，会生成Start.sh,Stop.sh,ReStart.sh,Alllog.sh等脚本，执行Start.sh，会一个一个启动服务器，执行Alllog.sh可以查看所有服务器的日志。
    -    内网使用Bus通信,zookpeer服务器来做分布式:执行脚本CreateScript_BusPlugin_Zookpeer.sh，会生成Start.sh,Stop.sh,ReStart.sh,Alllog.sh等脚本，执行Start.sh，会一个一个启动服务器，执行Alllog.sh可以查看所有服务器的日志。
      
## Tutorial && Documents

**Tutorial Chapters**:

* [**Tutorial 1: Compile NFShmServer 编译服务器**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-CompileNF)

* [**Tutorial 2: Import Mysql 导入数据库**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-ImportMysql)

* [**Tutorial 3: Start NFShmServer 开启服务器**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-StartServer)

* [**Tutorial 4: Start RobotServer 开启机器人**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-StartRobot)

-->
-------

**Concept Chapters**:

* [**Chapter 1: NFPluginLoader核心类**](https://github.com/yigao/NFShmServer/wiki/Chapter-1:NFPluginLoader,Plugin,Module)
* [**Chapter 2: 单个服务器进程的启动管理**](https://github.com/yigao/NFShmServer/wiki/Chapter-2:NFPluginLoader-main)
* [**Chapter 3: 服务器启动参数介绍**](https://github.com/yigao/NFShmServer/wiki/Chapter-3:ProcessParameter)
* [**Chapter 4: 服务器循环介绍**](https://github.com/yigao/NFShmServer/wiki/Chapter-4:Execute)
* [**Chapter 5: NFKernelPlugin基础核心引擎介绍**](https://github.com/yigao/NFShmServer/wiki/Chapter-5:NFKernelPlugin)
* [**Chapter 6: NFNetPlugin网络引擎介绍**](https://github.com/yigao/NFShmServer/wiki/Chapter-6:NFNetPlugin)
* [**Chapter 10: 共享内存创建以及初始化**](https://github.com/yigao/NFShmServer/wiki/Chapter-10:Shm-Init)
* [**Chapter 11: 创建共享内存**](https://github.com/yigao/NFShmServer/wiki/Chapter-11:CreateShareMem)
* [**Chapter 12: 共享内存单个类的创建初始化**](https://github.com/yigao/NFShmServer/wiki/Chapter-12:SetAndInitObj)
* [**Chapter 13: 共享内存几个核心类**](https://github.com/yigao/NFShmServer/wiki/Chapter-13:NFGlobalID,NFShmTimerManager,NFTransMng,NFDBObjMgr)
* [**Chapter 14: 加载Excel配置的共享内存类**](https://github.com/yigao/NFShmServer/wiki/Chapter-14:NFCDescStoreModule)
* [**Chapter 20: 日志系统**](https://github.com/yigao/NFShmServer/wiki/Chapter-20:NFCLogModule)
* [**Chapter 21: 服务器配置加载系统**](https://github.com/yigao/NFShmServer/wiki/Chapter-21:NFCConfigModule)
* [**Chapter 22: 定时器系统**](https://github.com/yigao/NFShmServer/wiki/Chapter-22:NFCTimerModule)
* [**Chapter 23: 事件系统**](https://github.com/yigao/NFShmServer/wiki/Chapter-23:NFCEventModule)

## 客户端下载，客户端代码还在整理，后面会开源，现在有一个捕鱼apk，可以玩玩
[game.apk](https://github.com/yigao/NFShmServer/blob/master/doc/%E6%8D%95%E9%B1%BC%E6%B5%8B%E8%AF%951.apk)
## 服务器架构

### 进程架构:
![App Architecture](https://github.com/yigao/NFShmServer/blob/master/doc/app_arch.png)

### 单物理机服务器架构:
![单物理机服务器架构](https://github.com/yigao/NFShmServer/blob/master/doc/single_server_arch.png)
### 多物理机服务器架构:
![多物理机服务器架构](https://github.com/yigao/NFShmServer/blob/master/doc/server_arch.png)
### 服务器架构说明:
- 所有的服务器都要链接master服务器，可以选择使用master服务器作为命名服务器，也可以选用zookeeper作为命名服务器，只需修改下配置即可
- 每一个服务器都有一个类似IP地址的ID，作为唯一ID，比如master服务器ID是1.1.1.1， worldserver服务器ID是15.100.3.1， 服务器之间相互通讯，不需要知道对方部署在哪一台物理机上，只需要知道对方的唯一ID，就可以相互通讯
- 每一个单独的物理机上都有一个NFRouteAgentServer路由代理服务器,用来在这个物理机上实现内网通讯以及和别的物理机通讯，一个NFProxyAgentServer网关代理服务器，用来链接网关，实现对外部（客户端）通讯
- 物理机
- 逻辑服务器比如LoginServer,LogicServer,GameServer,WorldServer,SnsServer,StoreServer, 相互之间不连接，同一个物理机上全部链接同一个NFRouteAgentServer路由代理服务器，并把自己的唯一ID注册到这个NFRouteAgentServer上， 来实现相互通讯，比如LoginServer发消息给WorldServer, LoginServer和WorldServer之间相互不连接，LoginServer需要把消息先发给NFRouteAgentServer, NFRouteAgentServer再把消息转发给WorldServer。
- NFRouteAgentServer路由代理服务器通过链接NFRouteServer服务器来实现相互链接，NFRouteAgentServer路由代理服务器会把自己下面的逻辑服务器信息发给NFRouteServer服务器，来实现分布跨物理机通讯。在不同物理机之间的服务器通讯需要NFRouteServer服务器，比如LoginServer给不在同一个物理机上的WorldServer发消息，LoginServer需要把消息先发给同一台物理机上的NFRouteAgentServer, NFRouteAgentServer再把消息转发给NFRouteServer, NFRouteServer在吧消息转发给和WorldServer同一个物理机的NFRouteAgentServer, NFRouteAgentServer再把消息转发给WorldServer
- 客户端只链接NFProxyServer， 发消息给逻辑服务器，NFProxyServer会把消息转发给逻辑服务器链接的NFProxyAgentServer代理服务器，NFProxyAgentServer代理服务器在吧消息转发给逻辑服务器, 同理逻辑服务器发消息给客户端，需要先通过NFProxyAgentServer代理服务器, NFProxyAgentServer代理服务器在发消息转发给NFProxyServer, NFProxyServer在发给客户端
#### 一些很赞的项目

[PSS](https://github.com/freeeyes/PSS)

- 作者: freeeyes
- 描述: 基于插件的跨平台网络服务器框架

[ARK](https://github.com/OpenArkStudio/ARK.git)

- 作者: NickYang1988
- 描述: 基于插件的跨平台网络服务器框架

[NoahGameFrame](https://github.com/ketoo/NoahGameFrame.git)

- 作者: ketoo
- 描述: 基于插件的跨平台网络服务器框架
