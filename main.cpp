#include "ModelData.hpp"
#include "SG.hpp"
#include "ST.hpp"
#include "SP1to2.hpp"
#include "SP2to1.hpp"
#include "SS.hpp"
#include "ROCCurve.hpp"
#include <vector>
#include <iostream>
#include <memory>

int main()
{
  IntVec nList{3, 3};
  DoubleVec sigmaList{1.0, 1.0};
  ModelData model(nList, sigmaList);

  std::cout << "SG開始" << std::endl;
  ROCCurve curveSG(std::make_unique<SG>(model));
  curveSG.plotCurve("SG_3.csv");

  std::cout << "ST開始" << std::endl;
  ROCCurve curveST(std::make_unique<ST>(model));
  curveST.plotCurve("ST_3.csv");

  std::cout << "SP1to2開始" << std::endl;
  ROCCurve curveSP1to2(std::make_unique<SP1to2>(model));
  curveSP1to2.plotCurve("SP1to2_3.csv");

  std::cout << "SS開始" << std::endl;
  ROCCurve curveSS(std::make_unique<SS>(model));
  curveSS.plotCurve("SS_3.csv");
}
