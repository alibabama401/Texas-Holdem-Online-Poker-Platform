# 德州扑克源码｜C++ 回调、扑克协议、SNG 与 MTT 产品资料

[主 README](README.md) · [繁體中文](README.zh-TW.md) · [English](README.en.md) · [简体中文产品页](https://alibabama401.github.io/Texas-Holdem-Online-Poker-Platform/zh-cn/)

本仓库公开德州扑克项目中的部分 C++ 异步回调、机器人批次时间逻辑、登录/大厅/俱乐部/赛事/牌局记录协议资源，以及经典牌桌、SNG、MTT、配桌和商城产品截图。

## 玩法与功能

| 场景 | 可核验资料 |
|---|---|
| 经典德州 | 牌桌与行动区截图、`dz.proto.bytes` 消息结构 |
| SNG / MTT | 产品截图、赛事房间和费用/奖励协议字段 |
| 俱乐部 | 创建、加入、成员、审核、邀请和退出消息结构 |
| 登录与账户 | 多种登录协议和用户信息 C++ 回调 |
| 机器人与 AI | 推送、AI 决策、批次配置和时间检查代码片段 |
| 大厅与商城 | 大厅、配桌、商城截图和 Hall 协议资源 |

## 产品截图

| 大厅 | 经典牌桌 |
|---|---|
| ![在线德州扑克大厅](docs/assets/screenshots/002dating.png) | ![经典德州扑克实时牌桌](docs/assets/screenshots/004jingdian.jpg) |
| **MTT** | **SNG** |
| ![MTT 多桌锦标赛](docs/assets/screenshots/005mtt.jpg) | ![SNG 单桌锦标赛](docs/assets/screenshots/008sng.jpg) |
| **配桌** | **商城** |
| ![玩家配桌与座位](docs/assets/screenshots/006paizuo.png) | ![扑克平台商城](docs/assets/screenshots/007shop.png) |

## 技术范围

- C++：用户账户、AI 决策、机器人推送和定时逻辑片段。
- 协议：登录、大厅、俱乐部、配置、牌局记录、聊天和德州消息资源。
- Unity：仅公开部分场景 `.meta`，未公开相应场景本体。
- 文档：API 与部署示例，需要结合完整工程验证。

## 重要说明

当前文件不足以直接构建完整客户端或服务端。仓库缺少部分头文件、实现、构建配置、数据库脚本、服务入口和 Unity 场景资源。`LICENSE`、`License.md` 与 `CITATION.cff` 的授权描述也不完全一致，使用前应取得统一书面说明。

## 联系

[Email](mailto:ttpoker40@gmail.com) · [Telegram @alibabama401](https://t.me/alibabama401) · [GitHub](https://github.com/alibabama401/Texas-Holdem-Online-Poker-Platform)
