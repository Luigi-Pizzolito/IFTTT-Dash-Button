# IFTTT Dash Button (in development)
Push a button, do a GET Request. Save battery to last ages.

- [IFTTT Dash Button](#ifttt-dash-button)
    - [Planned Features (And Progress)](#planned-features-and-progress)
        - [GET Requests](#get-requests)
            - [Triggering Actions](#triggering-actions)
            - [Monitoring Battery (in progress)](#monitoring-battery-in-progress)
        - [Power Saving](#power-saving)
        - [OTA / WebUpdate (in progress)](#ota-webupdate-in-progress)
    - [Useful Links and References](#useful-links-and-references)

## Planned Features (And Progress)
 - [X] GET Requests
    - [X] Trigger Action
    - [ ] Monitor Battery
 - [X] Power Saving
 - [ ] OTA / WebUpdate


### GET Requests
When the button is pushed a GET request is made to a webpage.
#### Triggering Actions
Depending on the webpage, many different actions can be triggered by the button. I suggest hooking it up to the IFTTT Maker WebHooks.
#### Monitoring Battery (in progress)
When a request is made, the button will also pass on the battery voltage. This way you can monitor the battery's charge.

### Power Saving
To keep the button down to a small size, a small battery needs to be used. To maintain a decent battery life, the ESP is almost always in deep-sleep mode. Pressing the button resets the ESP. The ESP reboots, makes a GET request and goes back to deep-sleep.

### OTA / WebUpdate (in progress)
By implementing Over-The-Air programming, you wont need to take apart your button to re-program the url or action.

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