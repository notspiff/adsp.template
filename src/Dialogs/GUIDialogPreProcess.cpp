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

#include "GUIDialogPreProcess.h"

using namespace ADDON;

#define BUTTON_OK                                 1
#define BUTTON_CANCEL                             2

#define DEMO_VALUE_1_SLIDER                       41
#define DEMO_VALUE_2_RADIO_BUTTON                 42
#define DEMO_VALUE_3_SPIN_CONTROL                 43

#define ACTION_NAV_BACK                          92

CGUIDialogPreProcess::CGUIDialogPreProcess()
 : CGUIDialogBase(  "DialogPreProcess.xml", false, true )
 , m_DemoValue1_Slider(NULL)
 , m_DemoValue2_RadioButton(NULL)
 , m_DemoValue3_SpinControl(NULL)
{
}

CGUIDialogPreProcess::~CGUIDialogPreProcess()
{
}

bool CGUIDialogPreProcess::OnInit()
{
  m_DemoValue1_Slider = GUI->Control_getSettingsSlider(m_window, DEMO_VALUE_1_SLIDER);
  m_DemoValue1_Slider->SetFloatValue(0.5f);

  m_DemoValue2_RadioButton = GUI->Control_getRadioButton(m_window, DEMO_VALUE_2_RADIO_BUTTON);
  m_DemoValue2_RadioButton->SetVisible(true);
  m_DemoValue2_RadioButton->SetSelected(false);

  m_DemoValue3_SpinControl = GUI->Control_getSpin(m_window, DEMO_VALUE_3_SPIN_CONTROL);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 1", 0);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 2", 1);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 3", 2);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 4", 3);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 5", 4);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 6", 5);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 7", 6);
  m_DemoValue3_SpinControl->AddLabel("Test-Value 8", 7);
  m_DemoValue3_SpinControl->SetVisible(true);
  m_DemoValue3_SpinControl->SetValue(0);

  return true;
}

bool CGUIDialogPreProcess::OnClick(int controlId)
{
  switch (controlId)
  {
    case DEMO_VALUE_1_SLIDER:
    {
      float value = m_DemoValue1_Slider->GetFloatValue();
      XBMC->Log(LOG_DEBUG, "%s - m_DemoValue1_Slider value set to %.02f", __PRETTY_FUNCTION__, value);
      break;
    }
    case DEMO_VALUE_2_RADIO_BUTTON:
    {
      bool selected = m_DemoValue2_RadioButton->IsSelected();
      XBMC->Log(LOG_DEBUG, "%s - m_DemoValue2_RadioButton value set to %s", __PRETTY_FUNCTION__, selected ? "true" : "false");
      break;
    }
    case DEMO_VALUE_3_SPIN_CONTROL:
    {
      int value = m_DemoValue3_SpinControl->GetValue();
      XBMC->Log(LOG_DEBUG, "%s - m_DemoValue3_SpinControl value set to %i", __PRETTY_FUNCTION__, value);
      break;
    }
    case BUTTON_CANCEL:
    {
      this->Close();
      break;
    }
    case BUTTON_OK:
    {
      this->Close();
      break;
    }
    default:
      break;
  }

  return true;
}

bool CGUIDialogPreProcess::OnFocus(int controlId)
{
  return true;
}

bool CGUIDialogPreProcess::OnAction(int actionId)
{
  if (actionId == ADDON_ACTION_CLOSE_DIALOG ||
      actionId == ADDON_ACTION_PREVIOUS_MENU ||
      actionId == ACTION_NAV_BACK)
    return OnClick(BUTTON_CANCEL);
  else
    return false;
}
