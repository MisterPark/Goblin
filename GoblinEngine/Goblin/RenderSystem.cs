using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GoblinEngine.DirectX;

namespace Goblin
{
  class RenderSystem
  {
    public Device Device { get; private set; }
    public DeviceContext DeviceContext { get; private set; }
    public SwapChain SwapChain { get; private set; }

    public bool VsyncEnabled { get; set; }
    public bool FullScreen { get; set; }

    public uint ScreenWidth { get; private set; }
    public uint ScreenHeight { get; private set; }

    public uint VideoMemory { get; private set; }
    public string VideoDescription { get; private set; }

    public RenderSystem(Control renderWindow, bool vsyncEnabled, bool fullscreen)
    {
      VsyncEnabled = vsyncEnabled;
      FullScreen = fullscreen;
      ScreenWidth = (uint)Screen.PrimaryScreen.Bounds.Width;
      ScreenHeight = (uint)Screen.PrimaryScreen.Bounds.Height;

      GraphicFactory factory = new GraphicFactory();
      GraphicAdapter adapter = factory.EnumAdapters(0);
      GraphicOutput output = adapter.EnumOutputs(0);
      List<ModeDescription> modes = output.GetDisplayModeList(GraphicFormat.R8G8B8A8_UNORM, GraphicModes.Interlaced);

      uint numerator = 0;
      uint denominator = 0;

      foreach (var mode in modes)
      {
        if(mode.Width == ScreenWidth && mode.Height == ScreenHeight)
        {
          numerator = mode.RefreshRate.Numerator;
          denominator = mode.RefreshRate.Denominator;
        }
      }

      AdapterDescription adapterDesc = adapter.GetDescription();

      VideoMemory = adapterDesc.DedicatedVideoMemory / 1024 / 1024;
      VideoDescription = adapterDesc.Description;

      output.Dispose();
      adapter.Dispose();
      factory.Dispose();

      SwapChainDescription swapChainDesc = new SwapChainDescription();
      swapChainDesc.BufferCount = 1;
      
      swapChainDesc.BufferDescription.Width = ScreenWidth;
      swapChainDesc.BufferDescription.Height = ScreenHeight;

      swapChainDesc.BufferDescription.Format = GraphicFormat.R8G8B8A8_UNORM;

      if(VsyncEnabled)
      {
        swapChainDesc.BufferDescription.RefreshRate.Numerator = numerator;
        swapChainDesc.BufferDescription.RefreshRate.Denominator = denominator;
      }
      else
      {
        swapChainDesc.BufferDescription.RefreshRate.Numerator = 0;
        swapChainDesc.BufferDescription.RefreshRate.Denominator = 1;
      }

      swapChainDesc.BufferUsage = GraphicUsage.RenderTargetOutput;
      swapChainDesc.OutputWindow = renderWindow.Handle;
      swapChainDesc.SampleDescription.Count = 1;
      swapChainDesc.SampleDescription.Quality = 0;

      swapChainDesc.Windowed = !FullScreen;

      swapChainDesc.BufferDescription.ScanlineOrdering = GraphicModeScanlineOrder.Unspecified;
      swapChainDesc.BufferDescription.Scaling = GraphicModeScaling.Unspecified;

      swapChainDesc.SwapEffect = SwapEffect.Discard;

      swapChainDesc.Flags = 0;

      SwapChain sc;
      DeviceContext dc;
      Device = new Device(DriverType.Hardware, FeatureLevel._11_0, swapChainDesc, out sc, out dc);
      SwapChain = sc;
      DeviceContext = dc;
    }
  }
}
