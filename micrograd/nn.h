#include "value.h"
#include <vector>
#include <random>

class Neuron{
    size_t nin;
    std::vector<Value> weights;
    Value bias;

    public:
        Neuron(size_t inputs): nin{inputs}, bias{0.0}{
            static std::mt19937 gen(std::random_device{}());
            std::uniform_real_distribution<double> dist(-1.0, 1.0);

            for (size_t i{0}; i<nin ;i++){
                weights.push_back(Value(dist(gen)));
            }
        };
};