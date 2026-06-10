 
🚦 Traffic Density Control System

An intelligent Arduino-based traffic management system that dynamically controls traffic signals using ultrasonic sensors to detect vehicle density on two roads. The system automatically prioritizes the road with higher traffic volume, helping reduce congestion and improve traffic flow efficiency.

📌 Project Overview

Traditional traffic lights operate on fixed time intervals regardless of traffic conditions, often causing unnecessary delays. This project implements a smart traffic control mechanism where ultrasonic sensors monitor vehicle presence on each road and adjust signal priorities accordingly.

When a vehicle queue is detected closer to one sensor than the other, that road is given the green signal while the opposite road remains red. The system continuously monitors traffic density and updates signal control in real time.

⚙️ Features
🚦 Automated traffic light control
📡 Real-time vehicle density detection using ultrasonic sensors
🔄 Dynamic signal switching based on traffic conditions
🟢 Priority-based green light allocation
🟡 Safe yellow-light transition before signal changes
📟 Serial monitor output for traffic data visualization
🛠️ Designed and simulated in Tinkercad

🧩 Components Used
Arduino Uno
2 × HC-SR04 Ultrasonic Sensors
6 × LEDs (Red, Yellow, Green for each road)
Resistors
Breadboard
Jumper Wires

🏗️ Working Principle
Two ultrasonic sensors continuously measure vehicle distance on both roads.
The Arduino compares the measured distances.
The road with the shorter distance (indicating higher traffic density) receives priority.
A yellow-light transition occurs before switching signals.
The prioritized road gets a green signal while the other remains red.
After the cycle completes, the system re-evaluates traffic conditions and repeats the process.

💡 Applications
Smart City Infrastructure
Intelligent Transportation Systems (ITS)
Traffic Congestion Management
Educational Arduino and IoT Projects
Traffic Signal Automation Research

🛠️ Technologies Used
Arduino IDE
Embedded C/C++
Tinkercad Circuit Simulation
HC-SR04 Ultrasonic Sensing

👨‍💻 Author
Md Atif Absar
Computer Science & Engineering Student at Khulna University of Engineering & Technology
Aspiring Software Engineer | Astronomy Enthusiast | Open-Source Developer
