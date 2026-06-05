#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0


const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};
byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};

byte circle[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}};

// 修正：原本有多一列，已刪除
byte H[8][8] = {
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0}
};

byte A[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0}
};
void setup() {
  Serial.begin(9600);
  
  // 初始化引腳，修正原本的 PinMode 大小寫與重複 setup 問題
  for(byte i = 0; i < 8; i++) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
  }
}

void loop() {
  // 顯示第一個圖案 (circle) 持續 1000 毫秒 (1秒)
  unsigned long startTime = millis();
  while(millis() - startTime < 1000) {
    showPattern(circle);
  }

  // 顯示第二個圖案 (H) 持續 1000 毫秒 (1秒)
  startTime = millis();
  while(millis() - startTime < 1000) {
    showPattern(H);
  }

  // 顯示第三個圖案 (A) 持續 1000 毫秒 (1秒)
  startTime = millis();
  while(millis() - startTime < 1000) {
    showPattern(A);
  }
}

// 負責刷新顯示 LED 點矩陣的函數
void showPattern(byte matrix[8][8]) {
  for(byte i = 0; i < 8; i++) {
    for(byte j = 0; j < 8; j++) {
      digitalWrite(row[j], 1 - scan[i][j]);
      digitalWrite(col[j], 1 - matrix[i][j]); 
    }
    // 稍微延時讓該列點亮，避免閃爍或太暗
    delayMicroseconds(500); 
    
    // 清除殘影
    for(byte j = 0; j < 8; j++) {
      digitalWrite(row[j], HIGH);
      digitalWrite(col[j], LOW);  
    }
  }
}