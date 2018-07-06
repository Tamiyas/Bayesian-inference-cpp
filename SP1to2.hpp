#ifndef STATISTICS_SP_1TO2_H
#define STATISTICS_SP_1TO2_H
#include "Statistics.hpp"
#include "ModelData.hpp"
#include <complex>

struct SP1to2 : Statistics {
  SP1to2(const ModelData& modelData) : Statistics(modelData) { }
  double invert() override;
  double inExp(const IntVec& nList, int i);
  double prX1GivenY1(const IntVec& nList);
  double prX2GivenY2(const IntVec& nList);
};

#endif
