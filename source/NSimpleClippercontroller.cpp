//------------------------------------------------------------------------
// Copyright(c) 2024 Noah Dominic.
//------------------------------------------------------------------------

#include "NSimpleClippercontroller.h"
#include "NSimpleClippercids.h"
#include <base/source/fstreamer.h>


using namespace Steinberg;

namespace NoahDominic {

//------------------------------------------------------------------------
// NSimpleClipperController Implementation
//------------------------------------------------------------------------
tresult PLUGIN_API NSimpleClipperController::initialize (FUnknown* context)
{
	// Here the Plug-in will be instantiated

	//---do not forget to call parent ------
	tresult result = EditControllerEx1::initialize (context);
	if (result != kResultOk)
	{
		return result;
	}

	// Here you could register some parameters
	parameters.addParameter(STR16("Ceiling"), STR16("dB"), 0, 1.f, Vst::ParameterInfo::kCanAutomate, NSimpleClipperParams::kParamCeilingId, 0);
	parameters.addParameter(STR16("Gain"), STR16("dB"), 0, 0.f, Vst::ParameterInfo::kCanAutomate, NSimpleClipperParams::kParamGainId, 0);

	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API NSimpleClipperController::terminate ()
{
	// Here the Plug-in will be de-instantiated, last possibility to remove some memory!

	//---do not forget to call parent ------
	return EditControllerEx1::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API NSimpleClipperController::setComponentState (IBStream* state)
{
	// Here you get the state of the component (Processor part)
	if (!state)
		return kResultFalse;
	if (!state)
		kResultFalse;

	// called when we load a preset, the model has to be reloaded
	IBStreamer streamer(state, kLittleEndian);
	float savedParams[] = { 0.f, 0.f };
	if (streamer.readFloatArray(savedParams, 2) == false)
	{
		return kResultFalse;
	}

	if (auto param = parameters.getParameter(NSimpleClipperParams::kParamCeilingId))
		param->setNormalized(savedParams[0]);
	if (auto param = parameters.getParameter(NSimpleClipperParams::kParamGainId))
		param->setNormalized(savedParams[1]);

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API NSimpleClipperController::setState (IBStream* state)
{
	// Here you get the state of the controller

	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API NSimpleClipperController::getState (IBStream* state)
{
	// Here you are asked to deliver the state of the controller (if needed)
	// Note: the real state of your plug-in is saved in the processor

	return kResultTrue;
}

//------------------------------------------------------------------------
IPlugView* PLUGIN_API NSimpleClipperController::createView (FIDString name)
{
	// Here the Host wants to open your editor (if you have one)
	if (FIDStringsEqual (name, Vst::ViewType::kEditor))
	{
		// create your editor here and return a IPlugView ptr of it
        return nullptr;
	}
	return nullptr;
}

//------------------------------------------------------------------------
} // namespace NoahDominic
