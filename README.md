# Projectile Simulator

A professional command-line projectile motion simulator written in **C**. This tool allows users to simulate the trajectory of a projectile by providing initial physical parameters and comparing step-by-step results with analytical kinematics formulas.

Developed as a personal project to practice C programming, input validation, and classical mechanics fundamentals during my Computer Science degree.

## Features
- **Real-time Trajectory Table:** Displays time, distance, and height at custom intervals.
- **Input Validation:** Prevents invalid physical parameters (e.g., negative gravity or speeds).
- **UTF-8 Support:** Configured for Windows terminals to display symbols like `²` and `º` correctly.
- **Analytical Summary:** Provides precise results for Range, Total Time, and Peak Height.

## Physics Formulas
The simulator implements the following equations of motion:

| Variable | Formula |
| :--- | :--- |
| **Horizontal Position** | $x(t) = v_0 \cdot \cos(\theta) \cdot t$ |
| **Vertical Position** | $y(t) = v_0 \cdot \sin(\theta) \cdot t - \frac{1}{2} \cdot g \cdot t^2$ |
| **Total Air Time** | $T = \frac{2 \cdot v_0 \cdot \sin(\theta)}{g}$ |
| **Maximum Range** | $R = v_0 \cdot \cos(\theta) \cdot T$ |
| **Peak Height** | $H = \frac{(v_0 \cdot \sin(\theta))^2}{2g}$ |

## Build & Run
To compile and run this project, you need a C compiler (like GCC).

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/projectile-simulator-c.git](https://github.com/your-username/projectile-simulator-c.git)


## EXAMPLE OUTPUT

```
--- Projectile Simulator Configuration ---
Launch Angle (deg): 45
Initial Speed (m/s): 20
Gravity (m/s²): 9.8
Time Step (s): 0.2

Time (s)   | Distance (m) | Height (m)
--------------------------------------------
 0.00      | 0.00         | 0.00
 0.20      | 2.83         | 2.63
 0.40      | 5.66         | 5.07
 ...

-------------ANALYTICAL RESULTS-------------
Total range: 40.82 (m)
Total time:  2.89 (s)
Max height:  10.20 (m)