简体中文

<p align="right">当前版本: <strong>v1.0.0</strong></p>
<p align="center"><img src="https://github.com/yigao/NFShmServer/blob/master/doc/logo.png" alt="nfshmserver" width="300"/></p>
NFShmServer 是一个使用C++开发的轻量级,敏捷型,弹性的,分布式的共享内存（C++热更）/多进程lua(lua热更)的插件开发框架, 让你更快更简单的开发服务端应用. 部分思路来自UE4和Ogre.(当前主要用在游戏领域) . 实现了一款unity3d捕鱼demo游戏，有兴趣的可以加群762414765学习
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
## 为什么要写NFShmFrame开源服务器
* 最近参加了一下面试，面试官问为什么要写开源服务器，你写的和别人的开源有什么区别。我说因为兴趣所以写，要写世界最屌的服务器.
* 这个服务器和别人的服务器有什么区别呢！如果写的东西，别人也可以立马写出来，或者和别人的差不多，那就只是练练手脚，价值不大。
## NFShmFrame开源服务器的与众不同之处
- 由游戏服务器开发过程中遇到的问题来展开NFShmFrame不同于别的服务器之处，在近10年的游戏开发中，常常遇到一些开发中的问题，为了解决遇到的这些服务器难题，我往往会在NFShmFrame上先实现解决方案，久而久之，6年的积累，慢慢就形成了NFShmFrame这个开源服务器
1. 问题一：C++服务器开发谁都避不过去的问题，C++服务器崩溃。不管是指针导致的，还是memcpy,memset等函数导致的，还是数组越界，栈空间越界导致的，最终C++服务器崩溃，内存数据全部丢失。
2. 问题二：C++难以实现像LUA那样的热更功能
3. 问题三：一般的分布式游戏服务器，基本都是由很多不同功能的进程组成，这些进程使用Tcp或共享内存相互链接，难以配置。
4. 问题四：多进程的分布式服务器，需要同时开启多个进程。即使在windows系统上使用vs调试，也需要开启很多窗口，太多的话，关闭或启动服务器麻烦。在linux，如果使用gdb调试多个服务器的话，那简直就是人道灾难
5. 问题五：在实现游戏服务器系统的DB存储过程中，大量手写sql语句。写的蛋痛，看的蛋痛，维护蛋痛，特别容易写错，还难写。玩转mysql服务器，storeserver利用protobuf反射，自动创建数据库，创建表，新加列,  通过加载pb， 动态更新storeserver服务，无需你手写任何mysql语句，统一实现游戏服务器的数据拉去，存取，更新
6. 问题六：C++多线程，不管是要实现tcp网络的多线程，还是db系统的多线程，并不好写。
7. 问题七：有些游戏服务器，比如从腾讯等公司拿出来的，同时使用共享内存和TCP来实现服务器与服务器之间的通讯以及服务器和客户端的通讯。TCP和共享内存之间接口难以统一，相互替换麻烦。
8. 问题八：大部分游戏公司的服务器代码各个模块耦合度太高，难以分开，难以替换升级。 
9. 问题九：部分公司，主要是腾讯出来创业搞出来的公司，使用共享内存来解决C++服务器崩溃后数据丢失和C++热更问题。但是使用共享内存创建类，缺乏stl之类的容器支持。导致使用共享内存成本太高。 
## 特性

