#include "SG.hpp"

double SG::invert()
{
  double h = 0.0;
  for(int x1 = 0; x1 != 2; ++x1){
    for(int x2 = 0; x2 != 2; ++x2)
      h += modelData.pr(x1, x2) * std::exp(inExp(x1, x2));
  }
  return h / modelData.pr(1, 1);
}

double SG::inExp(int x1, int x2)
{
  double w = 0.0;
  IntVec xVec = {x1, x2};
  auto& y2DVec = modelData.y2DVec;
  auto& nList = modelData.nList;
  for(int i = 0; i != 2; ++i){
    for(int j = 0; j != nList[i]; ++j)
      w += (1 - 2 * y2DVec[i][j] + 2 * y2DVec[i][j] * xVec[i] - xVec[i] * xVec[i])
            / (2 * sigmaList[i] * sigmaList[i]);
  }

  return w;
}
