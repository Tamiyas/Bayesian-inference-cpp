#include "SS.hpp"
#include <iostream>

double SS::invert()
{
  SP1to2 sp1to2(modelData);
  SP2to1 sp2to1(modelData);
  auto& nList = modelData.nList;
  auto result1to2 = sp1to2.prX1GivenY1(nList);
  auto result2to1 = sp2to1.prX2GivenY2(nList);

  if(result1to2 > result2to1)  return result1to2 * sp1to2.prX2GivenY2(nList);

  return result2to1 * sp2to1.prX1GivenY1(nList);
}
