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

#include "include/GUIDialogBase.h"

using namespace std;
using namespace ADDON;

CGUIDialogBase::CGUIDialogBase( std::string xmlFilename, bool ForceFallback, bool AsDialog, std::string DefaultSkin )
{
  m_window = GUI->Window_create(  xmlFilename.c_str(), 
                  DefaultSkin.c_str(),
                  ForceFallback, 
                  AsDialog );
  if(m_window)
  {
    m_window->m_cbhdl     = this;
    m_window->CBOnInit    = OnInitCB;
    m_window->CBOnFocus   = OnFocusCB;
    m_window->CBOnClick   = OnClickCB;
    m_window->CBOnAction  = OnActionCB;
  }
  else
  {
    XBMC->Log( LOG_ERROR, "Couldn't create m_window! Not enough free memory?" );
  }
}

CGUIDialogBase::~CGUIDialogBase()
{
  if(m_window)
  {
    GUI->Window_destroy(m_window);
  }
}

bool CGUIDialogBase::OnInitCB(GUIHANDLE cbhdl)
{
  CGUIDialogBase *dialog = static_cast<CGUIDialogBase*>(cbhdl);
  return dialog->OnInit();
}

bool CGUIDialogBase::OnClickCB(GUIHANDLE cbhdl, int controlId)
{
  CGUIDialogBase *dialog = static_cast<CGUIDialogBase*>(cbhdl);
  return dialog->OnClick(controlId);
}

bool CGUIDialogBase::OnFocusCB(GUIHANDLE cbhdl, int controlId)
{
  CGUIDialogBase *dialog = static_cast<CGUIDialogBase*>(cbhdl);
  return dialog->OnFocus(controlId);
}

bool CGUIDialogBase::OnActionCB(GUIHANDLE cbhdl, int actionId)
{
  CGUIDialogBase *dialog = static_cast<CGUIDialogBase*>(cbhdl);
  return dialog->OnAction(actionId);
}

bool CGUIDialogBase::Show()
{
  if (m_window)
  {
    return m_window->Show();
  }
  else
  {
    return false;
  }
}

void CGUIDialogBase::Close()
{
  if (m_window)
  {
    m_window->Close();
  }
}

void CGUIDialogBase::DoModal()
{
  if (m_window)
  {
    m_window->DoModal();
  }
}
