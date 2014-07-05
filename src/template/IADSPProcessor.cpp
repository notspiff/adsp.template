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

#include "include/IADSPProcessor.h"

IADSPProcessor::IADSPProcessor()
{
}

IADSPProcessor::~IADSPProcessor()
{
}

unsigned int IADSPProcessor::PreProcessNeededSamplesize(unsigned int Mode_id)
{
  return 0;
}

unsigned int IADSPProcessor::InputResampleProcessNeededSamplesize()
{
  return 1024;
}

int IADSPProcessor::InputResampleSampleRate()
{
  return m_StreamSettings.iProcessSamplerate;
}

AE_DSP_ERROR IADSPProcessor::MasterProcessSetMode(AE_DSP_STREAMTYPE Type, unsigned int Mode_id, int Unique_db_mode_id)
{
  return AE_DSP_ERROR_NO_ERROR;
}

unsigned int IADSPProcessor::MasterProcessNeededSamplesize()
{
  return 1024;
}

int IADSPProcessor::MasterProcessGetOutChannels(unsigned long &Out_channel_present_flags)
{
  return -1;
}

const char *IADSPProcessor::MasterProcessGetStreamInfoString()
{
  return "";
}

unsigned int IADSPProcessor::PostProcessNeededSamplesize(unsigned int Mode_id)
{
  return 0;
}
  
unsigned int IADSPProcessor::OutputResampleProcessNeededSamplesize()
{
  return 0;
}

int IADSPProcessor::OutputResampleSampleRate()
{
  return m_StreamSettings.iProcessSamplerate;
}

AE_DSP_ERROR IADSPProcessor::StreamIsModeSupported(AE_DSP_MODE_TYPE Type, unsigned int Mode_id, int Unique_db_mode_id)
{
  return AE_DSP_ERROR_NO_ERROR;
}
