# IOT PLANT WATERING SYSTEM with Google assistant integration using IFTTT

## Idea
I've seen people using smart watering systems to water their gardens remotely.But those systems were expensive to be shipped in india so i've decided to build my own.

### Components used
- NodeMCU ( ESP8266 )
- 4 Channel Relay
- A submersible water pump 

## Circuit Diagram

<p align="center">
  <img width="460" height="550" src=https://imgur.com/ShiGgmk.png">
</p>
     


## Resources/links

- [adafruit](https://io.adafruit.com)
- [if this then that](https://ifttt.com)
- [a relative link](https://github.com/openhomeautomation/adafruit-io-esp8266/blob/master/esp8266_sensor_module/esp8266_sensor_module.ino)
with help of that repository

## Modified code
[ Modified Source ](https://github.com/pacchukun/iot_plant_water/blob/master/Plantwatersketch.ino)


  
  
## Steps

### Setting up ADAFRUIT

Paste the code in editor and edit your SSID and WLAN password in the variables. Make an account in [adafruit](https://io.adafruit.com)
and get your **USERNAME** and **API KEY** from it and paste it.

Now open the Dashboard and follow::
<p align="center">
  <img width="460" height="300" src="https://i.imgur.com/Q6YlnEr.png">
</p>

<p align="center">
  <img width="460" height="300" src="https://i.imgur.com/umB3BhX.png">
</p>

<p align="center">
  <img width="460" height="300" src="https://imgur.com/HtbQwY4.png">
</p>
### Remember the names given as you have to replace them in code

<br>
                                     
<p align="center">
  <img width="460" height="300" src="https://imgur.com/uxqJawW.png">
</p>
     
### replace these in code - along with wherever needed.

<p align="center">
  <img width="460" height="500" src="https://imgur.com/BaqNGXQ.png">
</p>

### SETTING UP IFTTT Applet

> Make an account on [IFTTT](https://ifttt.com)
 
 Now click on **THIS** and select Google assistant
 
 <p align="center">
  <img width="460" height="300" src="https://imgur.com/l2dmqn3.png">
</p>

- Say a simple Phrase
> ** Hey google ** Start watering garden plants

- choose a response and click save

 Now click on **THEN** and select Adafruit

<p align="center">
  <img width="460" height="300" src=" https://imgur.com/4EFfvgj.png">
</p>

send data .. and click save

repeat this again to make the alert to stop the relay

## viola you got youself a working Google assistant controlled plant watering system  :tada: :tada: :tada:
