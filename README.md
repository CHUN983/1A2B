# README

## 作者
**姓名：** 孫健淳  
**學號：** [412410109]

---

## 程式概述
本程式實現了一款 1A2B 猜數字遊戲，主要功能包括：

- **遊戲模式：**
  1. 出題者模式：玩家設定數字，電腦負責猜測。
  2. 解答者模式：電腦設定數字，玩家負責猜測。
  3. 雙人模式：兩位玩家輪流擔任出題者與解答者。
  4. 玩家與電腦對戰模式：玩家與電腦競速猜數字。
- **遊戲歷史紀錄：** 記錄每場遊戲的模式、結果及時間戳。
- **易於操作的介面：** 基於選單的系統便於導航。

---

## 程式特色
1. **多樣化遊戲模式：** 提供四種不同的遊戲模式，增加趣味性。
2. **遊戲歷史紀錄：** 儲存並顯示遊戲結果，便於回顧。
3. **作弊檢測：** 確保輸入數據的一致性，維持公平性。
4. **良好程式結構：** 模組化函數設計與可讀的變數命名，方便維護。
5. **強化介面設計:** 使用 ASCII 藝術美化操作介面。
6. **額外功能：**
   - 帶時間戳的遊戲紀錄。
   - 玩家與電腦對戰的競技模式。
   - 玩家與玩家的對戰。
   - 

---

## 流程圖

### User Case
![User Case](photo/usercase.png)

---

### FlowChart
**mainGame.c**
<!-- ![FlowChart](photo/mainGame_flowchart1.png)
![FlowChart](photo/mainGame_flowchart2.png) -->
```mermaid
graph TD
    A[開始] --> B[顯示主選單]
    B --> C{選擇功能}
    C -->|a| D[顯示遊戲說明]
    C -->|b| E[選擇遊戲模式]
    C -->|c| F[查看遊戲歷史]
    C -->|x| G[退出程式]

    D --> B
    F --> B
    G --> H[結束程式]

    E --> I{選擇遊戲模式}
    I -->|1| J[出題者模式]
    I -->|2| K[解答者模式]
    I -->|3| L[雙人模式]
    I -->|4| M[玩家與電腦對戰模式]
    I -->|b| N[返回主選單]

    J --> O[執行出題者模式]
    O --> P[記錄遊戲歷史]
    P --> B

    K --> Q[執行解答者模式]
    Q --> R[記錄遊戲歷史]
    R --> B

    L --> S[執行雙人模式]
    S --> B

    M --> T[玩家猜數字]
    T --> U[記錄玩家嘗試次數]
    U --> V[電腦猜數字]
    V --> W[記錄電腦嘗試次數]
    W --> X{比較結果}
    X -->|玩家獲勝| Y[記錄玩家勝利]
    X -->|電腦獲勝| Z[記錄電腦勝利]
    X -->|平手| AA[記錄平手]
    Y --> AB[顯示結果]
    Z --> AB
    AA --> AB
    AB --> AC{繼續或退出}
    AC -->|繼續| B
    AC -->|退出| H

```

**出題者模式(Questioner)**
<!-- ![FlowChart](photo/questioner_flowchart1.png)
![FlowChart](photo/questioner_flowchart2.png) -->
```mermaid

flowchart TD
    A[Start] --> B[Generate First Guess]
    B --> C[Generate Candidate Table]
    C --> D[Initialize a and b to 0]
    D --> E[Loop until 4A is reached]
    E --> F[Increment Guess Count ]
    F --> G[Display Current Guess]
    G --> H[Get User Input ]
    H --> I{A == 4?}
    I -- Yes --> J[End : Correct Guess]
    I -- No --> K[Invalid Input Handling]
    K --> L[Mark Current Guess as Invalid]
    L --> M[Validate Input : isValidInput]
    M --> N{Input is valid?}
    N -- No --> O[Cheat Detected!]
    N -- Yes --> P[Calculate Remaining Valid Candidates]
    P --> Q[Find Midpoint Candidate]
    Q --> R[Update Guess with Midpoint Candidate]
    R --> E
    O --> Z[End : Cheat Detected]
    J --> Z

```

**解答者模式(guesser)**
<!-- ![FlowChart](photo/guesser_flowchart1.png)
![FlowChart](photo/guesser_flowchart2.png) -->

```mermaid

flowchart TD
    A[Start] --> B[Generate 4-digit Number for Computer]
    B --> C[Set check = 0]
    C --> D[Ask Player to Input Guess]
    D --> E[Get Player's Guess]
    E --> F[Check for Duplicate Digits]
    F --> G{Any Duplicate?}
    G -- Yes --> D[Prompt Player Again]
    G -- No --> H[Compare Player's Guess with Computer's Number]
    H --> I[Calculate A and B]
    I --> J[Display A and B]
    J --> K[Increment Player Guess Count]
    K --> L{Is numA == 4?}
    L -- Yes --> M[End Game and display Player Wins]
    L -- No --> C[Ask Player for Another Guess]
    M --> N[End]
```

