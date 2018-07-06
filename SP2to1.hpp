#ifndef STATISTCS_SP_2TO1_H
#define STATISTCS_SP_2TO1_H
#include "Statistics.hpp"
#include "ModelData.hpp"
#include <complex>

struct SP2to1 : Statistics {
  SP2to1(const ModelData& modelData) : Statistics(modelData) { }
  double invert() override;
  double inExp(const IntVec& nList, int i);
  double prX2GivenY2(const IntVec& nList);
  double prX1GivenY1(const IntVec& nList);
};

#endif
