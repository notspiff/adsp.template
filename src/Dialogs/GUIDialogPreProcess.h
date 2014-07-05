#pragma once
/*
 *      Copyright (C) 2005-2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "template/include/GUIDialogBase.h"

class CGUIDialogPreProcess : public CGUIDialogBase
{
public:
  CGUIDialogPreProcess();
  ~CGUIDialogPreProcess();

private:
  virtual bool OnInit();
  virtual bool OnClick(int controlId);
  virtual bool OnFocus(int controlId);
  virtual bool OnAction(int actionId);

  CAddonGUISettingsSliderControl   *m_DemoValue1_Slider;
  CAddonGUIRadioButton             *m_DemoValue2_RadioButton;
  CAddonGUISpinControl             *m_DemoValue3_SpinControl;
};
