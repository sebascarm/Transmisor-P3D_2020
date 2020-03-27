using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//Agregados
using System.Runtime.InteropServices;   //Para capturar servicios (DLL IMPORTS)
using System.Threading;                 //Para multi hilo (o pausa de hilo)
using System.IO;                        //Utilizado para obtener el Path
using System.Diagnostics;               //Utilizado para obtener matriz de procesos - Process[]
// hook
using Capture.Interface;
using Capture;
using Capture.Hook;

namespace Capturador
{
    public partial class Form : System.Windows.Forms.Form
    {
        // Constantes para mensajes  
        const int WM_COMMAND = 0X111;
        const int WM_MOVE = 0x0003;
        // Variables                
        int ProcesoId = 0;
        Process _Proceso;
        CaptureProcess _Proceso_Captura;
        IntPtr SwapChain = (IntPtr)0;
        bool Capturando = false;
        List<IntPtr> List_Swap_Recibido = new List<IntPtr>();
        // Lista de objetos
        List<TextBox> L_TextBox_Elemento = new List<TextBox>();
        List<TextBox> L_TextBox_Key = new List<TextBox>();
        List<TextBox> L_TextBox_hwdn = new List<TextBox>();
        List<TextBox> L_TextBox_Point = new List<TextBox>();
        List<RadioButton> L_Radio_Sel = new List<RadioButton>();
        //IntPtr[] Swap_Recibido = new IntPtr[10];
        public Form()
        {
            InitializeComponent();
        }

        private void Form_Load(object sender, EventArgs e)
        {
            L_TextBox_Elemento.Add(Text_1);
            L_TextBox_Elemento.Add(Text_2);
            L_TextBox_Elemento.Add(Text_3);
            L_TextBox_Elemento.Add(Text_4);
            L_TextBox_Elemento.Add(Text_5);
            L_TextBox_Elemento.Add(Text_6);
            L_TextBox_Elemento.Add(Text_7);
            L_TextBox_Elemento.Add(Text_8);
            L_TextBox_Elemento.Add(Text_9);
            L_TextBox_Elemento.Add(Text_10);

            L_TextBox_Key.Add(Text_Key_1);
            L_TextBox_Key.Add(Text_Key_2);
            L_TextBox_Key.Add(Text_Key_3);
            L_TextBox_Key.Add(Text_Key_4);
            L_TextBox_Key.Add(Text_Key_5);
            L_TextBox_Key.Add(Text_Key_6);
            L_TextBox_Key.Add(Text_Key_7);
            L_TextBox_Key.Add(Text_Key_8);
            L_TextBox_Key.Add(Text_Key_9);
            L_TextBox_Key.Add(Text_Key_10);

            L_TextBox_hwdn.Add(Text_hwnd_1);
            L_TextBox_hwdn.Add(Text_hwnd_2);
            L_TextBox_hwdn.Add(Text_hwnd_3);
            L_TextBox_hwdn.Add(Text_hwnd_4);
            L_TextBox_hwdn.Add(Text_hwnd_5);
            L_TextBox_hwdn.Add(Text_hwnd_6);
            L_TextBox_hwdn.Add(Text_hwnd_7);
            L_TextBox_hwdn.Add(Text_hwnd_8);
            L_TextBox_hwdn.Add(Text_hwnd_9);
            L_TextBox_hwdn.Add(Text_hwnd_10);

            L_TextBox_Point.Add(Text_Pointer_1);
            L_TextBox_Point.Add(Text_Pointer_2);
            L_TextBox_Point.Add(Text_Pointer_3);
            L_TextBox_Point.Add(Text_Pointer_4);
            L_TextBox_Point.Add(Text_Pointer_5);
            L_TextBox_Point.Add(Text_Pointer_6);
            L_TextBox_Point.Add(Text_Pointer_7);
            L_TextBox_Point.Add(Text_Pointer_8);
            L_TextBox_Point.Add(Text_Pointer_9);
            L_TextBox_Point.Add(Text_Pointer_10);

            L_Radio_Sel.Add(Radio_Bot_1);
            L_Radio_Sel.Add(Radio_Bot_2);
            L_Radio_Sel.Add(Radio_Bot_3);
            L_Radio_Sel.Add(Radio_Bot_4);
            L_Radio_Sel.Add(Radio_Bot_5);
            L_Radio_Sel.Add(Radio_Bot_6);
            L_Radio_Sel.Add(Radio_Bot_7);
            L_Radio_Sel.Add(Radio_Bot_8);
            L_Radio_Sel.Add(Radio_Bot_9);
            L_Radio_Sel.Add(Radio_Bot_10);
        }

