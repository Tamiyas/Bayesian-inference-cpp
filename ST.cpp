#include "ST.hpp"

double ST::invert()
{
  return 1 + modelData.pr(0, 0) * std::exp(inExp()) / modelData.pr(1, 1);
}

double ST::inExp()
{
  double w = 0.0;
  auto& y2DVec = modelData.y2DVec;
  auto& nList  = modelData.nList;
  for(int i = 0; i != 2; ++i){
    for(int j = 0; j != nList[i]; ++j)
      w += (1 - 2 * y2DVec[i][j]) / (2 * sigmaList[i] * sigmaList[i]);
  }

  return w;
}
