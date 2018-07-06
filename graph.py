"""グラフデータの描画.
"""
import csv
import matplotlib.pyplot as plt
import sys

def openFile(filePath):
  FPRList = []
  CDRList = []
  with open(filePath, 'r') as file:
    tsvData = csv.reader(file, delimiter = ',')
    for row in tsvData:
      FPRList.append(float(row[0]))
      CDRList.append(float(row[1]))
  return (FPRList, CDRList)

def plotCurve(filePath, c, l):
  (FPRList, CDRList) = openFile(filePath)
  plt.plot(FPRList, CDRList, color = c, lw = 0.8, label = l)
  plt.legend(loc = 'lower right')
  plt.xlim(0.0, 1.0)
  plt.ylim(0.0, 1.0)

