# Perceptron
### What is it?
- Simplest artificial Artificial neural network architectures. 
- Single layer of feedforward neural net.
- Consists of a single layer of input nodes that are fully connected to a layer of output nodes.
- It can learn the linearly seperable patterns.
- It uses artificial neurons known as threshold logic units (TLU). 

### Types
- Single layer Perceptron - Can only learn linearly seperable patterns. Effective for tasks where the data can be divided into distinct categories.
- Multilayer Perceptrons - Can do more complex stuff

### Basic Concepts
#### Input Features
Takes multiple input features, each input feature represents a characterisitc or attribute of the data.

#### Weights
Each input feature is associated with a weight, determining the significance of each input feature in influencing the output. When training, the weights are adjusted to learn optimal values.

#### Summation Function
Calculates the weighted sum of its inputs using the summation function.

#### Activation Function
The weighted sum is then passed through an activation function. Perceptron uses Heaviside step function functions. These take the summed values as input and compare with the threshold and provide the output as 0 or 1.

#### Output
The output of the perceptron is determined by the activation function's result. 

#### Bias 
A bias term is often included in the model. It allows the model to make adjustments that are independent of the input. It's an additional param that is learned during training.

#### Learning algorithm (Weight Update Rule)
When training, the perceptron learns by adjusting its weights and bias based on a learning algorithm. A common approach is the perceptron learning algorithm, which updates the weights based on the difference between the predicted output and the true output.

### How the hell does it work?
A weight is assigned to each input of the perceptron (significance of the input to the output). The perceptron's output is a weighted sum of the inputs that have been run through an activation function to decide whether or not the perceptron will fire. 
It computes the weighted sum of its inputs as:
```
z = w_1x_1 + w_1x_2 + ... + w_nx_n = X^TW
```
