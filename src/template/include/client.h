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
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "xbmc/libXBMC_addon.h"
#include "xbmc/libXBMC_adsp.h"
#include "xbmc/libXBMC_gui.h"

extern bool                          m_bCreated;
extern std::string                   g_strUserPath;
extern std::string                   g_strAddonPath;
extern ADDON::CHelper_libXBMC_addon *XBMC;
extern CHelper_libXBMC_gui          *GUI;
extern CHelper_libXBMC_adsp         *ADSP;
