# IFTTT Dash Button
Push a button, do a GET Request. Save battery to last ages.
More documentation on [Instructables](https://www.instructables.com/id/Tiny-ESP8266-Dash-Button-Re-Configurable/).

- [ESP-12E Weather Station (in development)](#esp-12e-weather-station-in-development)
    - [Planned Features (And Progress)](#planned-features-and-progress)
        - [GET Requests](#get-requests)
            - [Triggering Actions](#triggering-actions)
            - [Monitoring Battery (in progress)](#monitoring-battery-in-progress)
        - [Power Saving](#power-saving)
        - [OTA / WebUpdate (in progress)](#ota-webupdate-in-progress)
    - [Useful Links and References](#useful-links-and-references)

## Features
 - [X] GET Requests
    - [X] Trigger Action
    - [X] Monitor Battery
 - [X] Power Saving
 - [X] Reconfigurable

## About
Inspired by Bitluni's Lab. This is a tiny dashbutton. That connects to IFTTT, and saves battery. The code has been extended to make it easy to use and universally configurable without the need for re-programming. Just flash the `.bin` file from the releases page and the SPIFFS data, enter configuration mode, set it up and you are ready to go.
![Built Button](https://luigi-pizzolito.github.io/Gangster45671.github.io/IFTTT-Dash-Button/pictures/20180220_163702.jpg)

### GET Requests
When the button is pushed a GET request is made to a webpage.
#### Triggering Actions
Depending on the webpage, many different actions can be triggered by the button. I suggest hooking it up to the IFTTT Maker WebHooks.
#### Monitoring Battery
When a request is made, if the setting is set, the button will also pass on the battery voltage with your web request. This way you can monitor the battery's charge. The server will recieve:
 > yoururl.com/yourrequest/_?VCC_Param.=_**VCC_Voltage**

### Power Saving
To keep the button down to a small size, a small battery needs to be used. To maintain a decent battery life, the ESP is almost always in deep-sleep mode. Pressing the button resets the ESP. The ESP reboots, makes a GET request and goes back to deep-sleep.

### Configuration
You dont need to take apart your button to re-program the url or action. If you connect `GPIO_03[RX]` to `GND` during startup the button will enter configuration mode. Then you can
1. Connect to 'ESP_Button' WiFi Access Point, with the password 'wifibutton'
2. Visit http://192.168.4.1 to open the configuration page
3. After setting your values, click on the 'Save' button then the 'Restart'
![Configuration Interface](https://luigi-pizzolito.github.io/Gangster45671.github.io/IFTTT-Dash-Button/pictures/Config.png)

## Useful Links and References
- Similliar Projects
    - [Bitluni's DashButton] (https://github.com/bitluni/wifiButton)
- ESP Info
    - Pinouts
        - [ESP-12 Pinout](https://esp8266.github.io/Arduino/versions/2.0.0/doc/esp12.png)
        - [ESP-01 Pinout](https://os.mbed.com/media/uploads/sschocke/esp8266-pinout_etch_copper_top.png)
    - General Guides
        - [Sparkfun Guide](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/using-the-arduino-addon)
        - [Excellent Beginner's Guide](https://github.com/tttapa/ESP8266)
- GitHub Markdown Info
    - [Formatting and Syntax](https://help.github.com/articles/basic-writing-and-formatting-syntax/)
    - [Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet/)
