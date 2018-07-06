#ifndef STATISTICS_SG_H
#define STATISTICS_SG_H
#include "Statistics.hpp"
#include "ModelData.hpp"
#include <complex>

struct SG : Statistics {
  SG(const ModelData& modelData) : Statistics(modelData) { }
  double invert() override;
  double inExp(int x1, int x2);
};

#endif
