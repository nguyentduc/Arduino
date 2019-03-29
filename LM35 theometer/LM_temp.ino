// Thermalmeter using LM35DZ( 0 to 100 degree C) sensor to display temperture in Serial monitor.
#include <DS3231.h>
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
const int inPin =0;   //analog pin

void setup() {
  Serial.begin(9600);

  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(2, 27, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(25, 11, 2017);   // Set the date to January 1st, 2014
}

void loop() {
  int value = analogRead(inPin);                //value from analog pin
  
  //Calculate the voltage in mV from anaglog pin then convert to dregree C
  float millivolts = (value/1024.0)*5000;       // 10bit ADC so 1024 sterp from 0 to 5V.
  float celsius = millivolts/10;                // 10mV/degree

  //Display on Serial monitor
  Serial.print(value); 
  Serial.print(" > ");
  Serial.print(celsius);
  Serial.print(" degree Celcius \n");
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  delay(5000);                                  //refresh every 1 second
}
