#pragma once

using namespace System;

namespace FBXConverter {
	public ref class Converter
	{
		public:
		static bool ConvertAsciiToBinary(String^ inputPath, String^ outputPath);
	};
}
