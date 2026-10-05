# 德州撲克原始碼｜德州撲克大廳|C++ 回呼、撲克協議、SNG 與 MTT 產品資料

[主 README](README.md) · [简体中文](README.zh-CN.md) · [English](README.en.md) · [繁體中文產品頁](https://alibabama401.github.io/Texas-Holdem-Online-Poker-Platform/zh-tw/)

本倉庫公開德州撲克專案中的部分 C++ 非同步回呼、機器人批次計時邏輯、登入/大廳/俱樂部/賽事/牌局記錄協議資源，以及經典牌桌、SNG、MTT、配桌和商城產品截圖。

## 玩法與功能

| 場景 | 可核驗資料 |
|---|---|
| 經典德州 | 牌桌與行動區截圖、`dz.proto.bytes` 訊息結構 |
| SNG / MTT | 產品截圖、賽事房間和費用/獎勵協議欄位 |
| 俱樂部 | 建立、加入、成員、審核、邀請和退出訊息結構 |
| 登入與帳戶 | 多種登入協議和使用者資訊 C++ 回呼 |
| 機器人與 AI | 推送、AI 決策、批次設定和時間檢查程式碼片段 |
| 大廳與商城 | 大廳、配桌、商城截圖和 Hall 協議資源 |

## 產品截圖

| 大廳 | 經典牌桌 |
|---|---|
| ![線上德州撲克大廳](docs/assets/screenshots/002dating.png) | ![經典德州撲克即時牌桌](docs/assets/screenshots/004jingdian.jpg) |
| **MTT** | **SNG** |
| ![MTT 多桌錦標賽](docs/assets/screenshots/005mtt.jpg) | ![SNG 單桌錦標賽](docs/assets/screenshots/008sng.jpg) |
| **配桌** | **商城** |
| ![玩家配桌與座位](docs/assets/screenshots/006paizuo.png) | ![撲克平台商城](docs/assets/screenshots/007shop.png) |

## 技術範圍

- C++：使用者帳戶、AI 決策、機器人推送和計時邏輯片段。
- 協議：登入、大廳、俱樂部、設定、牌局記錄、聊天和德州訊息資源。
- Unity：僅公開部分場景 `.meta`，未公開相應場景本體。
- 文件：API 與部署範例，需要結合完整工程驗證。

## 重要說明

目前檔案不足以直接建置完整用戶端或伺服器。倉庫缺少部分標頭檔、實作、建置設定、資料庫腳本、服務入口和 Unity 場景資源。`LICENSE`、`License.md` 與 `CITATION.cff` 的授權描述也不完全一致，使用前應取得統一書面說明。

## 聯絡

[Email](mailto:ttpoker40@gmail.com) · [Telegram @alibabama401](https://t.me/alibabama401) · [GitHub](https://github.com/alibabama401/Texas-Holdem-Online-Poker-Platform)
