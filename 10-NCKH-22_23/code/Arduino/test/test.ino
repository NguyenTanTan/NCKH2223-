#include <ArduinoJson.h>
int count = 1;
void setup() { 
	Serial.begin(115200); 
} 
void loop() { 
	if (Serial.available()){
    String receivedJson = Serial.readStringUntil('\n');
    JsonDocument receivedDoc;
    DeserializationError error = deserializeJson(receivedDoc, receivedJson);
    if (error) {
      Serial.write(error.c_str());
      return;
    }
    const char* inp = receivedDoc["sensor"];
 
    if (strcmp(inp, "humidity") == 0){
      Serial.write(count);
      Serial.write("Hello from arduino!\n");
      count++;
    }
  }
} 
