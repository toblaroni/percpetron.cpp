/*
    Tutorial: https://riptutorial.com/machine-learning/example/22618/implementing-a-perceptron-model-in-cplusplus
    
    Algorithm:
        1. Make a vector for the weights (don't forget the bias term)
        2. Keep adjusting the weights until we get 0 errors or a low error count
        3. Make predictions on unseen data
*/

#include <stdio.h>
#include "perceptron.h"

Perceptron::Perceptron(float eta, int epochs) {
   m_epochs = epochs;
   m_eta    = epochs;
}

// Step function
int Perceptron::predict(vector<float> X) {
   return netInput(X) > 0 ? 1 : -1;
}

float Perceptron::netInput(vector<float> X) {
   // Sum(Vector of weights * Input vector) + bias
   float probabilities = m_w[0]; // Add the bias
   for (int i = 0; i < X.size(); i++) {
      probabilities += X[i] * m_w[i+1]; // Counting from the second element since the bias was added first
   }

   return probabilities;
}

// Training function
void Perceptron::fit(vector< vector<float> > X, vector<float> y) {
   for (int i = 0; i < X[0].size() + 1; i++) {  // +1 for bias
      // Setting weights to 0
      // Making the vector the size of the vector the same as the number of features (X[0].size()) + 1 for bias
      m_w.push_back(0);
   }

   for (int i = 0; i < m_epochs; i++) {
      for (int j = 0; j < X.size(); j++) {
         // Calc change for the weights
         float update = m_eta * (y[j] - predict(X[j]));

         for (int w = 1; w < m_w.size(); w++) {
            // Update each weight by the update * the training sample
            m_w[w] += update * X[j][w-1];
         }

         m_w[0] = update; // Update the bias term and setting equal to update
      }
   }
}

void Perceptron::printWeights() {
   printf("Weights: "); 
   for (int i = 0; i < m_w.size(); i++) {
      printf("%f ", m_w[i]);
   }
   printf("\n"); 
}
