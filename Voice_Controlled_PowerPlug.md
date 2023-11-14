## Non IoT Voice Controlled Power Plug with Syntiant NDP120 (Nicla Voice)
by Jallson Suryo

![Image00.png](https://www.dropbox.com/scl/fi/vyurj76z3jbmtn7fu7juc/Image00.png?rlkey=7h0joapk2otkzz5hncaqk3ivv&dl=0)

Project link: https://studio.edgeimpulse.com/public/297564/latest

Demo video link: https://youtu.be/9PRjhA38jBE

### Problem:

Can you imagine Alexa without the Cloud?
Currently, adding voice means adding an internet connection and it means extra expense, privacy & security concern, and you have to install an app or access from the web for everything in your home. Another problem is the time delay between a voice command being given and then sent to the server and back to the device for execution, so it feels a bit annoying to use.

### Our Solution:

A power-plug which can be controlled using voice commands with no connection to the internet. By using an ML model embedded to the micro-controller which has previously been trained to recognize several commands for control, which are then passed to relays which will turn the power on/off at each socket according to command instantly. Practicality, privacy concern and cost-effectiveness are the goals of this Non IoT Voice Controlled Power Plug project.

### Description:

This project takes advantage of Audio Syntiant processing block that extracts time and frequency features from a signal specific to Syntiant NDP120 chip in Nicla Voice. The NDP120 is ideal for always-on low-power speech recognition applications with the “find posterior parameters” feature which will only react to the specifics keywords.

Devices with those embedded ML model will accept voice commands but won’t need a WIFI or Bluetooth connection. Which means you could directly telling the lamp, aircon or TV to turn on/off without Alexa or Siri or any digital assistant speaker/hub.

This project will use some relays and power-strip that are connected to various appliances such as lamp, fan, TV, etc. A Nicla Voice with ML embedded which has been trained to recognize various keywords like: one, two, three, four, on, and off is the center of the decision process. From Nicla Voice we use the I2C protocol which is connected to the Arduino pro-micro to carry out voice commands from Nicla Voice and forwarded to the relays which control power sockets.

![Image01.png](https://www.dropbox.com/scl/fi/kx4007qizhfh6b7g60h46/Image01.png?rlkey=dgnbl6ku4ynnfc4dilpgevrwx&dl=0)

#### Hardware Component:

- Arduino Nicla Voice (with Syntiant NDP120)
- Any micro-controller/Arduino (I use Pro Micro)
- 5V Relay (4pcs)
- Breadboard
- Cable jumper
- Cable for 110/220V
- Powerstrip (4 sockets)

![Image02.png](https://www.dropbox.com/scl/fi/qc2dalm102emjhuzu0f0d/Image02.png?rlkey=3ttjo0qimi49o7p241kd4f7ja&dl=0)


#### Software & Online Services:

- Edge Impulse Studio (Enterprise account for more than 4 hrs data)
- Arduino IDE
- Terminal

### Steps:

#### 1. Upload or Collect Audio Data

Before we start, we need to install the Arduino CLI and Edge Impulse tooling on our computer. You can follow this guide -> https://docs.edgeimpulse.com/docs/development-platforms/officially-supported-mcu-targets/arduino-nicla-voice to get everything installed.
Open studio.edgeimpulse.com in a browser, and sign in, or create a new account if you do not have one. Click on New project, then in Data acquisition, click on the Upload Data icon for uploading .wav files (e.g. from Kaggle, Google Speech Commands Dataset, etc.). Other methods to collect data are from devices such as a connected smartphone with QR code link, or a connected Nicla Voice with Edge Impulse audio firmware flashed to it. For ease of labelling, when collecting or uploading data, fill in the name according to the desired label, for example one, two, three, on, off, or zzz for words or sound that can be ignored.
PS: With over 4 hours of audio data sets, multiple classes and higher performance settings to build model, this project uses an Enterprise account for more capable and faster results.

![Image03.png](https://www.dropbox.com/scl/fi/amfkqd3jho1o3y6mu79yd/Image03.png?rlkey=ad5i27b30jz46i27he0sfpov7&dl=0)
![Image04.png](https://www.dropbox.com/scl/fi/2qmcaslxe84lb5nly5m6c/Image04.png?rlkey=42zuopkuhgh545ccu7eu6il3k&dl=0)


#### 2. Split and Balancing

Click on a data sample that was collected, then click on the 3 dots to open the menu, and finally choose Split sample. Set the segment length to 1000 ms (1 second), or add segments manually, then click Split. Repeat this process until all samples are labelled in 1 second intervals. Make sure the comparison between one, two, three, four, on, off and unknown data is quite balanced, and the ratio between training and test data is around 80/20.

![Image05.png](https://www.dropbox.com/scl/fi/6t1py5wtytwyiztc7c0jo/Image05.png?rlkey=1py2qgu4c090p4jipx568qzp1&dl=0)
![Image06.png](https://www.dropbox.com/scl/fi/cd2xgyraj5qr724eiw74j/Image06.png?rlkey=pnos5lcri2hculnuw4wvjga78&dl=0)


#### 3. Train and build the model (Syntiant)

Choose Create Impulse, set Window size to 968ms, then add an Audio (Syntiant) Processing block, and choose Classifier for the Learning block, then Save Impulse. In the Syntiant parameters, choose log-bin (NDP120/200) then click Save. Set the training to around 50 cycles with 0.0005 Learning rate, and choose Dense Network with Dropout rate around 0.5, then click Start train. It will take a short while, but you can see the progress of the training on the right. If the results show a figure of around 80% accuracy upon completion, then we can most likely proceed to the next stage.
Now we can test the model in Live classification, or choose Model testing to test with the data that was set aside earlier (the 80/20 split), and click Classify all. If the result is quite good -- around 80% accuracy, then we can move to the next step -- Deployment.

![Image07.png](https://www.dropbox.com/scl/fi/zeadwuz3fq7f2us7uxpmr/Image07.png?rlkey=4llzf98nfekxl8iebqbifpf4c&dl=0)
![Image08.png](https://www.dropbox.com/scl/fi/rb3fgee6dcg5uc6p878oy/Image08.png?rlkey=hzf1jx9szxj9b9c2bpjmiqex9&dl=0)
![Image09.png](https://www.dropbox.com/scl/fi/jycihba5kzwa0h7nm00de/Image09.png?rlkey=wm62iubhxlmefwcfq51pqx7xz&dl=0)
![Image10.png](https://www.dropbox.com/scl/fi/vs9n7i4efhnurxfc1kava/Image10.png?rlkey=8tsco80j4h8zjukzl697nehd2&dl=0)
![Image11.png](https://www.dropbox.com/scl/fi/ljm3noi9cj2f65h9f76rv/Image11.png?rlkey=ntb4xsrz7ibhvw7qg6ixldgtr&dl=0)

#### 4. Deploy to Nicla Voice

For a Syntiant NDP device like the Nicla Voice, we can configure the posterior parameters (in this case tick all labels except zzz). To run your Impulse locally on the Arduino Nicla Voice, you should type and choose Nicla Voice in the Deployment tab, then click Build. The binary firmware will start building and automatically download to your computer once it is complete, and instruction how to flash video will pop-up. Flash this firmware to Nicla Voice as instructed. Now you can run this model in Terminal for live classification.

![Image12.png](https://www.dropbox.com/scl/fi/iak3dyy8iy52lx3jt7ept/Image12.png?rlkey=1nn3j2vmhb1ctsews4l41yax6&dl=0)
![Image13.png](https://www.dropbox.com/scl/fi/vrz1fycckztks5y5ddn9w/Image13.png?rlkey=aey7gaa6qf73ubkd893o7bsa1&dl=0)
![Image14.png](https://www.dropbox.com/scl/fi/581le95n50xcbnomlf4ak/Image14.png?rlkey=uuemtb9psu8woql26p61b3lvc&dl=0)

#### 5. Upload the Arduino Code

Nicla Voice:
Upload this code https://github.com/Jallson/Voice_Controlled_PowerPlug/blob/main/relayvoice_niclavoice.ino to the Arduino Nicla Voice using the Arduino IDE. This code will override the existing code in the Nicla Voice’s MCU but not the model on the NDP120. The code basically sends a byte via I2C every time a keyword is detected, the value of the byte will depend on the keyword detected.
Pro Micro:
Upload this code https://github.com/Jallson/Voice_Controlled_PowerPlug/blob/main/relayvoice_promicro.ino to the Pro Micro using the Arduino IDE. The code receives the incoming byte via I2C and will switch on or off the relay based on the values of the data received from the Nicla Voice.

![Image15.png](https://www.dropbox.com/scl/fi/mv8uyfemg8dd7qiy7ahw6/Image15.png?rlkey=5zligbtsxbpy5i6nzeo9a23zr&dl=0)

### Conclusion:

Finally we succeeded in making this Non IoT Voice Controlled Power-plug idea a reality and implemented in home appliances setting. I believe in the future this kind of non-IoT smart home system will be widely implemented, it could be built-in in every home appliances with specific keywords. So that concerns about privacy, security, as well as practicality and energy efficiency can be achieved for a more sustainable future.







