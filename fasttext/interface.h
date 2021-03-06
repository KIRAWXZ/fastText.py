#ifndef FASTTEXT_INTERFACE_H
#define FASTTEXT_INTERFACE_H

#include <string>
#include <vector>
#include <memory>

#include "cpp/src/real.h"
#include "cpp/src/args.h"
#include "cpp/src/dictionary.h"
#include "cpp/src/matrix.h"
#include "cpp/src/model.h"
#include "cpp/src/qmatrix.h"

using namespace fasttext;

class FastTextModel {
    private:
        std::vector<std::string> _words;
        std::shared_ptr<Dictionary> _dict;
        std::shared_ptr<Matrix> _input_matrix;
        std::shared_ptr<Matrix> _output_matrix;
        std::shared_ptr<Model> _model;

    public:
        FastTextModel();
        int dim;
        int ws;
        int epoch;
        int minCount;
        int neg;
        int wordNgrams;
        std::string lossName;
        int bucket;
        int minn;
        int maxn;
        double lr;
        int lrUpdateRate;
        double t;

        std::vector<std::vector<std::string>> classifierPredictProb(std::string text,
                int32_t k);

        void setArgs(std::shared_ptr<Args> args);
        void setDictionary(std::shared_ptr<Dictionary> dict);
        void setMatrix(std::shared_ptr<Matrix> input,
                std::shared_ptr<Matrix> output);
        void setModel(std::shared_ptr<Model> model);
};
typedef void (*callbackfunc)(double progress, void *user_data);
void trainWrapper(int argc, char **argv, int silent, callbackfunc callback_run, void* callback);
void loadModelWrapper(std::string filename, FastTextModel& model);

#endif

