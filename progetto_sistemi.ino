#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

#define LCD_RESET A4
#define DHTPIN 53
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));

  tft.reset();

  uint16_t identifier = tft.readID();
  if (identifier == 0x0101)
    identifier = 0x9341;
  else
    identifier = 0x9486;

  tft.begin(identifier);
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  tft.fillRect(0, 80, 480, 5, RED );
  tft.fillRect(0, 0, 480, 80, RED);

  tft.setCursor(0, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("Stefano Zipoli");

  tft.setCursor(0, 30);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  tft.println("CONTROLLO TEMPERATURA E UMIDITA'");

  tft.setCursor(0, 50);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  tft.println("Stanza: salotto");

}

void loop(void) {
  int  h = dht.readHumidity(); //leggo il valore dell'umidità
  int temp = dht.readTemperature();  //leggo il valore della temperatura
  goccia();   //disegno goccia
  if (temp < 10)
    TempMinore10(); //disegno termometro per temperatura minore di 10 gradi
  else if (temp >= 10 && temp < 27 )
    Temp_10_27();  //disegno termometro per temperatura compresa tra 10 gradi e 27 gradi
  else
    TempMaggiore27(); // disegno termometro per temperatura maggiore di 27 gradi
  umidita(h);  // stampo a schermo l'umidità
  temperatura(temp);  // stampo a schermo la temperatura
  for (int i = 80; i < 315; i++)
    tft.fillRect(240, i, 5, 5, RED); //linea di mezzo che separa temperatura e umidità
}
void goccia() {
  tft.fillRect(120, 245, 5, 5, CYAN);
  tft.fillRect(120, 250, 5, 5, CYAN);
  tft.fillRect(120, 255, 5, 5, CYAN);
  tft.fillRect(125, 255, 5, 5, CYAN);
  tft.fillRect(115, 255, 5, 5, CYAN);
  tft.fillRect(120, 260, 5, 5, CYAN);
  tft.fillRect(125, 260, 5, 5, CYAN);
  tft.fillRect(115, 260, 5, 5, CYAN);
  tft.fillRect(120, 265, 5, 5, CYAN);
  tft.fillRect(125, 265, 5, 5, CYAN);
  tft.fillRect(115, 265, 5, 5, CYAN);
  tft.fillRect(130, 265, 5, 5, CYAN);
  tft.fillRect(110, 265, 5, 5, CYAN);
  tft.fillRect(120, 270, 5, 5, CYAN);
  tft.fillRect(125, 270, 5, 5, CYAN);
  tft.fillRect(115, 270, 5, 5, CYAN);
  tft.fillRect(130, 270, 5, 5, CYAN);
  tft.fillRect(110, 270, 5, 5, CYAN);
  tft.fillRect(120, 275, 5, 5, CYAN);
  tft.fillRect(125, 275, 5, 5, CYAN);
  tft.fillRect(115, 275, 5, 5, CYAN);
  tft.fillRect(130, 275, 5, 5, CYAN);
  tft.fillRect(110, 275, 5, 5, CYAN);
  tft.fillRect(120, 280, 5, 5, CYAN);
  tft.fillRect(125, 280, 5, 5, CYAN);
  tft.fillRect(115, 280, 5, 5, CYAN);
}
void TempMinore10() {
  {
    tft.fillRect(380, 225, 5, 5, WHITE);
    tft.fillRect(385, 225, 5, 5, WHITE);
    tft.fillRect(375, 230, 5, 5, WHITE);
    tft.fillRect(390, 230, 5, 5, WHITE);
    tft.fillRect(375, 235, 5, 5, WHITE);
    tft.fillRect(390, 235, 5, 5, WHITE);
    tft.fillRect(375, 240, 5, 5, WHITE);
    tft.fillRect(390, 240, 5, 5, WHITE);
    tft.fillRect(375, 245, 5, 5, WHITE);
    tft.fillRect(390, 245, 5, 5, WHITE);
    tft.fillRect(385, 245, 5, 5, WHITE);
    tft.fillRect(375, 250, 5, 5, WHITE);
    tft.fillRect(390, 250, 5, 5, WHITE);
    tft.fillRect(375, 255, 5, 5, WHITE);
    tft.fillRect(390, 255, 5, 5, WHITE);
    tft.fillRect(375, 260, 5, 5, WHITE);
    tft.fillRect(390, 260, 5, 5, WHITE);
    tft.fillRect(385, 260, 5, 5, WHITE);
    tft.fillRect(375, 265, 5, 5, WHITE);
    tft.fillRect(390, 265, 5, 5, WHITE);
    tft.fillRect(375, 270, 5, 5, WHITE);
    tft.fillRect(390, 270, 5, 5, WHITE);
    tft.fillRect(375, 275, 5, 5, WHITE);
    tft.fillRect(390, 275, 5, 5, WHITE);
    tft.fillRect(385, 275, 5, 5, WHITE);
    tft.fillRect(370, 280, 5, 5, WHITE);
    tft.fillRect(395, 280, 5, 5, WHITE);
    tft.fillRect(365, 285, 5, 5, WHITE);
    tft.fillRect(400, 285, 5, 5, WHITE);
    tft.fillRect(365, 290, 5, 5, WHITE);
    tft.fillRect(400, 290, 5, 5, WHITE);
    tft.fillRect(365, 295, 5, 5, WHITE);
    tft.fillRect(400, 295, 5, 5, WHITE);
    tft.fillRect(370, 300, 5, 5, WHITE);
    tft.fillRect(395, 300, 5, 5, WHITE);
    tft.fillRect(375, 305, 5, 5, WHITE);
    tft.fillRect(390, 305, 5, 5, WHITE);
    tft.fillRect(380, 305, 5, 5, WHITE);
    tft.fillRect(385, 305, 5, 5, WHITE);
    tft.fillRect(380, 255, 10, 5, BLACK);
    tft.fillRect(380, 260, 5, 5, BLACK);
    tft.fillRect(380, 265, 10, 5, BLACK);
    tft.fillRect(380, 270, 10, 5, BLACK);
    tft.fillRect(380, 275, 5, 5, RED);
    tft.fillRect(375, 280, 20, 5, RED);
    tft.fillRect(370, 285, 30, 15, RED);
    tft.fillRect(375, 300, 20, 5, RED);
  }
}
void Temp_10_27() {
  tft.fillRect(380, 225, 5, 5, WHITE);
  tft.fillRect(385, 225, 5, 5, WHITE);
  tft.fillRect(375, 230, 5, 5, WHITE);
  tft.fillRect(390, 230, 5, 5, WHITE);
  tft.fillRect(375, 235, 5, 5, WHITE);
  tft.fillRect(390, 235, 5, 5, WHITE);
  tft.fillRect(375, 240, 5, 5, WHITE);
  tft.fillRect(390, 240, 5, 5, WHITE);
  tft.fillRect(375, 245, 5, 5, WHITE);
  tft.fillRect(390, 245, 5, 5, WHITE);
  tft.fillRect(385, 245, 5, 5, WHITE);
  tft.fillRect(375, 250, 5, 5, WHITE);
  tft.fillRect(390, 250, 5, 5, WHITE);
  tft.fillRect(375, 255, 5, 5, WHITE);
  tft.fillRect(390, 255, 5, 5, WHITE);
  tft.fillRect(375, 260, 5, 5, WHITE);
  tft.fillRect(390, 260, 5, 5, WHITE);
  tft.fillRect(385, 260, 5, 5, WHITE);
  tft.fillRect(375, 265, 5, 5, WHITE);
  tft.fillRect(390, 265, 5, 5, WHITE);
  tft.fillRect(375, 270, 5, 5, WHITE);
  tft.fillRect(390, 270, 5, 5, WHITE);
  tft.fillRect(375, 275, 5, 5, WHITE);
  tft.fillRect(390, 275, 5, 5, WHITE);
  tft.fillRect(385, 275, 5, 5, WHITE);
  tft.fillRect(370, 280, 5, 5, WHITE);
  tft.fillRect(395, 280, 5, 5, WHITE);
  tft.fillRect(365, 285, 5, 5, WHITE);
  tft.fillRect(400, 285, 5, 5, WHITE);
  tft.fillRect(365, 290, 5, 5, WHITE);
  tft.fillRect(400, 290, 5, 5, WHITE);
  tft.fillRect(365, 295, 5, 5, WHITE);
  tft.fillRect(400, 295, 5, 5, WHITE);
  tft.fillRect(370, 300, 5, 5, WHITE);
  tft.fillRect(395, 300, 5, 5, WHITE);
  tft.fillRect(375, 305, 5, 5, WHITE);
  tft.fillRect(390, 305, 5, 5, WHITE);
  tft.fillRect(380, 305, 5, 5, WHITE);
  tft.fillRect(385, 305, 5, 5, WHITE);
  tft.fillRect(380, 235, 10, 10, BLACK);
  tft.fillRect(380, 245, 5, 5, BLACK);
  tft.fillRect(380, 250, 10, 5, BLACK);
  tft.fillRect(380, 255, 10, 5, RED);
  tft.fillRect(380, 260, 5, 5, RED);
  tft.fillRect(380, 265, 10, 5, RED);
  tft.fillRect(380, 270, 10, 5, RED);
  tft.fillRect(380, 275, 5, 5, RED);
  tft.fillRect(375, 280, 20, 5, RED);
  tft.fillRect(370, 285, 30, 15, RED);
  tft.fillRect(375, 300, 20, 5, RED);
}
void TempMaggiore27() {
  {
    tft.fillRect(380, 225, 5, 5, WHITE);
    tft.fillRect(385, 225, 5, 5, WHITE);
    tft.fillRect(375, 230, 5, 5, WHITE);
    tft.fillRect(390, 230, 5, 5, WHITE);
    tft.fillRect(375, 235, 5, 5, WHITE);
    tft.fillRect(390, 235, 5, 5, WHITE);
    tft.fillRect(375, 240, 5, 5, WHITE);
    tft.fillRect(390, 240, 5, 5, WHITE);
    tft.fillRect(375, 245, 5, 5, WHITE);
    tft.fillRect(390, 245, 5, 5, WHITE);
    tft.fillRect(385, 245, 5, 5, WHITE);
    tft.fillRect(375, 250, 5, 5, WHITE);
    tft.fillRect(390, 250, 5, 5, WHITE);
    tft.fillRect(375, 255, 5, 5, WHITE);
    tft.fillRect(390, 255, 5, 5, WHITE);
    tft.fillRect(375, 260, 5, 5, WHITE);
    tft.fillRect(390, 260, 5, 5, WHITE);
    tft.fillRect(385, 260, 5, 5, WHITE);
    tft.fillRect(375, 265, 5, 5, WHITE);
    tft.fillRect(390, 265, 5, 5, WHITE);
    tft.fillRect(375, 270, 5, 5, WHITE);
    tft.fillRect(390, 270, 5, 5, WHITE);
    tft.fillRect(375, 275, 5, 5, WHITE);
    tft.fillRect(390, 275, 5, 5, WHITE);
    tft.fillRect(385, 275, 5, 5, WHITE);
    tft.fillRect(370, 280, 5, 5, WHITE);
    tft.fillRect(395, 280, 5, 5, WHITE);
    tft.fillRect(365, 285, 5, 5, WHITE);
    tft.fillRect(400, 285, 5, 5, WHITE);
    tft.fillRect(365, 290, 5, 5, WHITE);
    tft.fillRect(400, 290, 5, 5, WHITE);
    tft.fillRect(365, 295, 5, 5, WHITE);
    tft.fillRect(400, 295, 5, 5, WHITE);
    tft.fillRect(370, 300, 5, 5, WHITE);
    tft.fillRect(395, 300, 5, 5, WHITE);
    tft.fillRect(375, 305, 5, 5, WHITE);
    tft.fillRect(390, 305, 5, 5, WHITE);
    tft.fillRect(380, 305, 5, 5, WHITE);
    tft.fillRect(385, 305, 5, 5, WHITE);

    tft.fillRect(380, 235, 10, 10, RED);
    tft.fillRect(380, 245, 5, 5, RED);
    tft.fillRect(380, 250, 10, 5, RED);
    tft.fillRect(380, 255, 10, 5, RED);
    tft.fillRect(380, 260, 5, 5, RED);
    tft.fillRect(380, 265, 10, 5, RED);
    tft.fillRect(380, 270, 10, 5, RED);
    tft.fillRect(380, 275, 5, 5, RED);
    tft.fillRect(375, 280, 20, 5, RED);
    tft.fillRect(370, 285, 30, 15, RED);
    tft.fillRect(375, 300, 20, 5, RED);
  }
}
void umidita(int h) {
  tft.setCursor(50, 110);
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.println("Umidita'");
  tft.setCursor(80, 160);
  tft.setTextColor(YELLOW, BLACK);
  tft.setTextSize(5);
  tft.println(h);
  tft.setCursor(160, 160);
  tft.setTextColor(YELLOW);
  tft.setTextSize(5);
  tft.println("%");
}
void temperatura(int temp) {

  tft.setCursor(270, 110);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.println("Temperatura");
  tft.setCursor(300, 160);
  tft.setTextColor(BLUE, BLACK);
  tft.setTextSize(5);
  tft.println(temp);
  tft.setCursor(365, 180);
  tft.setTextColor(BLUE);
  tft.setTextSize(2);
  tft.println("Celsius");
}
