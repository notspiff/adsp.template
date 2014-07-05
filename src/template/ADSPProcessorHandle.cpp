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

#include "include/ADSPProcessorHandle.h"
#include <string.h>

CADSPProcessorHandle::CADSPProcessorHandle(const AE_DSP_SETTINGS *Settings, const AE_DSP_STREAM_PROPERTIES *pProperties)
{
  memcpy(&m_StreamSettings, Settings, sizeof(AE_DSP_SETTINGS));
  memcpy(&m_StreamProperties, pProperties, sizeof(AE_DSP_SETTINGS));
}

CADSPProcessorHandle::~CADSPProcessorHandle()
{
}

AE_DSP_ERROR CADSPProcessorHandle::StreamInitialize(const AE_DSP_SETTINGS *Settings)
{
  AE_DSP_ERROR err = AE_DSP_ERROR_NO_ERROR;
  memcpy(&m_StreamSettings, Settings, sizeof(AE_DSP_SETTINGS));

  return AE_DSP_ERROR_NO_ERROR;
}

float CADSPProcessorHandle::OutputResampleGetDelay()
{
  return (float)m_StreamSettings.iInFrames / (float)m_StreamSettings.iInSamplerate;
}

float CADSPProcessorHandle::PostProcessGetDelay(unsigned int Mode_id)
{
  return (float)m_StreamSettings.iInFrames / (float)m_StreamSettings.iInSamplerate;
}

float CADSPProcessorHandle::MasterProcessGetDelay()
{
  return (float)m_StreamSettings.iInFrames / (float)m_StreamSettings.iInSamplerate;
}

float CADSPProcessorHandle::PreProcessGetDelay(unsigned int Mode_id)
{
  return (float)m_StreamSettings.iInFrames / (float)m_StreamSettings.iInSamplerate;
}

float CADSPProcessorHandle::InputResampleGetDelay()
{
  return (float)m_StreamSettings.iInFrames / (float)m_StreamSettings.iInSamplerate;
}
