#include "SP1to2.hpp"

double SP1to2::invert()
{
  auto& nList = modelData.nList;
  return prX1GivenY1(nList) * prX2GivenY2(nList);
}

double SP1to2::prX1GivenY1(const IntVec& nList)
{
  return 1 + (modelData.prX1(0) / modelData.prX1(1)) * std::exp(inExp(nList, 0));
}

double SP1to2::prX2GivenY2(const IntVec& nList)
{
  return 1 + (modelData.pr(1, 0) / modelData.pr(1, 1)) * std::exp(inExp(nList, 1));
}

double SP1to2::inExp(const IntVec& nList, int i)
{
  double w = 0.0;
  auto& y2DVec = modelData.y2DVec;
  for(int j = 0; j != nList[i]; ++j)
    w += (1 - 2 * y2DVec[i][j]) / (2 * sigmaList[i] * sigmaList[i]);
  return w;
}
