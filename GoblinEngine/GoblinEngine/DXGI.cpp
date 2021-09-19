#include "pch.h"
#include "DXGI.h"

GoblinEngine::DirectX::GraphicOutput::GraphicOutput(IntPtr unmanagedObject)
{
	output = (IDXGIOutput*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::GraphicOutput::~GraphicOutput()
{
	output->Release();
	output = nullptr;
}

System::Collections::Generic::List<ModeDescription^>^ GoblinEngine::DirectX::GraphicOutput::GetDisplayModeList(GraphicFormat format, GraphicModes mode)
{
	List<ModeDescription^>^ modes = gcnew List<ModeDescription^>();
	UINT numModes = 0;
	DXGI_MODE_DESC* modeList;

	output->GetDisplayModeList((DXGI_FORMAT)format, (UINT)mode, &numModes, NULL);

	if (numModes > 0)
	{
		modeList = new DXGI_MODE_DESC[numModes];
		output->GetDisplayModeList((DXGI_FORMAT)format, (UINT)mode, &numModes, modeList);
		for (int i = 0; i < numModes; i++)
		{
			ModeDescription^ desc = gcnew ModeDescription();
			desc->Width = modeList[i].Width;
			desc->Height = modeList[i].Height;
			desc->RefreshRate->Numerator = modeList[i].RefreshRate.Numerator;
			desc->RefreshRate->Denominator = modeList[i].RefreshRate.Denominator;
			desc->Format = (GraphicFormat)modeList[i].Format;
			desc->ScanlineOrdering = (GraphicModeScanlineOrder)modeList[i].ScanlineOrdering;
			desc->Scaling = (GraphicModeScaling)modeList[i].Scaling;
			modes->Add(desc);
		}
	}

	return modes;
}



GoblinEngine::DirectX::GraphicAdapter::GraphicAdapter(IntPtr unmanagedObject)
{
    adapter = (IDXGIAdapter*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::GraphicAdapter::~GraphicAdapter()
{
    adapter->Release();
    adapter = nullptr;
}

AdapterDescription^ GoblinEngine::DirectX::GraphicAdapter::GetDescription()
{
	DXGI_ADAPTER_DESC desc;
	adapter->GetDesc(&desc);

	AdapterDescription^ adapterDesc = gcnew AdapterDescription();
	adapterDesc->Description = gcnew String(desc.Description);
	adapterDesc->VendorId = desc.VendorId;
	adapterDesc->DeviceId= desc.DeviceId;
	adapterDesc->SubSysId = desc.SubSysId;
	adapterDesc->Revision = desc.Revision;
	adapterDesc->DedicatedVideoMemory = desc.DedicatedVideoMemory;
	adapterDesc->DedicatedSystemMemory = desc.DedicatedSystemMemory;
	adapterDesc->SharedSystemMemory = desc.SharedSystemMemory;
	adapterDesc->AdapterLuid = gcnew LongUID();
	adapterDesc->AdapterLuid->HighPart = desc.AdapterLuid.HighPart;
	adapterDesc->AdapterLuid->LowPart = desc.AdapterLuid.LowPart;

	return adapterDesc;
}

GraphicOutput^ GoblinEngine::DirectX::GraphicAdapter::EnumOutputs(unsigned output)
{
	IDXGIOutput* pOutput;
	adapter->EnumOutputs(output, &pOutput);
	IntPtr ptr = (IntPtr)pOutput;
	return gcnew GraphicOutput(ptr);
}



GoblinEngine::DirectX::GraphicFactory::GraphicFactory()
{
	pin_ptr<IDXGIFactory*> pFactory = &factory;
	CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)pFactory);
}

GoblinEngine::DirectX::GraphicFactory::~GraphicFactory()
{
	factory->Release();
	factory = nullptr;
}

GraphicAdapter^ GoblinEngine::DirectX::GraphicFactory::EnumAdapters(unsigned adapter)
{
	IDXGIAdapter* pAdapter;
	factory->EnumAdapters(adapter, &pAdapter);
	IntPtr ptr = (IntPtr)pAdapter;
	return gcnew GraphicAdapter(ptr);
}

