/*
FileCopyEx - Extended File Copy plugin for Far 2 file manager

Copyright (C) 2004 - 2010
Idea & core: Max Antipin
Coding: Serge Cheperis aka craZZy
Bugfixes: slst, CDK, Ivanych, Alter, Axxie and Nsky
Special thanks to Vitaliy Tsubin
Far 2 (32 & 64 bit) full unicode version by djdron

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "FarPlugin.h"
#include "taskbarIcon.h"

const int WIN_NONE          = 0;
const int WIN_MESSAGE       = 1;
const int WIN_PROGRESS      = 2;
const int WIN_SCAN_PROGRESS = 3;

class FarProgress
{
public:
  FarProgress(void);
  virtual ~FarProgress(void);
  void ShowMessage(const String &);
  void ShowProgress(const String &);
  void ShowScanProgress(const String & msg);
  void SetScanProgressInfo(int64_t NumberOfFiles, int64_t TotalSize);
  void Hide();
  void SetPercent(float);
  void SetNeedToRedraw(bool Value);

  bool InverseBars;
protected:
  FarColor clrFrame, clrTitle, clrBar, clrText, clrLabel;
  int ProgX1, ProgX2, ProgY, WinType;
  HANDLE hScreen;
  static void DrawWindow(int, int, int, int, const String &);
  static void GetConSize(int &, int &);
  void DrawProgress(int, int, int, float);
  static void Text(intptr_t, intptr_t, FarColor *, const String &);
  static void SetTitle(const String &);
  void SetTitle2(const String &) const;
  static String GetTitle();
  String TitleBuf, ProgTitle;
  void DrawScanProgress(int x1, int x2, int y, int64_t NumberOfFiles, int64_t TotalSize);
  int64_t LastUpdate;
  bool NeedToRedraw;

  TaskBarIcon taskbarIcon;

private:
  void RedrawWindowIfNeeded();
  void RedrawWindow();
};
