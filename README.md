[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md)

# 德州扑克俱乐部源码｜德州私人局、联盟与多人实时对战

基于 **Unity 客户端 + C++ 服务端 + MySQL + Redis** 的德州扑克俱乐部平台资料。项目包含俱乐部、联盟、私人局/朋友局、邀请、战绩、语音视频、MTT、SNG、AOF、保险与后台管理等已公开功能，适合用于技术评估、部署研究和二次开发。

> 仓库资料展示的是现有产品与代码结构；运营历史、并发能力、支付接入和部署完整性请在使用前独立核验。请遵守所在地法律、平台规则及负责任游戏要求。

[![Contact](https://img.shields.io/badge/Contact-TG%3A%40xuzongbin001-blue)](https://t.me/xuzongbin001)
![Server](https://img.shields.io/badge/Server-C%2B%2B-red)
![Client](https://img.shields.io/badge/Client-Unity-green)

## 专题导航

- [德州扑克源码：架构、玩法与代码组成](https://masterai-top.github.io/Texas-Holdem-Poker-Club-Platform/zh-cn/texas-holdem-source-code.html)
- [德州扑克俱乐部源码：俱乐部、联盟与成员体系](https://masterai-top.github.io/Texas-Holdem-Poker-Club-Platform/zh-cn/poker-club-source-code.html)
- [德州私人局源码：朋友局、邀请与实时牌桌](https://masterai-top.github.io/Texas-Holdem-Poker-Club-Platform/zh-cn/private-poker-game-source-code.html)
- [繁體中文專題入口](https://masterai-top.github.io/Texas-Holdem-Poker-Club-Platform/zh-tw/texas-holdem-source-code.html)

## 核心功能

| 模块 | 已公开内容 |
| --- | --- |
| 俱乐部与联盟 | 俱乐部、联盟、成员与代理体系 |
| 私人局 | 私人桌、朋友局、邀请和实时多人牌桌 |
| 玩法 | 经典德州、6+短牌、奥马哈、大菠萝、MTT、SNG、AOF、德州牛仔 |
| 对局工具 | 保险、战绩统计、机器人、礼物、实时语音与视频聊天 |
| 运营 | 后台管理、多语言资源、iOS/Android 客户端 |

## 技术与代码

- 客户端：Unity / C#，面向 iOS 与 Android。
- 服务端：C++，仓库可见游戏服务、活动服务、GM 服务及牌桌逻辑代码。
- 通信：Protocol Buffers/TARS 相关协议文件。
- 数据层：README 所述 MySQL + Redis；实际部署配置请以交付资料为准。
- 多语言：仓库包含简体中文、繁体中文、英文、韩文语言资源。

典型文件包括 `gameserver.cpp/h`、`gameroot.cpp/h`、`onclientmessage.cpp/h`、`onroommessage.cpp/h`、`sendclientmessage.cpp/h` 与 `sendroommessage.cpp/h`。

## 产品截图



<img width="500" height="889" alt="德州扑克俱乐部产品演示" src="https://github.com/user-attachments/assets/6de3ed8c-17f8-43a5-94c2-896708a4d798" />

![德州扑克实际牌桌 03](https://github.com/user-attachments/assets/afc9ea87-44ef-45e6-aa8e-f6491dcb121c)
![德州扑克实际牌桌 01](https://github.com/user-attachments/assets/20c19859-a23a-4c42-835c-7591f350a125)
![德州扑克实际牌桌 02](https://github.com/user-attachments/assets/96c4bffd-e012-48a2-a817-2e2453a1a54a)
![俱乐部产品截图 1](https://github.com/user-attachments/assets/11cee94b-eeea-4519-9727-30e88a737406)
![俱乐部产品截图 2](https://github.com/user-attachments/assets/160bd558-4327-4ec1-b4a2-0889b5b305be)
![俱乐部产品截图 3](https://github.com/user-attachments/assets/51b760e9-ddff-4190-b330-cdc2e4cfee93)
![俱乐部产品截图 4](https://github.com/user-attachments/assets/c1c6955a-172b-4e5b-8fe3-e6325f3f6b38)
![俱乐部产品截图 5](https://github.com/user-attachments/assets/c7beec6a-2757-484d-9757-87ca12b3bfac)

## 获取与联系

- Telegram：[@xuzongbin001](https://t.me/xuzongbin001)
- Email：masterai918@gmail.com

本仓库用于项目展示和技术交流。完整源码、数据库脚本、部署文档及资源包的实际范围，请在获取前逐项核验。
