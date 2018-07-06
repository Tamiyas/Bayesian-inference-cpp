#include "Statistics.hpp"

Statistics::Statistics(const ModelData& modelData_)
  : modelData(modelData_), sigmaList(modelData.sigmaList)
{ }

double Statistics::calculate()
{
  return 1 / invert();
}

const IntVec& Statistics::getXVec()
{
  return modelData.xVec;
}

void Statistics::reset()
{
  modelData.reset();
}
