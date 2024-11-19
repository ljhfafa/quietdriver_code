# QuietDriver Project

## Overview

The **QuietDriver Controller** is an enhancement of the traditional fixed time-gap model, aiming to provide smoother and more responsive vehicle-following dynamics in simulations. Unlike basic models, our controller considers not only the relative speed between the lead and ego vehicles but also their relative acceleration. This results in smoother speed adjustments for the ego car and stronger acceleration responses during significant changes in the lead car’s speed.

## Key Features

- **Smooth Speed Transitions**: The ego car maintains a stable speed profile, even with fluctuations in the lead car's velocity.
- **Responsive Acceleration**: During rapid lead car accelerations, the ego car quickly adjusts to maintain safe following distances.
- **Enhanced Safety**: In scenarios with large speed differences, the controller reduces abrupt changes in the ego car's speed, creating a safer and more comfortable driving experience.
- **Phantom Jam Mitigation**: Our controller has preliminarily solved the Phantom Jam problem, reducing the occurrence of traffic jams without an obvious cause.

## Behavior Overview

In simulations with the QuietDriver Controller:

- **Stable Following**: When the lead car's speed fluctuates around a stable value, the ego car’s speed remains smooth and steady, avoiding drastic changes.
- **Quick Response to Acceleration**: The ego car's acceleration increases rapidly when the lead car starts moving from a stationary state.
- **Limitations at Low Speeds**: At lower speeds, the vehicles may maintain a close distance due to the fixed time-gap model approach. We are currently working on an improved version to address this limitation.
