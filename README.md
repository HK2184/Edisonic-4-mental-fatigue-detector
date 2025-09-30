# Edisonic-4-mental-fatigue-detector
A smart Iot Sensing device used to detect mental fatigue


# 🧠 Mental Fatigue Detector – SmartCityX Hackathon (Intel 1D Track)

## 📌 Project Overview
The **Mental Fatigue Detector** is an **AIoT-based system** designed for the **SmartCityX Hackathon (Intel 1D Track)**.  
It monitors **head tilt posture (MPU6050)** and **ambient lighting (LM393 LDR)** using an **ESP32**, and runs a **Edge Impulse Classification NN moddel** locally to detect early signs of mental fatigue.  

When fatigue is detected, the system displays alerts on an OLED screen and can also push data to the cloud (Azure API ) for **real-time monitoring**.  
This project addresses **urban healthcare challenges** by helping students and professionals maintain focus and reduce fatigue-related health issues.  

---

## ⚙️ Hardware Components
- **ESP32 Development Board**  
- **MPU6050 Accelerometer + Gyroscope**  
- **LM393 LDR Module (3-pin)**  
- **0.96" OLED Display (SSD1306, I2C)**  
- Breadboard, jumper wires, USB cable  

### 🔌 Circuit Connections
| Component    | ESP32 Pin |
|--------------|-----------|
| MPU6050 VCC  | 3.3V      |
| MPU6050 GND  | GND       |
| MPU6050 SDA  | GPIO21    |
| MPU6050 SCL  | GPIO22    |
| LM393 VCC    | 3.3V      |
| LM393 GND    | GND       |
| LM393 DO     | GPIO32    |
| OLED VCC     | 3.3V      |
| OLED GND     | GND       |
| OLED SDA     | GPIO21    |
| OLED SCL     | GPIO22    |

---

## 💻 Software Stack
- **Arduino IDE / PlatformIO** (ESP32 code)  
- **Edge Impulse Classifier NN model** (model deployment)  
- **Azure Storage ** – optional cloud data import  
  

---

## 📂 Repository Structure


Mental-Fatigue-Detector/
│── hardware\_code/              # Arduino/ESP32 sketches
│   └── fatigue\_detector.ino
│── dataset/                    # Collected ESP32 sensor data
│   └── dataset.csv
│── model\_training/             # Jupyter notebooks for ML training
│   └── train\_model.ipynb
│── models/                     # Exported models
│   └── mental\_fatigue\_model.tflite
│   └── model\_data.h
│── web\_app/                    # React.js frontend (optional)
│── mobile\_app/                 # React Native mobile app (optional)
│── README.md                   # Project documentation





## 📊 Dataset Collection
- ESP32 logs **tilt angle (degrees)** + **light state (bright/dark)**.  
- Labels are added manually (0 = Normal`, `1 = Fatigue`).  



tilt,light,label
3.45,1,0
5.12,1,0
27.80,0,1
35.15,0,1



---

## 🧑‍💻 Model Training
1. Train a small **Neural Network** on collected dataset.  
2. Convert trained model → **TensorFlow Lite** (`.tflite`).  
3. Convert `.tflite` → **C array (`model_data.h`)**:
 bash
 xxd -i mental_fatigue_model.tflite > model_data.h


4. Upload to ESP32 sketch.

---

## 🚀 How to Run

### 🔹 ESP32 Hardware

1. Clone this repo:

   bash
   git clone https://github.com/<your-username>/Mental-Fatigue-Detector.git
  
2. Open Arduino IDE → Load `hardware_code/fatigue_detector.ino.
3. Install required libraries:

   * Adafruit_MPU6050
   * Adafruit_SSD1306
   * Adafruit_GFX
   * TensorFlowLite_ESP32
4. Upload code to ESP32.
5. Monitor output via OLED + Serial Monitor.

### 🔹 Model Training

1. Open model_training/train_model.ipynb in **Google Colab / Jupyter**.
2. Train model on dataset/dataset.csv.
3. Export model → deploy to ESP32.



## 👥 Team – Edisonic 4

* **A. Srijan Sivaram** – Team Lead
* **Harikrishna Iyer**
* **Jaison John Samuel**
* **M. S. Snendar**

---

## 📜 License

This project is open-source under the **MIT License**.


