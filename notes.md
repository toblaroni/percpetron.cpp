# Perceptron
### What is it?
- Simplest artificial Artificial neural network architectures. 
- Single layer of feedforward neural net.
- Consists of a single layer of input nodes that are fully connected to a layer of output nodes.
- It can learn the linearly seperable patterns.
- It uses artificial neurons known as threshold logic units (TLU). 

### What is supervised learning?
Where you have labeled examples which you use to tweak the network based on its predictions.

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
    z = w_1x_1 + w_1x_2 + ... + w_nx_n = XTW  (TW is the transpose of W)
```
The step function compares this weighted sum to the threshold, which outputs 1 if the input is larger than a threshold value and 0 otherwise. 
The most common step function is Heaviside step function:
```
             0  if z < Threshold
    h(z) = {
             1  if z > Threshold
```
A perceptron has a single layer of threshold log units where each TLU is connected to all outputs. 
When all neurons are connected to every neuron of the previous layer, it is known as a fully connected layer or dense layer.
The output of the fully connected layer is:
```
    fW,b(X) = h(XW+b)
```
Where X is the input, W is the weight for each inputs neurons and b is the bias and h is the step function.

During training, the perceptron's weights are adjusted to minimize the difference between the predicted output and the actual output. Usually the delta rule or the perceptron learning rule are used for this.

### [Example](https://riptutorial.com/machine-learning/example/22617/what-exactly-is-a-perceptron-)
We want to classify whether an object is a bike or a car. Let's say that we want to select 2 features - the height and teh width of the object. 
In that case x = [x1, x2] where x1 is the height and x2 is the width.

Once we have this input vector x, we want to multiplly each element in that vector with a weight. Usually the higher the value of the weight the more important the feature is. For example if we were using colour as a feature and we have a red bike and a red car, the perceptron would set colour at a very low weight.

Now that we have multiplied the vectors x and w and got back a vector, we need to sum the elements of this vector. A smart way of doing this is multiplying x by wT where wT is the transpose of w. This leaves us with a 1x1 vector (single value) which is equal to 
`x1*w1 + x2*w2 + ... + xn*wn`. 
After that we have our prediction. This prediction will most likely not be a simple 1 or -1 to be able to classify a new sample. So what we do is if our prediction is bigger than 0 we say our sample belongs to class 1, otherwise if it's smaller than zero we say that the sample belongs to class -1. This is called the step function.

In order to get the right weights we need to train our model. The weights can be adjusted by the following equation:
```
    delta(w) = eta * (y - prediction) * x(i)
```
Where x(i) is our feature (x1 for weight 1, x2 for w2 and so on...).
We also have eta. eta is the learning rate. You can imagine the learning rate as how big we want the change of the weights to be. A good rate results in a fast learning algorithm. To low of an eta can mean the algorithm takes too long to converge, to high and the algorithm may never converge.

The first input is a constant (1) and is multiplied by w0 (See the image in the link ^^^). This is the bias - it's essential to get a good prediction.
To update the weight of the bias we use the same equaton but we don't multiply it by the input (since it's 1):
```
    delta(w) = eta * (y - prediction)
```

That is the basic idea of how a perceptron works.

