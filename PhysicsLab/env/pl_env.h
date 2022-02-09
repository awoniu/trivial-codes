#pragma once
#include <map>
#include "gui/dataPaint.h"
class MainWindow;

class Env{
public:
  Env();
  void setGui(MainWindow* gui){m_gui=gui;};
  void addCube();
public:
  std::map<int, char> m_obj;
  float m_gravity;
  DataPaint m_ground;
  MainWindow* m_gui;
};