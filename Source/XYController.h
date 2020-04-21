/*
  ==============================================================================

    XYController.h
    Created: 11 Apr 2020 9:02:44pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "PluginProcessor.h"

class XYController:
    public Component
{
    Rectangle<float> rectangle;
    float x_min, x_max, y_min, y_max, x_val, y_val;
    
    Point<float> currentMouseXY;
    Point<float> mouseDownPositionXY;
    
    class XYDot : public Component
{
    Point<float> dotXY;
    Colour colour;
    
public:
    
    XYDot() {}
    
    void setColour (Colour col)
    {
        colour = col;
        repaint();
    }
    
    void paint (Graphics& g)  override
    {
        g.fillAll (Colours::transparentBlack);
        g.setColour (colour);
        g.fillEllipse (getLocalBounds().toFloat());
    }
};
    
    XYDot dot2C;
    
    Label xValueLabel, yValueLabel;
    
public:
    
    XYController(AcxycontrollerAudioProcessor* inProcessor, AudioProcessorValueTreeState& stateToControl,
        const String& x_parameterID,
        const String& x_parameterLabel,
        const String& y_parameterID,
        const String& y_parameterLabel);
    
    ~XYController();
    
    void paint(Graphics& g) override;
    void resized() override;
    
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
  
    Point<int> constrainPosition (float x, float y);
    Point<int> getValueAsPosition (float x, float y);

    void setPositionAsValue (Point<float> position);

    
private:
    
    AcxycontrollerAudioProcessor* mProcessor;
    
    Slider x_axis_slider;
    Slider y_axis_slider;
    
public:

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> x_attachment;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> y_attachment;

};
