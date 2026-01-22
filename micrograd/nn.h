#include "value.h"
#include <vector>
#include <random>
#include <cassert>

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

        Value operator()(const std::vector<Value>& inputs) const{
            assert(inputs.size() == nin);

            Value output{bias};

            for (size_t i{0}; i<nin ;i++){
                output = output + (inputs[i] * weights[i]);
            }
            return output.tanh();
        }


        std::vector<Value> parameters() const{\
            std::vector<Value> params;
            params.reserve(nin+1);
            params.insert(params.end(), weights.begin(), weights.end());
            params.push_back(bias);
            return params;
        }
};