        // Boton de conexion                                                
        private void Boton_Connect_Click(object sender, EventArgs e) {
            string exeName = Path.GetFileNameWithoutExtension(Text_Process.Text);
            Process[] Procesos = Process.GetProcessesByName(exeName);
            foreach (Process Proceso in Procesos) {
                Direct3DVersion direct3DVersion = Direct3DVersion.Direct3D10;
                direct3DVersion = Direct3DVersion.Direct3D11;
                //Overlay como false (tal vez se usa true)
                CaptureConfig Config_Captura = new CaptureConfig() {
                    Direct3DVersion = direct3DVersion,
                    ShowOverlay = false
                };
                ProcesoId = Proceso.Id; // se usa?
                _Proceso = Proceso;     // se usa?
                var Interface_Captura = new CaptureInterface();
                Interface_Captura.RemoteMessage += new MessageReceivedEvent(CallBack_Mesajes_Captura);
                _Proceso_Captura = new CaptureProcess(Proceso, Config_Captura, Interface_Captura);
                
                break;
            }
            Thread.Sleep(10);
            //Revisamos si capturo el proceso
            if (_Proceso_Captura == null) {
                MessageBox.Show("Ejecutable no encontrado: '" + exeName + "'");
            } else {
                Boton_Connect.Enabled = false;
                Boton_Desconnect.Enabled = true;
                Boton_Capture.Enabled = true;
            }
        }
        // BOTON Desconexion                                                      
        private void Boton_Desconnect_Click(object sender, EventArgs e) {
            
            if (_Proceso_Captura != null)
            {
                HookManager.RemoveHookedProcess(ProcesoId);
                _Proceso_Captura.CaptureInterface.Disconnect();
                _Proceso_Captura = null;
                //Estado del boton              
                Boton_Connect.Enabled = true;
                Boton_Desconnect.Enabled = false;

            }

        }
        // BOTON Descapturar                                                     
        private void Stop_Click(object sender, EventArgs e)
        {
            Capturando = false;
        }

        // BOTON Capturar                                                        
        private void Boton_Capture_Click(object sender, EventArgs e) {
            Capturando = true;
            Capturar();
        }

        private void Boton_Get_hwnd_Click(object sender, EventArgs e) {
            IntPtr Padre;
            Padre = Obtener_Proceso(Text_ClassName.Text, Text_WindowName.Text);
            Text_hwnd.Text = Padre.ToString();
            // habilitamos botones
            Boton_Send_Key.Enabled = true;
            Boton_Set_Out.Enabled = true;
            Boton_Get_Chil_hwnd.Enabled = true;
            Boton_GetPoint.Enabled = true;
        }
        // Obtener el Hwnd Externo
        private void Boton_hwndExt_Click(object sender, EventArgs e)
        {
            IntPtr Hijo;
            Hijo = Obtener_Proceso(Text_WindowFloat.Text, L_TextBox_Elemento[0].Text);
            L_TextBox_hwdn[0].Text  = Hijo.ToString();
        }

