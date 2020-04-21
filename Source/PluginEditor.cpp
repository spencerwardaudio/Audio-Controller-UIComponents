/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AcxycontrollerAudioProcessorEditor::AcxycontrollerAudioProcessorEditor (AcxycontrollerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    mXYPad = std::make_unique<XYController>(&processor, processor.treeState,
    "Freq1",
    "Frequency1",
    "Q1",
    "QControl1");
    
    mXYPad->setTopLeftPosition(0, 0);
    
    addAndMakeVisible(mXYPad.get());
    
    repaint();
    
//    addAndMakeVisible(&XYdot);
    
    
    label1.setText("label1", dontSendNotification);
    label1.setColour(Label::textColourId, Colours::white);
//    label1.setJustificationType (Justification::centred);
//    addAndMakeVisible(label1);
    
    label2.setText("label2", dontSendNotification);
    label2.setColour(Label::textColourId, Colours::white);
    label2.setBounds(20,  20, getWidth() - 20,  30);
    addAndMakeVisible(label2);
    
    setSize (200, 200);

}

AcxycontrollerAudioProcessorEditor::~AcxycontrollerAudioProcessorEditor()
{
}

//==============================================================================
void AcxycontrollerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));


}

void AcxycontrollerAudioProcessorEditor::resized()
{

//    label1.setBounds(50, 80, 30, 20);
//    label2.setBounds(50, 140, 30, 20);
}
