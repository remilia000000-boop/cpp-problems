---
inclusion: always
name: cpp-learning-progress
description: 記錄這位學徒目前的 C++、LeetCode 與迷你防火牆專題學習進度，讓後續 session 能直接接續教學。
---

# C++、LeetCode 與專題學習進度

最後更新：2026-10-07

## 學習者背景與目標

- 資工系大二學生，對系統最有興趣、演算法次之。
- 目前主要使用 C++，未來可能學 Python。
- 大三畢業專題目標：使用 C++ 與 libpcap 製作可運行的迷你防火牆／封包過濾器。
- 偏好先自己嘗試；卡住時採「方向提示 → 關鍵觀念 → 必要時完整解法」的節奏。

## 已完成內容

- C++／系統基礎練習：`practice/bit-extract-ip.cpp`
  - 使用右移取得 IPv4 最高 8 位元。
  - 認識 `uint8_t`、`static_cast<int>` 與位元組輸出的字元陷阱。
- LeetCode 1 — Two Sum：暴力 O(n²) 改寫為 `unordered_map` O(n)。
- LeetCode 26 — Remove Duplicates from Sorted Array：雙指針、原地修改與空陣列邊界。
- LeetCode 136 — Single Number：XOR，時間 O(n)、額外空間 O(1)。
- LeetCode 208 — Implement Trie (Prefix Tree)：自行實作 `insert`、`search`、`startsWith`。
- LeetCode 283 — Move Zeroes：雙指針搭配 `swap`，時間 O(n)、額外空間 O(1)。

## 已掌握或接觸的觀念

- 位元右移、XOR、mask 的基本概念。
- 雙指針與原地陣列操作。
- Hash Table：`unordered_map` 的插入、`find` 與查找。
- Trie：`children[26]`、`c - 'a'`、`isEnd`、節點建立與路徑查找。
- Git 基礎：clone、add、commit、pull、push，以及用 `.gitignore` 排除 `.exe`。

## 曾踩過、需要持續留意的坑

- `uint8_t` 常是字元型別；直接交給 `std::cout` 可能印成字元，數值輸出可用 `static_cast<int>`。
- `children` 指標陣列必須初始化為 `nullptr`；曾因索引變數打錯造成未初始化指標與 Runtime Error，並已自行定位修正。
- `new` 建立的 Trie 節點尚未練習如何釋放；要建立「誰 `new`、誰負責釋放」的資源管理觀念。
- 避免 `int` 與 `size_t` 的 signed／unsigned 比較警告。
- 不要在迴圈更新式之外意外再寫一次 `i++`，以免跳過元素。
- 先理解每題的不變量，再決定是否沿用上一題的 `swap` 或雙指針寫法。

## 下一步

1. 學習 Trie 的記憶體生命週期：解構子、遞迴釋放，再認識 `std::unique_ptr` 與 RAII。
2. 繼續 Easy LeetCode，優先鞏固 Hash、位元運算、字串與雙指針；暫不急著挑大量 Medium。
3. 逐步進入 Linux、socket、TCP/IP、Wireshark 與 libpcap，為迷你防火牆做準備。

## 給後續家教的接續方式

- 不要重複從 C++ 最基礎語法開始；先用一題短練習確認記憶，再接續上述下一步。
- 不要把 LeetCode 執行時間百分位當成可靠的演算法證據；以複雜度、正確性與可讀性為主要評估標準。
- 題目完成後提醒將程式碼放入 `leetcode/` 或 `practice/`，但除非使用者要求，不要代替他直接寫完整題解。
