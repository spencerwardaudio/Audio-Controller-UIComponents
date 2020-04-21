/*
  ==============================================================================

    ACParameters.h
    Created: 13 Apr 2020 11:18:43pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

enum ACParameter
{
    aParameter_freq1 = 0,
    aParameter_Q1,
    aParameter_freq2,
    aParameter_Q2,
    aParameter_TotalNumParameters
};

static String ACParameterID [aParameter_TotalNumParameters] = 
{
    "Freq1",
    "Q1",
    "Freq2",
    "Q2"
};

static String ACParameterLabel [aParameter_TotalNumParameters] =
{
    "Frequency1"
    "QControl1",
    "Frequency2",
    "QControl2"
};