        private void Boton_Send_Key_Click(object sender, EventArgs e) {
            IntPtr Padre;
            Padre = (IntPtr)int.Parse(Text_hwnd.Text);
            // Poner en foreground el programa  
            SetForegroundWindow(Padre);
            // enviamos el teclado              
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    SendKeys.SendWait(L_TextBox_Key[i].Text);
                }
            }
            SendKeys.Flush();
        }

        // BOTON Hide                                                           
        private void Boton_Hide_Click(object sender, EventArgs e)
        {
            IntPtr Padre;
            IntPtr Hijo;
            IntPtr PadreExt = FindWindow(Text_WindowFloat.Text, L_TextBox_hwdn[0].Text);
            Hijo = (IntPtr)int.Parse(L_TextBox_hwdn[0].Text);
            Padre = (IntPtr)int.Parse(Text_hwnd.Text);
            //SetForegroundWindow(Hijo);
            //Hijo = (IntPtr)001617E4;
            SetWindowPos(Hijo, (IntPtr)0, 100, 100, 200, 400, 0);

            //SendMessage(Hijo, WM_MOVE, (IntPtr)(long)0x0, MakeLParam(50, 100));
            //IntPtr PadreTmp = FindWindow("FS98FLOAT", L_TextBox_Elemento[0].Text);
            //IntPtr HijoTmp = FindWindowEx(PadreTmp, IntPtr.Zero, null, L_TextBox_Elemento[0].Text);


            MoveWindow(Hijo, 0, 0, 200, 200, true);
        }
        private void Boton_Set_Out_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    Desacoplar((IntPtr)int.Parse(L_TextBox_hwdn[i].Text), L_TextBox_Elemento[i].Text, Text_WindowFloat.Text);
                }
            }
            SendKeys.Flush();
        }

        private void Boton_Get_Chil_hwnd_Click(object sender, EventArgs e) {
            IntPtr Padre = (IntPtr)int.Parse(Text_hwnd.Text);
            IntPtr Hijo;
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    Hijo = Obtener_Sub_Proceso(Padre, L_TextBox_Elemento[i].Text, Text_WindowFloat.Text);
                    L_TextBox_hwdn[i].Text = Hijo.ToString();
                }
            }
        }

        // Obtener proceso                                  
        IntPtr Obtener_Proceso(string ClassName, string WindowName) {
            IntPtr Padre;
            Padre = FindWindow(ClassName, WindowName);
            if (Padre != null) {
                return Padre;
            } else {
                return (IntPtr)0;
            }
        }
        // Obtener sub proceso                              
        IntPtr Obtener_Sub_Proceso(IntPtr Padre, string Nombre, string Window_Exterior="") {
            IntPtr Hijo;
            Hijo = FindWindowEx(Padre, IntPtr.Zero, null, Nombre);
            if (Hijo != (IntPtr)0) {
                return Hijo;
            } else {
                //Revisamos si esta afuera                  
                // Tenemos que obtener el padre exterior    
                IntPtr PadreExt = FindWindow(Window_Exterior, Nombre);
                Hijo = FindWindowEx(PadreExt, IntPtr.Zero, null, Nombre);
                if (Hijo != null) {
                    // Estaba afuera
                    return Hijo;
                } else {
                    // no se encontro
                    return (IntPtr)0; 
                }
            }
        }
        // Desacoplar ventana                                
        void Desacoplar(IntPtr Hijo, string Hijo_Nombre, string Window_Exterior)  {
            //Revisamos si esta afuera                  
            // Tenemos que obtener el padre exterior    
            IntPtr PadreExt = FindWindow(Window_Exterior, Hijo_Nombre);
            IntPtr HijoExt  = FindWindowEx(PadreExt, IntPtr.Zero, null, Hijo_Nombre);
            if (HijoExt == (IntPtr)null)
            {
                // No Esta afuera
                SendMessage(Hijo, WM_COMMAND, new IntPtr(1025), new IntPtr(1025));
            }
        }


        //LLamadas de callback (Mensaje)                             
        void CallBack_Mesajes_Captura(MessageReceivedEventArgs message) {
            Text_Log.Invoke(new MethodInvoker(delegate () {
                Text_Log.Text = String.Format("{0}\r\n{1}", message, Text_Log.Text); 
                })
            );
        }
        // Log para mensajes                                          
        void Log(string Mensaje)
        {
            Text_Log.Invoke(new MethodInvoker(delegate () {
                Text_Log.Text = String.Format("{0}\r\n{1}", Mensaje, Text_Log.Text); })
            );
        }

        void Capturar() {
            if (Capturando)
            {
                //_Proceso_Captura.BringProcessWindowToFront();
                Size? resize = null;
                _Proceso_Captura.CaptureInterface.BeginGetScreenshot(
                    (IntPtr)10,   // Envio de Swap a usar
                    new Rectangle(0, 0, 0, 0),
                    new TimeSpan(0, 0, 5),
                    Callback_Screenshot,
                    resize,
                    (ImageFormat)Enum.Parse(typeof(ImageFormat),
                    "Bitmap")
                );
            }
        }
        //LLamadas de callback (Imagen)                             
        void Callback_Screenshot(IAsyncResult result) {
            if (Capturando)
            {
                using (Screenshot screenshot = _Proceso_Captura.CaptureInterface.EndGetScreenshot(result, ref SwapChain))
                    try
                    {
                        Thread.Sleep(1);
                        Log("Arribo elemento: " + SwapChain.ToString());
                        //Arribo_Swap(SwapChain);
                        if (screenshot != null && screenshot.Data != null)
                        {
                            ImagenBox.Invoke(new MethodInvoker(delegate () {
                                if (ImagenBox.Image != null) {
                                    ImagenBox.Image.Dispose();
                                }
                                ImagenBox.Image = screenshot.ToBitmap(); })
                            );
                        }
                        Thread hilo = new Thread(new ThreadStart(Capturar));
                        hilo.Start();
                    }
                    catch { }
            }
        }
        // Dibujar                                                  

        
        // Arribo de Swap                                           
        void Arribo_Swap(IntPtr Swap_In) {
            bool Existe = false;
            for (int i = 0; i < List_Swap_Recibido.Count; i++)
            {
                if (List_Swap_Recibido[i] == Swap_In)
                {
                    Existe = true;
                }
            }
            if (!Existe) {
                List_Swap_Recibido.Add(Swap_In);
                Log("Nuevo elemento: " + Swap_In.ToString());
            }
        }

        //Procedimientos externo (captura de windows)           
        [DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr FindWindow(string lpClassName, string lpWindowName);   //Uso de la libreria de windows
        //Procedimientos externo (captura de sub windows)       
        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        static extern IntPtr FindWindowEx(IntPtr parentHandle, IntPtr childAfter, string lclassName, string windowTitle);
        //Poner en Foreground                                   
        [DllImport("user32.dll")]
        private static extern bool SetForegroundWindow(IntPtr hWnd);
        //Procedimientos externo (Envio de mensajes a Windows)  
        [DllImport("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int wMsg, IntPtr wParam, IntPtr lParam);
        //Procedimientos externo (Mover ventana)                
        [DllImport("user32.dll")]
        // No anda
        public static extern int SetWindowPos(IntPtr hWnd, IntPtr val_0, int x, int y, int ancho, int alto,  uint flag = 0);
        // a ver
        [DllImport("user32.dll")]
        private static extern bool MoveWindow(IntPtr handle, int x, int y, int width, int height, bool redraw);


        private void textBox20_TextChanged(object sender, EventArgs e)
        {

        }

        private void Text_Hijo_1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Text_4_TextChanged(object sender, EventArgs e)
        {

        }

        

        private void groupBox3_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        
    }

}
