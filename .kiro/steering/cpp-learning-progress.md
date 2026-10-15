---
inclusion: always
name: cpp-learning-progress
description: 記錄這位學徒目前的 C++、LeetCode 與迷你防火牆專題學習進度，讓後續 session 能直接接續教學。
---

# C++、LeetCode 與專題學習進度

最後更新：2026-10-12

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
- LeetCode 338 — Counting Bits：DP + 位元運算，`ans[i] = ans[i & (i - 1)] + 1`，時間 O(n)。
  - 初版用 `get_two(int& num)` 以參考傳入迴圈變數 `i`，`num /= 2` 把 `i` 改成 0 導致迴圈無法前進 → TLE；改成傳值 `int num` 後 AC。
  - 進一步學會用「已算過的答案」推導（DP），同一個 `ans` 陣列既是答案也是快取。
- LeetCode 191 — Number of 1 Bits：Brian Kernighan（`n & (n - 1)` 消滅最低位的 1），迴圈只跑「1 的個數」次。
- LeetCode 125 — Valid Palindrome：雙指針夾逼 + 字串清理（`isalnum`、`tolower`），時間 O(n)、額外空間 O(1)。
  - 初版在「配對相等」後忘了讓指標前進 → 無限迴圈 TLE；改用「內層 while 推進指標 + 外層比較並前進」的標準骨架後 AC。
  - 自行悟出 `s[left++]` / `s[right--]`（後綴遞增）把前進融入比較式。

## 已掌握或接觸的觀念

- 位元右移、XOR、mask 的基本概念。
- 位元運算進階：`i & (i - 1)` 可清掉最低位的 1（Brian Kernighan 數 bit、判斷 2 的次方的核心）；`i & 1` 取最低位、`i >> 1` 去掉最低位。
- 動態規劃入門：用已算過的子結果推導當前答案，同一陣列兼任「答案」與「快取」（Counting Bits）。
- 雙指針標準骨架：以內層 `while` 將指標推進到合法位置，外層只做「比較 + 一起前進」，確保每輪指標必動、不會無限迴圈。
- 傳值 vs. 傳參考：`int`（複本，讀取用）vs. `int&`（本尊，刻意修改才用）；日後處理封包用 `const T&` 兼顧效能與安全。
- 字串字元處理：`<cctype>` 的 `isalnum`、`tolower`，呼叫前需 `static_cast<unsigned char>` 避免有號 char 變負數的 UB。
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
- 不要用參考（`int&`）去接收迴圈變數再在函式內修改它，會改到本尊造成迴圈卡死（Counting Bits TLE 的死因）。只需讀取就傳值。
- 雙指針「配對成功後」務必推進指標（`left++`/`right--`），否則迴圈無法收斂、無限迴圈 TLE（Valid Palindrome 的死因）。
- 位元運算、處理 raw byte / 旗標 / IP / 埠號時一律用無號數（`unsigned`、`uint32_t`、`uint8_t`）；有號數的符號位會在右移與比較時埋雷。
- `size_t`（無號）做減法會回繞：空字串時 `s.size() - 1` 變超大值；需要可能為負的索引時改用有號 `int` 並明確轉型。
- 呼叫 `isalnum`/`tolower` 等 `<cctype>` 函式前，先 `static_cast<unsigned char>`，否則有號 char 的負值是 UB。

## 下一步

1. 學習 Trie 的記憶體生命週期：解構子、遞迴釋放，再認識 `std::unique_ptr` 與 RAII。（仍未完成，優先度高，直接連結防火牆專題。）
2. 位元運算已連下 338、191 兩題並熟悉 `n & (n-1)`；可再點 231（Power of Two）、461（Hamming Distance）收尾，然後把重心移往字串與雙指針。
3. 字串／雙指針：已完成 125；可續寫 167（Two Sum II，有序陣列雙指針，已出題尚未寫）、680（Valid Palindrome II）。
4. 逐步進入 Linux、socket、TCP/IP、Wireshark 與 libpcap，為迷你防火牆做準備。

## 給後續家教的接續方式

- 不要重複從 C++ 最基礎語法開始；先用一題短練習確認記憶，再接續上述下一步。
- 不要把 LeetCode 執行時間百分位當成可靠的演算法證據；以複雜度、正確性與可讀性為主要評估標準。
- 題目完成後提醒將程式碼放入 `leetcode/` 或 `practice/`，但除非使用者要求，不要代替他直接寫完整題解。
