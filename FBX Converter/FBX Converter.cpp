#include "pch.h"

#include "FBX Converter.h"
#include <fbxsdk.h>


using namespace System::Runtime::InteropServices;

bool FBXConverter::Converter::ConvertAsciiToBinary(String^ inputPath, String^ outputPath)
{
    const char* inPath = (const char*)(Marshal::StringToHGlobalAnsi(inputPath)).ToPointer();
    const char* outPath = (const char*)(Marshal::StringToHGlobalAnsi(outputPath)).ToPointer();

    FbxManager* manager = FbxManager::Create();
    FbxIOSettings* ios = FbxIOSettings::Create(manager, IOSROOT);
    manager->SetIOSettings(ios);

    FbxImporter* importer = FbxImporter::Create(manager, "");
    if (!importer->Initialize(inPath, -1, manager->GetIOSettings()))
        return false;

    FbxScene* scene = FbxScene::Create(manager, "scene");
    importer->Import(scene);
    importer->Destroy();

    FbxExporter* exporter = FbxExporter::Create(manager, "");
    int binaryFormat = -1;
    int formatCount = manager->GetIOPluginRegistry()->GetWriterFormatCount();
    for (int i = 0; i < formatCount; i++) {
        if (manager->GetIOPluginRegistry()->WriterIsFBX(i)) {
            const char* desc = manager->GetIOPluginRegistry()->GetWriterFormatDescription(i);
            if (strstr(desc, "binary")) {
                binaryFormat = i;
                break;
            }
        }
    }

    if (binaryFormat == -1)
        return false;

    if (!exporter->Initialize(outPath, binaryFormat, manager->GetIOSettings()))
        return false;

    exporter->Export(scene);
    exporter->Destroy();
    manager->Destroy();

    Marshal::FreeHGlobal(IntPtr((void*)inPath));
    Marshal::FreeHGlobal(IntPtr((void*)outPath));
    return true;
}