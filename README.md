This is an updated version of the original kn5 converter

This version adds a new tool called the FBX Converter to convert ASCII FBX to binary FBX which is then called by the kn5 converter.
The FBX converter utilizes the FBX SDK.


### Changes to kn5 converter
- Updated to .NET Framework 4.8
- Creates binary FBX file alongside the original ASCII FBX.

### To Build
Make sure you install the FBX SDK and make sure these options are all correct for the FBX Converter project. (https://help.autodesk.com/view/FBX/2020/ENU/?guid=FBX_Developer_Help_getting_started_installing_and_configuring_configuring_the_fbx_sdk_for_wind_html)
Also ensure that the FBX converter and kn5 converter are on the same platform.
