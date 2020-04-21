/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "XYController.h"

#include "ACParameters.h"

//==============================================================================
/**
*/
class AcxycontrollerAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    AcxycontrollerAudioProcessorEditor (AcxycontrollerAudioProcessor&);
    ~AcxycontrollerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    Label label1;
    Label label2;

private:
    
    std::unique_ptr<XYController> mXYPad;

    AcxycontrollerAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AcxycontrollerAudioProcessorEditor)
};
