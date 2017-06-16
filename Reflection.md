# Describe the effect each of the P, I, D components had in your implementation.

* The P is used for turning the wheels proportionally to the difference between the current position and the desired one
* The I is used for correcting bias and it is collected over time -
if the car is always biased to one direction, this part will countersteer in the opposite direction.
* The D is used for turning the wheels smoothly by using the difference between the current P and the previous one, e.g. how fast are we closing to
the desired position


# Describe how the final hyperparameters were chosen.

There is a twiddle implementation inside the code, but it takes a lot of time,
so actually the parameters were chosen manually, based on lectures.
