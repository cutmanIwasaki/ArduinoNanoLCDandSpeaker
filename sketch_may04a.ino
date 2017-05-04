#include <Wire.h>
#define LCD_ADRS 0x3E   //LCDのI2Cアドレス
char moji[] ="welcome to yokoso japariPark";
char moji2[] = "wait while";
char moji3[] = "playing";
#define BEATTIME 1000 //音を出している時間(msec)
#define SPEAKER 2 //スピーカーの出力ピン番号

//音階生成関数
void do1(int beattime){
  tone(SPEAKER,262,beattime) ; // ド
  delay(beattime) ;
}
void do2(int beattime){
  tone(SPEAKER,523,beattime) ; 
  delay(beattime) ;
}
void do3(int beattime){
  tone(SPEAKER,1046,beattime) ; 
  delay(beattime) ;
}
void re1(int beattime){
  tone(SPEAKER,294,beattime) ; 
  delay(beattime) ;
}
void re2(int beattime){
  tone(SPEAKER,582,beattime) ; 
  delay(beattime) ;
}
void re3(int beattime){
  tone(SPEAKER,1164,beattime) ; 
  delay(beattime) ;
}
void mi1(int beattime){
  tone(SPEAKER,330,beattime) ; 
  delay(beattime) ;
}
void mi2(int beattime){
  tone(SPEAKER,660,beattime) ; 
  delay(beattime) ;
}
void fa1(int beattime){
  tone(SPEAKER,349,beattime) ; 
  delay(beattime) ;
}
void fa2(int beattime){
  tone(SPEAKER,698,beattime) ; 
  delay(beattime) ;
}
void so1(int beattime){
  tone(SPEAKER,392,beattime) ; 
  delay(beattime) ;
}
void so2(int beattime){
  tone(SPEAKER,784,beattime) ; 
  delay(beattime) ;
}
void ra1(int beattime){
  tone(SPEAKER,440,beattime) ; 
  delay(beattime) ;
}
void ra2(int beattime){
  tone(SPEAKER,880,beattime) ; 
  delay(beattime) ;
}
void shi1(int beattime){
  tone(SPEAKER,494,beattime) ; 
  delay(beattime) ;
}
void shi2(int beattime){
  tone(SPEAKER,988,beattime) ; 
  delay(beattime) ;
}
void Xshi2(int beattime){
  tone(SPEAKER,932,beattime) ; 
  delay(beattime) ;
}
//ようこそジャパリパークへ冒頭
void kemono(){
  delay(1000);
  ra1(300);
  fa1(300);
  delay(300);
  do1(300);
  do2(300);
  delay(300);
  ra1(800);
  delay(1000);
  //begin
  fa2(200);
  mi2(200);
  fa2(200);
  so2(400);
  fa2(200);
  so2(200);
  ra2(400);
  Xshi2(200);
  delay(10);
  Xshi2(190);
  do3(400);
  
  ra2(200);
  so2(200);
  fa2(200);
  fa2(400);
  re3(400);
  do3(400);
  fa2(400);
  re2(400);
  Xshi2(400);
  ra2(400);
  so2(400);
  fa2(800);
  
  
}


void writeData(byte t_data)
{
 Wire.beginTransmission(LCD_ADRS);
 Wire.write(0x40);
 Wire.write(t_data);
 Wire.endTransmission();
delay(1);
}
//コマンド書き込み
void writeCommand(byte t_command)
{
   Wire.beginTransmission(LCD_ADRS);
   Wire.write(0x00);
   Wire.write(t_command);
   Wire.endTransmission();
   delay(10);
}
//液晶初期化
void init_LCD() {
  delay(100);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x39);
  delay(20);
  writeCommand(0x14);
  delay(20);
  writeCommand(0x73);
  delay(20);
  writeCommand(0x52);
  delay(20);
  writeCommand(0x6C);
  delay(250);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x01);
  delay(20);
  writeCommand(0x0C);
  delay(20);
}
//LCDへ文字列送信
void LCD_str(char *c) {
  unsigned char i,wk;
  for (i=0 ; ; i++) {
    wk = c[i];
    if  (wk == 0x00) {break;}
    writeData(wk);
  }

}

void setup() {
  Wire.begin();
  init_LCD();
  writeCommand(0x01);   //画面をクリア
  writeCommand(0x02);   //ホーム（アドレス０）へカーソル移動
  delay(2);             //処理待ち
  
  LCD_str(moji);
  
  writeCommand(0x40+0x80); // 2列目へ移動
  LCD_str(moji2);

  for(int i=0;i<20;i++){        //画面を左向きに移動
    writeCommand(0b00011000);
  delay(300);
  }
  
  int FREQCOUNT = 0;
  for(FREQCOUNT = 0;FREQCOUNT < 10000;FREQCOUNT++){   //起動音
    tone(SPEAKER,FREQCOUNT,BEATTIME);
    delayMicroseconds(100);
  }  
  
}
void loop() {
  writeCommand(0x01);   //画面をクリア
  writeCommand(0x02);   //ホーム（アドレス０）へカーソル移動
  delay(2);             //処理待ち
  LCD_str(moji3);
  kemono();             //ようこそジャパリパークへ演奏
} 

