#ifndef STATISTICS_H
#define STATISTICS_H
#include "ModelData.hpp"

class Statistics {
  protected:
    ModelData modelData;
    DoubleVec sigmaList;
  public:
    Statistics(const ModelData& modelData_);
    virtual ~Statistics() = default;
    double calculate();
    const IntVec& getXVec();
    void reset();
    virtual double invert() = 0;
};


#endif
