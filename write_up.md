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

## Experiment 4 - Result
![Figure_4 1](https://github.com/qbach-repo/SDE-control-project/assets/58492405/91517f11-f639-490c-8b06-668c79c7d62b)
![Figure_4 2](https://github.com/qbach-repo/SDE-control-project/assets/58492405/43b40bb9-f8dd-476a-a4ee-2ffb69147ffd)

## Experiment 5 - Result
![Figure_5 1](https://github.com/qbach-repo/SDE-control-project/assets/58492405/1b799c11-55ac-4f36-84dd-25167ad55910)
![Figure_5 2](https://github.com/qbach-repo/SDE-control-project/assets/58492405/85b22f04-179f-46ed-a014-41db3b9783f0)
![Screen Shot 2023-06-12 at 11 30 16 AM](https://github.com/qbach-repo/SDE-control-project/assets/58492405/73f4f949-8b30-463a-ada6-7cbfa8bb66d3)

## PID Effect
- P: the p term is the propotional term in the pid controller which would take the current error at delta t to influence the output of the controllers (throttle and steer in this case). As we can see in the plot of the steer output, the p term will contribute to the steer output whenever the error is large.
- I: the i term is the total error so far, the i term will come in to effect when the accumulate error increase too high; when the p and the d term control output are not enough to correct the control the i term will come into play as it would take a bigger effect when the accumulate error is large enough. 
- D: the d term is the rate of change of the error, in the case when we see that the car needs to make adjustment to the steering to avoid obstacles, the rate of change of the error will increase drastically and the d term will take effect. This can be seen in the plot of steering as the slope of the error becomes more stiff, the output of the steering will increase due to the d term. 

## The Best Parameters 
- Steer: pid_steer.Init(0.3, 0.01, 0.8, 1.2, -1.2);
- Throttle: pid_throttle.Init(0.13, 0.001,0.02, 1, -1);

## Elaborate on Critical Analysis of PID
 - How would you design a way to automatically tune the PID parameters? - automate tuning for the PID can be done by running the simulation multiple times and observe the error and output of the controllers. From these datapoint we can implement a regression to find the best parameters automatically.

- PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
  - Pros:
    + It's simply to implement
    + can replicate the controller for other agents not just cars
  - Cons:
    + Have to spend a long time to tune the parameters or implement a complicated tuning algorithm
    + If we change the vehicle we have to tune the parameters again since the configuration of steering or throttling are different based on the vehicle

