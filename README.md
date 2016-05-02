# ESP8266 Relay Control

This project is to control a simple 5v relay using ESP8266 over Azure IoT Hub (MQTT)

##Hardware Requirements

__ESP 8266__ - 01 http://tr.aliexpress.com/item/New-Upgraded-version-ESP-01-ESP8266-serial-WIFI-wireless-module-wireless-transceiver/32633226881.html?spm=2114.010208.3.10.BBbReL&ws_ab_test=searchweb201556_10,searchweb201602_2_10034_507_10032_10020_10017_10005_10006_10021_10022_10009_10008_10018_10019,searchweb201603_1&btsid=afe8dd0f-ba8a-4286-8460-d4a110ea4851

__5V RELAY__ -  http://tr.aliexpress.com/item/5V-One-1-Channel-Relay-Module-Board-Shield-For-PIC-AVR-DSP-ARM-MCU-For-Arduino/2038548096.html?spm=2114.49010208.4.50.pprbBO

##Connections
ESP-GND -> GND

ESP_VCC -> 3V3

ESP_CH_EN -> 3V3

ESP_GPIO_0 -> GND (only for programming)

ESP_GPIO_2 -> Relay's Input

ESP_RX -> USB_TO_TTL_TX

ESP_TX -> USB_TO_TTL_RX




RELAY_VCC -> 5V

RELAY_GND -> GND

RELAY_INPUT -> ESP_GPIO_2 


##Resources
http://www.e-consystems.com/blog/windowsce/?p=1630

