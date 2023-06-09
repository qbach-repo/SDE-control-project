# Project Setup 
![CARLA-setup](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/c7e156c5-fc96-45d8-b7d5-a822161d106c)

# Step 1: Build the PID controller object
Refer to the code in pid_controller.h and pid_controller.cpp

# Step 2: PID controller for throttle:
Refer to the code and comments in main.cpp

# Step 3: PID controller for steer:
Refer to the code and comments in main.cpp

# Step 4: Evaluate the PID efficiency
## Experiment 1 - Result
![Figure_1 1](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/4d94c1ad-697c-43eb-912b-6da7cc568270)
![Figure_1 2](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/42228d21-c64c-446e-a60a-6b3fc57d2b91)

- From the experiment 1 results, I can see the steering and the throttle can be aggresive. Therefore, I reduce the steering and the throttle control by reducing the coefficients.
- The effect from steering too aggressive is the car went off to the side
![Screen Shot 2023-06-08 at 7 41 10 PM](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/34e50f8b-5d17-4eb4-a140-3681af4cfab1)

## Experiment 2 - Result
![Figure_2 1](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/6db8ac1e-e5b8-4a1a-86c0-5c49cfa0ec0f)
![Figure_2 2](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/2054b109-7a5e-4f31-9036-cb6462c9e07a)

- Getting to the experiment 2 the car has more stable steering and the throttle is less aggressive resulting in less braking
- However, these coefficients still did not get the car to avoid the obstacle 
![Screen Shot 2023-06-08 at 4 49 37 PM](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/91d3c02e-eec8-4b43-bf73-7411621f7516)


## Experiment 3 - Result 
![Figure_3 1](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/7a9a2868-a80d-4b0a-b46b-d1ab5d6b7e07)
![Figure_3 2](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/eccf0b7c-298e-4a2f-9232-90901478bc96)

- After a couple of trials and errors I have got to the coefficients that resulted in the car being able to avoid the first obstacle 
- And the car goes a lot smoother now with small coefficients; this can be seen in the brake plot which remains flat. 

![Screen Shot 2023-06-08 at 8 35 19 PM](https://github.com/qbach-repo/SDE-PID-Controller/assets/58492405/f783f0b1-ac8a-4541-9e0a-6a84249ed3fe)