**雙人模式(Two-Player)**
<!-- ![FlowChart](photo/twoPlayer_flowchart1.png)
![FlowChart](photo/twoPlayer_flowchart2.png) -->
```mermaid

flowchart TD
    A[Start] --> B[Initialize Game]
    B --> C[Generate Table for Valid Guesses]
    C --> D[Set round = 0, guessPlayer1Num = 0, guessPlayer2Num = 0]
    D --> E[Start Game Loop]
    E --> F{Round > 1?}
    F -- Yes --> G[End Game]
    F -- No --> H[Print Current Player's Turn]
    H --> I[Player Makes Guess]
    I --> J[Check for Duplicate Digits]
    J --> K{Any Duplicates?}
    K -- Yes --> I[Ask Player to Input Again]
    K -- No --> L[Ask Other Player for Hint]
    L --> M[Check if Guess is Correct :NumA == 4]
    M -- No --> N[Invalidate Guess in Record]
    M -- Yes --> O[Print Results and Move to Next Round]
    O --> P[Regenerate Table for Next Round]
    N --> Q[Check if Input is Valid]
    Q --> R{Is Input Valid?}
    R -- No --> S[Print Cheat Message]
    R -- Yes --> T[Continue Loop]
    S --> G[End Game]
    T --> E[Continue Game]
    G --> U[Determine Winner Based on Guesses]
    U --> V[Print Winner]
    V --> W[End]

```

**gameHistory.c**
<!-- ![FlowChart](photo/gameHistory_flowchart.png) -->
```mermaid

flowchart TD
    A[Start] --> B[Generate Current Date]
    B --> C[Create Game Record]
    C --> D[Save Game Record to File]
    D --> E{Is the File Opened Successfully?}
    E -- No --> F[Error: File Could Not Be Opened]
    E -- Yes --> G[Write Record in CSV Format]
    G --> H[Close File]
    H --> I[End]

    subgraph Display Game History
        I1[Start Display Game History]
        I2[Open Game History File]
        I3{Is File Opened?}
        I3 -- No --> I4[Display No Game History]
        I3 -- Yes --> I5[Read File Line by Line]
        I5 --> I6[Parse CSV Line]
        I6 --> I7[Display Parsed Record]
        I7 --> I5
        I5 --> I8[Close File]
        I8 --> I9[End Display]
    end

    subgraph Add Example Record
        A1[Start Add Example Record]
        A2[Create Game Record]
        A3[Fill in Example Data]
        A4[Generate Current Date]
        A5[Save Game Record to File]
        A6[End Example Record]
    end

    B --> I1
    B --> A1


```

---

## 使用說明

### 編譯方式
若有多個檔案，請使用以下指令進行編譯：
```bash
gcc player.c questioner.c mainGame.c gameUI.c twoplayerModel.c gameHistory.c -o game
```

### 執行方式
執行以下指令啟動程式：
```bash
./game
```

### 功能選單
1. **遊戲說明 (a):** 顯示遊戲規則與操作說明。
2. **遊戲模式 (b):**
   - **1:** 出題者模式。
   - **2:** 解答者模式。
   - **3:** 雙人模式。
   - **4:** 玩家與電腦對戰模式。
3. **遊戲歷史 (c):** 檢視過往遊戲紀錄。
4. **退出程式 (x):** 結束程式。

### 遊戲操作
- 根據螢幕指示輸入您的答案或選擇。
- 使用數字鍵 (1-4) 或特定字元 (a, b, c, x) 導航。

---

## 執行畫面截圖

### 主選單
![主選單](photo/gameStart.png)

### 遊戲模式
![遊戲模式](photo/gameMode.png)

### 遊戲過程
#### Questioner Mode
![遊戲過程](photo/questioner.png)
#### Guesser Mode
![遊戲過程](photo/guesser.png)
#### Two-Player Mode
![遊戲過程](photo/twoPlayer.png)
#### Computer vs. Player Mode
![遊戲過程](photo/playerVScomputer1.png)
![遊戲過程](photo/playerVScomputer2.png)

### 遊戲歷史
![遊戲歷史](photo/gameHistory.png)

---

## 新功能
1. **新增猜題記錄：** 新增每次的猜題記錄除了玩家能直接知道自己猜了幾次外，在之後的遊戲紀錄，對戰模式下都有幫助。 
2. **玩家與玩家對戰模式：** 玩家與玩家間自行比賽的方式，其中程式會幫忙檢測玩家間是否存在欺騙的行為。
3. **玩家與電腦對戰模式：** 玩家與電腦競速猜數字的全新模式。
4. **遊戲歷史紀錄：** 所有遊戲均以時間戳記錄並儲存。

---

## 程式品質
- **註解：** 詳盡的註解說明每個函數的邏輯。
- **可讀性：** 恰當的縮排與有意義的變數命名。
- **模組化設計：** 程式碼分為多個檔案，提高可維護性。

---

## 注意事項
- 確保 `game_history.txt` 檔案與程式位於同一目錄下，用於儲存遊戲歷史。
- 如有任何問題或建議，可聯繫信箱：apple0908070605@gmail.com。

