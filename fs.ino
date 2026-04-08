#include <DHT.h>
#define DHTPIN 2      // DHT11接D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int fanPin = 3;       // 风扇控制引脚（继电器或PWM）
int threshold = 28;   // 温度阈值（可改）

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(fanPin, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();  // 读温度
  
  if (isnan(temp)) {
    Serial.println("传感器读取失败！");
  } else {
    Serial.print("当前温度: "); Serial.print(temp); Serial.println(" °C");
    
    if (temp > threshold) {
      digitalWrite(fanPin, HIGH);  // 打开风扇
      Serial.println("温度过高 → 风扇开启！");
    } else {
      digitalWrite(fanPin, LOW);   // 关闭风扇
    }
  }
  delay(2000);  // 2秒读一次
}