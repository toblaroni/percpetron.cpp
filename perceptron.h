#include <vector>

class Perceptron {
   public:
      Perceptron(float eta, int epochs);
      float netInput(std::vector<float> X);
      int predict(std::vector<float> X);
      void fit(std::vector<std::vector<float>> X, std::vector<float> y);
   private:
};
