//------------------------------------------------------------------------
// Copyright(c) 2024 Noah Dominic.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace NoahDominic {
//------------------------------------------------------------------------
static const Steinberg::FUID kNSimpleClipperProcessorUID (0x9C840BC3, 0x993B5AB6, 0x8FC2D12B, 0x36C05572);
static const Steinberg::FUID kNSimpleClipperControllerUID (0x9FED3586, 0x6FF050AB, 0x99ADD189, 0x4EEB069C);

#define NSimpleClipperVST3Category "Fx"

enum NSimpleClipperParams : Steinberg::Vst::ParamID
{
	kParamCeilingId = 102,
	kParamGainId = 103,
};

//------------------------------------------------------------------------
} // namespace NoahDominic
