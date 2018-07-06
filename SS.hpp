#ifndef STATISTICS_SS_H
#define STATISTICS_SS_H
#include "Statistics.hpp"
#include "SP1to2.hpp"
#include "SP2to1.hpp"
#include "ModelData.hpp"
#include <algorithm>

struct SS : Statistics {
    SS(const ModelData& modelData)
     : Statistics(modelData) { }
    double invert() override;
};

#endif
