/*
Biblioteci incluse:
LiquidCrystal
*/
#include <LiquidCrystal.h>
// #include <avr/interrupt.h>
// Partea de initializare LiquidCrystal
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Partea de inputOutput
int youWonPin = 21, youLostPin = 20, youLostLed = 22, resetPin = 19, startStopPin = 18, currentTime = 0, showSomething = 0, simulationTime = millis(), runTime = 0, difference = 0;
bool youWonState = false, youLostState = false, startState = false, stopState = false;

// Partea de animatii pe lcd
byte firstFrameSmileyLeftTop[8] = {
B00000,
B00000,
B00000,
B00011,
B00100,
B01000,
B01010,
};
byte firstFrameSmileyRightTop[8] = {
B00000,
B00000,
B00000,
B11000,
B00100,
B00010,
B01010
};
byte firstFrameSmileyLeftBottom[8] = {
B01010,
B01001,
B00100,
B00011,
B00000,
B00000,
B00000
};
byte firstFrameSmileyRightBottom[8] = {
B01010,
B10010,
B00100,
B11000,
B00000,
B00000,
B00000
};
byte secondFrameSmileyLeftTop[8] = {
B00000,
B00000,
B00000,
B00011,
B00100,
B01001,
B01000,
};
byte secondFrameSmileyRightTop[8] = {
B00000,
B00000,
B00000,
B11000,
B00100,
B10010,
B01010
};
byte secondFrameSmileyLeftBottom[8] = {
B01000,
B01001,
B00100,
B00011,
B00000,
B00000,
B00000
};
byte secondFrameSmileyRightBottom[8] = {
B01010,
B10010,
B00100,
B11000,
B00000,
B00000,
B00000
};
byte thirdFrameSmileyLeftTop[8] = {
B00000,
B00000,
B00000,
B00011,
B00100,
B01001,
B01010,
};
byte thirdFrameSmileyRightTop[8] = {
B00000,
B00000,
B00000,
B11000,
B00100,
B10010,
B00010
};
byte thirdFrameSmileyLeftBottom[8] = {
B01010,
B01001,
B00100,
B00011,
B00000,
B00000,
B00000
};
byte thirdFrameSmileyRightBottom[8] = {
B00010,
B10010,
B00100,
B11000,
B00000,
B00000,
B00000
};
byte firstFrameDeathExtremeLeftTop[8] = {
B00000,
B00001,
B00010,
B00100,
B00110,
B00001,
B00000
};
byte firstFrameDeathLeftTop[8] = {
B00000,
B10000,
B10011,
B01100,
B01000,
B01010,
B11010
};
byte firstFrameDeathRightTop[8] = {
B00000,
B00001,
B11001,
B00110,
B00010,
B01010,
B01011
};
byte firstFrameDeathExtremeRightTop[8] = {
B00000,
B10000,
B01000,
B00100,
B01100,
B10000,
B00000
};
byte firstFrameDeathExtremeLeftBottom[8] = {
B00000,
B00000,
B00000,
B00001,
B00010,
B00001,
B00000
};
byte firstFrameDeathLeftBottom[8] = {
B01010,
B01000,
B10101,
B01010,
B10011,
B00001,
B00000
};
byte firstFrameDeathRightBottom[8] = {
B01010,
B00010,
B10101,
B01010,
B11001,
B10000,
B00000
};
byte firstFrameDeathExtremeRightBottom[8] = {
B00000,
B00000,
B00000,
B10000,
B01000,
B10000,
B00000
};
byte secondFrameDeathExtremeLeftTop[8] = {
B00000,
B00011,
B00101,
B01000,
B01100,
B00010,
B00001
};
byte secondFrameDeathLeftTop[8] = {
B00000,
B00000,
B00111,
B11000,
B10000,
B10100,
B10100
};
byte secondFrameDeathRightTop[8] = {
B00000,
B00011,
B10010,
B01100,
B00100,
B10101,
B10110
};
byte secondFrameDeathExtremeRightTop[8] = {
B00000,
B00000,
B10000,
B01000,
B11000,
B00000,
B00000
};
byte secondFrameDeathExtremeLeftBottom[8] = {
B00000,
B00000,
B00001,
B00010,
B00101,
B00010,
B00000
};
byte secondFrameDeathLeftBottom[8] = {
B10100,
B10000,
B01011,
B10100,
B00111,
B00011,
B00000
};
byte secondFrameDeathRightBottom[8] = {
B10100,
B00100,
B01010,
B10101,
B10010,
B00001,
B00000
};
byte secondFrameDeathExtremeRightBottom[8] = {
B00000,
B00000,
B00000,
B00000,
B10000,
B00000,
B00000
};
byte thirdFrameDeathExtremeLeftTop[8] = {
B00000,
B00000,
B00001,
B00010,
B00011,
B00000,
B00000
};
byte thirdFrameDeathLeftTop[8] = {
B00000,
B11000,
B01001,
B00110,
B00100,
B10101,
B01101
};
byte thirdFrameDeathRightTop[8] = {
B00000,
B00000,
B11100,
B00011,
B00001,
B00101,
B00101
};
byte thirdFrameDeathExtremeRightTop[8] = {
B00000,
B11000,
B10100,
B00010,
B00110,
B01000,
B10000
};
byte thirdFrameDeathExtremeLeftBottom[8] = {
B00000,
B00000,
B00000,
B00000,
B00001,
B00000,
B00000
};
byte thirdFrameDeathLeftBottom[8] = {
B00101,
B00100,
B01010,
B10101,
B01001,
B10000,
B00000
};
byte thirdFrameDeathRightBottom[8] = {
B00101,
B00001,
B11010,
B00101,
B11100,
B11000,
B00000
};
byte thirdFrameDeathExtremeRightBottom[8] = {
B00000,
B00000,
B10000,
B01000,
B10100,
B01000,
B00000
};
byte firstFrameGoExtremeLeftTop[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000
};
byte firstFrameGoLeftTop[8] = {
B00001,
B00001,
B00001,
B00001,
B00001,
B00001,
B00001
};
byte firstFrameGoRightTop[8] = {
B10000,
B10000,
B10001,
B10010,
B10100,
B11000,
B10000
};
byte firstFrameGoExtremeRightTop[8] = {
B00000,
B00000,
B10000,
B01000,
B00100,
B00010,
B00001
};
byte firstFrameGoExtremeLeftBottom[8] = {
B10000,
B01000,
B00100,
B00010,
B00001,
B00000,
B00000
};
byte firstFrameGoLeftBottom[8] = {
B00001,
B00011,
B00101,
B01001,
B10001,
B00001,
B00001
};
byte firstFrameGoRightBottom[8] = {
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B10000
};
byte firstFrameGoExtremeRightBottom[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000
};
byte secondFrameGoExtremeLeftTop[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000
};
byte secondFrameGoLeftTop[8] = {
B00001,
B00001,
B00001,
B00001,
B00001,
B00001,
B00001
};
byte secondFrameGoRightTop[8] = {
B10000,
B10000,
B10011,
B10100,
B11000,
B10000,
B10000
};
byte secondFrameGoExtremeRightTop[8] = {
B00000,
B00000,
B00000,
B10000,
B01000,
B00100,
B00010
};
byte secondFrameGoExtremeLeftBottom[8] = {
B00000,
B10000,
B01000,
B00100,
B00011,
B00000,
B00000
};
byte secondFrameGoLeftBottom[8] = {
B00011,
B00101,
B01001,
B10001,
B00001,
B00001,
B00001
};
byte secondFrameGoRightBottom[8] = {
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B10000
};
byte secondFrameGoExtremeRightBottom[8] = {
B00001,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000
};
byte thirdFrameGoExtremeLeftTop[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000
};
byte thirdFrameGoLeftTop[8] = {
B00001,
B00001,
B00001,
B00001,
B00001,
B00001,
B00011
};
byte thirdFrameGoRightTop[8] = {
B10000,
B10000,
B10110,
B11001,
B10000,
B10000,
B10000
};
byte thirdFrameGoExtremeRightTop[8] = {
B00000,
B00000,
B00000,
B00000,
B10000,
B01000,
B00100
};
byte thirdFrameGoExtremeLeftBottom[8] = {
B00000,
B00000,
B10000,
B01001,
B00110,
B00000,
B00000
};
byte thirdFrameGoLeftBottom[8] = {
B00101,
B01001,
B10001,
B00001,
B00001,
B00001,
B00001
};
byte thirdFrameGoRightBottom[8] = {
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B10000
};
byte thirdFrameGoExtremeRightBottom[8] = {
B00010,
B00001,
B00000,
B00000,
B00000,
B00000,
B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(youLostPin, INPUT_PULLUP);
  pinMode(youWonPin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
  pinMode(startStopPin, INPUT_PULLUP);
  pinMode(youLostLed, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(youLostPin), youLostFunction, RISING);
  attachInterrupt(digitalPinToInterrupt(youWonPin), youWonFunction, RISING);
  attachInterrupt(digitalPinToInterrupt(resetPin), resetFunction, RISING);
  attachInterrupt(digitalPinToInterrupt(startStopPin), setStartStopFunction, RISING);
  digitalWrite(youLostLed, LOW);
  startState = false;
}

void loop() {

  // put your main code here, to run repeatedly:
  if(startState){
    if(!youWonState && !youLostState){
      showRun();
    }
    if(youWonState){
        showVictory();
    }
    if(youLostState){
        showLoss();
    }
  }
  if(stopState){
      showStop();
  }
  if(!startState && !stopState){
      showGreetings();
  }
    do{
        runTime = millis();
        difference = runTime - simulationTime;
    }while(difference != 1000);
    simulationTime = runTime;
}

void showRun(){
      digitalWrite(youLostLed, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(currentTime);
      currentTime++;
      lcd.print(" Go!");
      drawGo(currentTime % 3);
      
}
void showStop(){
      digitalWrite(youLostLed, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(currentTime);
      lcd.print(" STOP!");
      

}
void showGreetings(){
      digitalWrite(youLostLed, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Welcome!");
      

}

void youLostFunction(){
    youLostState = true;
    // startState = false;
    // stopState = false;
}
void youWonFunction(){
    youWonState = true;
    // startState = false;
    // stopState = false;
}

void resetFunction(){
    currentTime = 0;
    youLostState = false;
    youWonState = false;
    startState = false;
    stopState = false;
}
void setStartStopFunction(){
    if(!startState){
        startState = true;
        stopState = false;
    }else{
        startState = false;
        stopState = true;
    }
}

void showVictory(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You won!");
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(currentTime);
    digitalWrite(youLostLed, LOW);
    showSomething = (showSomething + 1) % 3;
    drawSmileyFace(showSomething);
}

void showLoss(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You lost!");
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(currentTime);
    digitalWrite(youLostLed, HIGH);
    showSomething = (showSomething + 1) % 3;
    drawDeathFace(showSomething);
}
void drawSmileyFace(int val){
    switch (val){
        case 0 : drawFirstSmileyFrame(); break;
        case 1 : drawSecondSmileyFrame(); break;
        case 2 : drawThirdSmileyFrame(); break;
    }
}
void drawFirstSmileyFrame(){
    lcd.createChar(0, firstFrameSmileyLeftTop);
    lcd.createChar(1, firstFrameSmileyRightTop);
    lcd.createChar(2, firstFrameSmileyLeftBottom);
    lcd.createChar(3, firstFrameSmileyRightBottom);
    lcd.setCursor(14, 0);
    lcd.write(byte(0));
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(3));
}
void drawSecondSmileyFrame(){
    lcd.createChar(0, secondFrameSmileyLeftTop);
    lcd.createChar(1, secondFrameSmileyRightTop);
    lcd.createChar(2, secondFrameSmileyLeftBottom);
    lcd.createChar(3, secondFrameSmileyRightBottom);
    lcd.setCursor(14, 0);
    lcd.write(byte(0));
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(3));
}
void drawThirdSmileyFrame(){
    lcd.createChar(0, thirdFrameSmileyLeftTop);
    lcd.createChar(1, thirdFrameSmileyRightTop);
    lcd.createChar(2, thirdFrameSmileyLeftBottom);
    lcd.createChar(3, thirdFrameSmileyRightBottom);
    lcd.setCursor(14, 0);
    lcd.write(byte(0));
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(3));
}
void drawDeathFace(int val){
    switch (val){
        case 0 : drawFirstDeathFrame(); break;
        case 1 : drawSecondDeathFrame(); break;
        case 2 : drawThirdDeathFrame(); break;
    }
}
void drawFirstDeathFrame(){
    lcd.createChar(0, firstFrameDeathExtremeLeftTop);
    lcd.createChar(1, firstFrameDeathLeftTop);
    lcd.createChar(2, firstFrameDeathRightTop);
    lcd.createChar(3, firstFrameDeathExtremeRightTop);
    lcd.createChar(4, firstFrameDeathExtremeLeftBottom);
    lcd.createChar(5, firstFrameDeathLeftBottom);
    lcd.createChar(6, firstFrameDeathRightBottom);
    lcd.createChar(7, firstFrameDeathExtremeRightBottom);
    lcd.setCursor(12, 0);
    lcd.write(byte(0));
    lcd.setCursor(13, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 0);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(4));
    lcd.setCursor(13, 1);
    lcd.write(byte(5));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    lcd.setCursor(15, 1);
    lcd.write(byte(7));
}
void drawSecondDeathFrame(){
    lcd.createChar(0, secondFrameDeathExtremeLeftTop);
    lcd.createChar(1, secondFrameDeathLeftTop);
    lcd.createChar(2, secondFrameDeathRightTop);
    lcd.createChar(3, secondFrameDeathExtremeRightTop);
    lcd.createChar(4, secondFrameDeathExtremeLeftBottom);
    lcd.createChar(5, secondFrameDeathLeftBottom);
    lcd.createChar(6, secondFrameDeathRightBottom);
    lcd.createChar(7, secondFrameDeathExtremeRightBottom);
    lcd.setCursor(12, 0);
    lcd.write(byte(0));
    lcd.setCursor(13, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 0);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(4));
    lcd.setCursor(13, 1);
    lcd.write(byte(5));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    lcd.setCursor(15, 1);
    lcd.write(byte(7));
}
void drawThirdDeathFrame(){
    lcd.createChar(0, thirdFrameDeathExtremeLeftTop);
    lcd.createChar(1, thirdFrameDeathLeftTop);
    lcd.createChar(2, thirdFrameDeathRightTop);
    lcd.createChar(3, thirdFrameDeathExtremeRightTop);
    lcd.createChar(4, thirdFrameDeathExtremeLeftBottom);
    lcd.createChar(5, thirdFrameDeathLeftBottom);
    lcd.createChar(6, thirdFrameDeathRightBottom);
    lcd.createChar(7, thirdFrameDeathExtremeRightBottom);
    lcd.setCursor(12, 0);
    lcd.write(byte(0));
    lcd.setCursor(13, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 0);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(4));
    lcd.setCursor(13, 1);
    lcd.write(byte(5));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    lcd.setCursor(15, 1);
    lcd.write(byte(7));
}

