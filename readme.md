# Smart Coal Mine Safety Monitoring System (IIoT)

## Overview

This project is an Industrial Internet of Things (IIoT) based system designed to monitor safety conditions in coal mines. It continuously tracks environmental and structural parameters and detects hazardous situations in real time.

## Objective

To improve safety in coal mines by monitoring critical parameters such as temperature, gas levels, vibration, and structural tilt, and triggering alerts when unsafe conditions are detected.

## Components Used

* Arduino Uno
* TMP36 Temperature Sensor
* Gas Sensor (MQ series or simulated input)
* Vibration Sensor
* Tilt Sensor
* LEDs (Red and Green)
* Resistors and Breadboard

## Working Principle

The system reads data from multiple sensors connected to the Arduino. Each parameter is compared against predefined threshold values. If any parameter exceeds safe limits, the system identifies the condition as dangerous and triggers an alert.

## Alert Conditions

* Temperature greater than 45°C
* Gas level greater than 700
* Vibration detected
* Tilt detected

If any of the above conditions are met, the system activates a danger alert. Otherwise, it indicates a safe condition.

## Output

### Circuit Simulation

![Circuit](output.png)

### Serial Monitor Output

```
------ SENSOR DATA ------
Temperature: 32.5 °C
Gas Level: 400
Vibration: NORMAL
Stress (Tilt): STABLE
STATUS: SAFE
------------------------

------ SENSOR DATA ------
Temperature: 48.2 °C
Gas Level: 800
Vibration: DETECTED
Stress (Tilt): TILTED
STATUS: DANGER
------------------------
```

## Result

The system successfully monitors environmental conditions and differentiates between safe and hazardous states in real time.

## Future Scope

* Integration with cloud platforms such as ThingSpeak
* Real-time monitoring dashboard
* Mobile or SMS alerts for miners
* AI-based predictive analysis for early hazard detection

## Author
Bhavika Reddy
Janagam Anuhya 
Medha Bonu
