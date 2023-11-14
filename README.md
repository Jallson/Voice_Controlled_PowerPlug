# Voice_Controlled_PowerPlug
A power-strip which can be controlled using voice commands with no connection to the internet. Practicality, privacy concern and cost-effectiveness are the goals of this Non IoT Voice Controlled Power Plug project.
## Introduction:
This project takes advantage of Audio Syntiant processing block that extracts time and frequency features from a signal specific to Syntiant NDP120 chip in Nicla Voice. The NDP120 is ideal for always-on low-power speech recognition applications with the “find posterior parameters” feature which will only react to the specifics keywords.

Devices with those embedded ML model will accept voice commands but won’t need a WIFI or Bluetooth connection. Which means you could directly telling the lamp, aircon or TV to turn on/off without Alexa or Siri or any digital assistant speaker/hub.

This project will use some relays and power-strip that are connected to various appliances such as lamp, fan, TV, etc. A Nicla Voice with ML embedded which has been trained to recognize various keywords like: one, two, three, four, on, and off is the center of the decision process. From Nicla Voice we use the I2C protocol which is connected to the Arduino pro-micro to carry out voice commands from Nicla Voice and forwarded to the relays which control power sockets.
