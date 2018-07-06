#ifndef STATISTICS_ST_H
#define STATISTICS_ST_H
#include "Statistics.hpp"
#include "ModelData.hpp"
#include <complex>

struct ST : Statistics {
  ST(const ModelData& modelData) : Statistics(modelData) { }
  double invert() override;
  double inExp();
};

#endif
