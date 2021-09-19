using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GoblinEngine.DirectX;

namespace Goblin
{
  public partial class Form1 : Form
  {
    RenderSystem renderSystem;

    public Form1()
    {
      InitializeComponent();

      renderSystem = new RenderSystem(panel1,true, false);
    }
  }
}
