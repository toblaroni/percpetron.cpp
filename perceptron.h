#include <vector>

using namespace std;
class Perceptron {
   public:
      Perceptron(float eta, int epochs);
      float netInput(vector<float> X);
      int predict(vector<float> X);
      void fit(vector<vector<float>> X, vector<float> y);
      void printWeights();
   private:
      float m_eta;         // Constant learning rate
      int m_epochs;        // Number of passes we do over the training set
      vector <float> m_w;  // Weights
};