void drawGo(int val){
    switch (val){
        case 0: drawFirstGoFrame(); break;
        case 1: drawSecondGoFrame(); break;
        case 2: drawThirdGoFrame(); break;
    }
}
void drawFirstGoFrame(){
    lcd.createChar(0, firstFrameGoExtremeLeftTop);
    lcd.createChar(1, firstFrameGoLeftTop);
    lcd.createChar(2, firstFrameGoRightTop);
    lcd.createChar(3, firstFrameGoExtremeRightTop);
    lcd.createChar(4, firstFrameGoExtremeLeftBottom);
    lcd.createChar(5, firstFrameGoLeftBottom);
    lcd.createChar(6, firstFrameGoRightBottom);
    lcd.createChar(7, firstFrameGoExtremeRightBottom);
    lcd.setCursor(12, 0);
    lcd.write(byte(0));
    lcd.setCursor(13, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 0);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(4));
    lcd.setCursor(13, 1);
    lcd.write(byte(5));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    lcd.setCursor(15, 1);
    lcd.write(byte(7));
}
void drawSecondGoFrame(){
    lcd.createChar(0, secondFrameGoExtremeLeftTop);
    lcd.createChar(1, secondFrameGoLeftTop);
    lcd.createChar(2, secondFrameGoRightTop);
    lcd.createChar(3, secondFrameGoExtremeRightTop);
    lcd.createChar(4, secondFrameGoExtremeLeftBottom);
    lcd.createChar(5, secondFrameGoLeftBottom);
    lcd.createChar(6, secondFrameGoRightBottom);
    lcd.createChar(7, secondFrameGoExtremeRightBottom);
    lcd.setCursor(12, 0);
    lcd.write(byte(0));
    lcd.setCursor(13, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 0);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(4));
    lcd.setCursor(13, 1);
    lcd.write(byte(5));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    lcd.setCursor(15, 1);
    lcd.write(byte(7));
}
void drawThirdGoFrame(){
    lcd.createChar(0, thirdFrameGoExtremeLeftTop);
    lcd.createChar(1, thirdFrameGoLeftTop);
    lcd.createChar(2, thirdFrameGoRightTop);
    lcd.createChar(3, thirdFrameGoExtremeRightTop);
    lcd.createChar(4, thirdFrameGoExtremeLeftBottom);
    lcd.createChar(5, thirdFrameGoLeftBottom);
    lcd.createChar(6, thirdFrameGoRightBottom);
    lcd.createChar(7, thirdFrameGoExtremeRightBottom);
    lcd.setCursor(12, 0);
    lcd.write(byte(0));
    lcd.setCursor(13, 0);
    lcd.write(byte(1));
    lcd.setCursor(14, 0);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(4));
    lcd.setCursor(13, 1);
    lcd.write(byte(5));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    lcd.setCursor(15, 1);
    lcd.write(byte(7));
    
}