- 可以做到分布式架构不需要修改任何源码的情况下，做到单进程运行整套分布式系统(对于滚服服务器，可同时运行多个服务器，便于调试跨服)，加快平时的服务器开发。 同时还能做到在开发运行的时候最大可能的节约内存， 方便调试开发。分布式运行只需要程序启动时参数修改即可
- C++热更，服务器实现了共享内存C++热更(对于纯粹C++来说，也是唯一热更的有效可用的方案，当然热更的前提是没有修改共享内存类的结构大小)。
- 服务器崩溃不丢失数据，对于热门的赚钱的游戏这点还是很重要的。 服务器崩溃后重启，不丢任何物理数据，甚至连内网协议数据都不会有丢失。
- 游戏数据均放在共享内存里，共享内存架构经过很多MMO大项目验证无问题，内网通讯采用共享内存通讯的话，服务器异常时，玩家协议数据不会丢失。
- (2022.9-2023.9已完成)实现一套可以放心用在共享内存里的仿sgi-stl数据结构, 极大的解决了使用共享内存写代码难度搞得问题(见过好几套从腾讯流出来的游戏的共享内存架构，大部分仅仅是实现了一个简单的哈希表，其余的业务就需要使用C语言的原始数组啥的了)。除了事先需要定义好需要的内存大小外，其余使用方法都与stl一样.  NFShmVector -- std::vecotr       使用:NFShmVector<int, 5> -- std::vector<int> 除了要定义5这个最大内存容量外，其余使用方法NFShmVector和std::vector完全一样，包过使用他们的迭代器以及stl算法
  
        
- (2022.9-2023.9已完成)服务器游戏配置数据，从excel到共享内存代码，到sql语句，只需定义一个protobuf结构，就可以生成大量有用代码，你可以用这个protobuf结构去读取excel数据，生成对应的共享内存结构类，来存放数据，也可以生成sql数据，把excel表导入到数据库，不需要修改源码，可以从本地文件读取excel数据，可以直接从数据库读取配置。
- (2022.9-2023.9已完成)玩家个人数据，只需定义一个protobuf结构，自动生成共享内存数据，sql数据，通过protobuf发射来完成mysql数据的存取，无需你自己写sql语句。
- 类似腾讯内部服务器，每一个服务器进程都有一个独立的类似网络IP的ID，来代表这个服务器，你不需要知道任何一个服务器进程部署在哪里，只要知道这个服务器的独立ID，就可以相互通讯
- (2022.9-2023.9已完成)多进程单线程lua热更，实现了lua插件。可以用lua写业务代码，热更服务器。
- (未完成)多进程actor多线程lua热更, 目前还是构思中。有点类似skynet, 但是C++底层还是nf, 架构主C++，业务主lua.
- (2022.9-2023.9已完成)友好的协程RPC系统，实现了一个使用游戏服务器的RPC系统，简单好用，同时非常适配游戏服务器的协议系统。
- 高并发和高性能的通信模块， 跨物理机器以及对外采用libevent+evpp实现的多线程网络tcp,udp,http， 同一个物理机通信可采用单线程共享内存bus系统，也可采用前面的多线程网络。同时实现了网络和bus系统的接口配置统一， 只需要稍微修改配置，就可方便切换.
- 高可用的系统架构。架构采用分成架构，系统分为架构层,服务器层，具体的游戏业务层。具体的层次具体的目录，上层不会依赖下层，结构清晰。架构层,服务器层通用，不同的游戏分不同的目录.
- (2020.1-2023.9已完成)可复用的db系统，db系统采用protobuf反射机制来实现。不需要手动撸sql语句，不需要定义mysql表。只需要一个protobuf结构体，db系统会自动创建数据库，创建表格，新加列。数据库的查询，插入，保存，也仅需要使用这个protobuf结构体调用系统结构即可。
- (2022.9-2023.9已完成)redis缓存系统，使用protobuf反射来实现，不需要手写任何代码。只需要配置好storeserver系统的简单的缓存机制即可。
- (2022.9-2023.9已完成)统一的配置加载机制，无论你是从excel加载配置，还是从数据库表格里加载配置。无需大量修改代码，仅仅该一个标志即可。
- (2022.9-2023.9已完成)邮箱以及企业微信通知机制，实现了启动服务器以及服务器崩溃，服务器结构会把启动的信息以及服务器崩溃的dump信息发送至邮箱或你的企业微信里。
- 友好的日志控制，你可以单独控制，一个小模块的日志，甚至一个玩家的日志
- 配套的 U3D 客户端，一个捕鱼项目 https://github.com/yigao/NFShmFrame_FishClient.git
- 跨平台(Windows, Linux)
 
## unity3d捕鱼demo游戏 [点击加群762414765](https://shang.qq.com/wpa/qunwpa?idkey=3dShwRu-nyiWUWLw3iWzCyn-3ZU8EFfi)，群里提供apk下载
![}OXI`%2KDC3509YEVE Z00K](https://github.com/yigao/NFShmServer/assets/5827943/1624b292-871d-46da-a446-1755efb4bae8)
![0 ZK~FM1IBM0{E%LI8 %)AJ](https://github.com/yigao/NFShmServer/assets/5827943/fc137349-de2b-4519-9b8b-325ea220251a)

## 后期开发目标
- 使用C++重写excel的加载，验证，导出代码机制(python,lua的导出，在大型项目里太慢)(2023.8-2023.9已完成)
- redis缓存系统(2023.9.18已完成)
- 完善excel导出sql语句，从db系统加载配置(2023.9.1已完成)
- 实现actor的多线程Lua系统(类似skynet, 区别lua只负责逻辑，系统架构主要由C++实现)
- 实现单线程python系统
- 实现单线程js系统
- 实现单线程php系统
- 实现单线程c#系统
- 实现actor的多线程python系统(类似skynet, 区别python只负责逻辑，系统架构主要由C++实现)
- 继续完善excel到db系统机制，自动导出代码, 实现网页端的配置更新
- 将平台升级到C++17
- 将db系统由mysql到libzdb, 兼容市场上大部分数据库(MySQL, PostgreSQL, SQLite and Oracle)
- 完善捕鱼逻辑(9.23已完成)
- 实现一个MMO游戏的逻辑
- 重写最后一战的服务器
- 重写魔兽世界的服务器

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

## unity3d捕鱼demo && Documents

**unity3d捕鱼demo游戏**:

* [**Tutorial 1: Compile NFShmServer 编译捕鱼demo服务器**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-CompileNF)

* [**Tutorial 2: Import Mysql 导入捕鱼demo数据库**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-ImportMysql)

* [**Tutorial 3: Start NFShmServer 开启捕鱼demo服务器**](https://github.com/yigao/NFShmServer/wiki/Tutorial:-StartServer)

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


## 服务器架构

### 进程架构:
![App Architecture](https://github.com/yigao/NFShmServer/blob/master/doc/app_arch.png)

### 单物理机服务器架构:
![单物理机服务器架构](https://github.com/yigao/NFShmServer/blob/master/doc/single_server_arch.png)
### 多物理机服务器架构:
![多物理机服务器架构](https://github.com/yigao/NFShmServer/blob/master/doc/server_arch.png)
### 服务器架构说明:
- 所有的服务器都要链接master服务器，可以选择使用master服务器作为命名服务器，只需修改下配置即可
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
