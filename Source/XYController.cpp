/*
  ==============================================================================

    XYController.cpp
    Created: 11 Apr 2020 9:02:44pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "XYController.h"


XYController::XYController(AcxycontrollerAudioProcessor* inProcessor, AudioProcessorValueTreeState& stateToControl,
const String& x_parameterID,
const String& x_parameterLabel,
const String& y_parameterID,
const String& y_parameterLabel):

    x_min(0),
    x_max(1),
    y_min(0),
    y_max(1),
    x_val(50.0f),
    y_val(20.0f),
    dot2C(),
mProcessor(inProcessor)

{
    // Default dimensions
    setSize(200, 200);
    
    addAndMakeVisible(dot2C);

//    x_axis_slider = new Slider(x_parameterLabel);
//    y_axis_slider = new Slider(y_parameterLabel);
    y_axis_slider.setSliderStyle(Slider::RotaryHorizontalDrag);
    y_axis_slider.setRange(0.0f, 1.0f);
    y_axis_slider.setBounds(20, 60, 100, 100);
    y_axis_slider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    addAndMakeVisible(&y_axis_slider);
    
    x_axis_slider.setSliderStyle(Slider::RotaryHorizontalDrag);
    x_axis_slider.setRange(0.0f, 1.0f);
    x_axis_slider.setBounds(100, 60, 100, 100);
    x_axis_slider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    addAndMakeVisible(&x_axis_slider);
    
    
    // Attach the sliders to the AudioProcessorValueTreeState
    x_attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, x_parameterID, x_axis_slider);
    
    y_attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, y_parameterID, y_axis_slider);
 
}

XYController::~XYController()
{
    
}

void XYController::mouseDown (const MouseEvent& e)
{
    dot2C.setTopLeftPosition(constrainPosition (e.getPosition().getX(), e.getPosition().getY()));
    mouseDownPositionXY.setXY(dot2C.getPosition().getX(), dot2C.getPosition().getY());
    setPositionAsValue(dot2C.getPosition().toFloat());
    
    repaint();
}

void XYController::mouseDrag (const MouseEvent& e)
{
    if (e.mouseWasDraggedSinceMouseDown())
{
    dot2C.setTopLeftPosition (constrainPosition (mouseDownPositionXY.getX() + e.getDistanceFromDragStartX(), mouseDownPositionXY.getY() + e.getDistanceFromDragStartY()));
    setPositionAsValue (dot2C.getPosition().toFloat());
    repaint();
    
    currentMouseXY = dot2C.getPosition().toFloat();
}
}

Point<int> XYController::constrainPosition (float x, float y)
{
    const float xPos = x;
    const float yPos = y;
    return Point<int> (xPos, yPos);
}

Point<int> XYController::getValueAsPosition(float x, float y)
{

    const float xPos = x;
    const float yPos = y;
    return Point<int> (xPos, yPos);
}

void XYController::setPositionAsValue(Point<float> position)
{
    
    const float xVal = position.getX();
    float yVal = position.getY();
    
    
    
    auto scaledXVal = (float)jmap (xVal, 0.0f, 200.0f, 0.0f, 1.0f);
    auto scaledYVal = (float)jmap (yVal, 0.0f, 200.0f, 0.0f, 1.0f);;

    x_axis_slider.setValue(scaledXVal, sendNotification);
    std::cout << scaledXVal << "value of x" << std::endl;
    
    y_axis_slider.setValue(scaledYVal, sendNotification);
    std::cout << scaledYVal << "value of y" << std::endl;
    
}

void XYController::paint(Graphics& g)
{
    // Text label
    g.setColour (Colours::white);

}

void XYController::resized()
{
    dot2C.setSize(20, 20);
    const Point<int> pos (getValueAsPosition (x_val, y_val));
    dot2C.setTopLeftPosition(pos.getX(), pos.getY());
    dot2C.setInterceptsMouseClicks (false, false);
    dot2C.setColour (Colours::red);
    
    x_axis_slider.setTopLeftPosition(30, 60);
    y_axis_slider.setTopLeftPosition(60, 60);
}

