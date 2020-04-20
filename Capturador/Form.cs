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
        IntPtr h_Padre;
        IntPtr[] h_Elemento = new IntPtr[10];
        IntPtr[] h_Elemento_Ext = new IntPtr[10];
        IntPtr[] h_Pointer = new IntPtr[10];
        //     
        bool Conectado = false;
        int Elementos = 0;
        IntPtr Swap_Nuevo = (IntPtr)0;
        IntPtr Swap_Caido = (IntPtr)0;

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
        List<TextBox> L_TextBox_hwdn_Ext = new List<TextBox>();
        List<TextBox> L_TextBox_Point = new List<TextBox>();
        List<RadioButton> L_Radio_Sel = new List<RadioButton>();
        List<CheckBox> L_Check = new List<CheckBox>();
        
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

            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_1);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_2);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_3);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_4);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_5);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_6);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_7);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_8);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_9);
            L_TextBox_hwdn_Ext.Add(Text_hwnd_Ext_10);

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

            L_Check.Add(Check_1);
            L_Check.Add(Check_2);
            L_Check.Add(Check_3);
            L_Check.Add(Check_4);
            L_Check.Add(Check_5);
            L_Check.Add(Check_6);
            L_Check.Add(Check_7);
            L_Check.Add(Check_8);
            L_Check.Add(Check_9);
            L_Check.Add(Check_10);

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
                //MessageBox.Show("Ejecutable no encontrado: '" + exeName + "'");
                Log("Ejecutable no encontrado: '" + exeName + "'");
            } else {
                Conectado = true;
                //Boton_Connect.Enabled = false;
                //Boton_Desconnect.Enabled = true;
                //Boton_Capture.Enabled = true;
            }
        }
        // BOTON Desconexion                                                      
        private void Boton_Desconnect_Click(object sender, EventArgs e) {
            if (_Proceso_Captura != null) {
                HookManager.RemoveHookedProcess(ProcesoId);
                _Proceso_Captura.CaptureInterface.Disconnect();
                _Proceso_Captura = null;
                //Estado del boton              
                Boton_Connect.Enabled = true;
                Boton_Desconnect.Enabled = false;
            }
        }
        // BOTON Capturar                                                      
        private void Boton_Capture_Click(object sender, EventArgs e) {
            Capturando = true;
            Capturar();
        }
        // BOTON Descapturar                                                   
        private void Stop_Click(object sender, EventArgs e) {
            Capturando = false;
        }
        // BOTON Obtener el hwnd Principal                                     
        private void Boton_Get_hwnd_Click(object sender, EventArgs e) {
            h_Padre = Obtener_Proceso(Text_ClassName.Text, Text_WindowName.Text);
            Text_hwnd.Text = h_Padre.ToString();
            // habilitamos botones
            Boton_Send_Key.Enabled = true;
            Boton_Set_Out.Enabled = true;
            Boton_Get_Chil_hwnd.Enabled = true;
            Boton_GetPoint.Enabled = true;
        }
        // BOTON Enviar Tecla                                                  
        private void Boton_Send_Key_Click(object sender, EventArgs e) {
            // Poner en foreground el programa  
            SetForegroundWindow(h_Padre);
            // enviamos el teclado              
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    SendKeys.SendWait(L_TextBox_Key[i].Text);
                }
            }
            SendKeys.Flush();
        }
        // BOTON Obtener el hwnd del elemento                                   
        private void Boton_Get_Chil_hwnd_Click(object sender, EventArgs e) {
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    h_Elemento[i]= Obtener_Sub_Proceso(h_Padre, L_TextBox_Elemento[i].Text, Text_WindowFloat.Text);
                    L_TextBox_hwdn[i].Text = h_Elemento[i].ToString();
                }
            }
        }
        // BOTON Desacoplar ventana                                             
        private void Boton_Set_Out_Click(object sender, EventArgs e) {
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    Desacoplar(h_Elemento[i], L_TextBox_Elemento[i].Text, Text_WindowFloat.Text);
                }
            }
            SendKeys.Flush();
        }

        // Obtener el Hwnd Externo del Elemento                                  
        private void Boton_hwndExt_Click(object sender, EventArgs e) {
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    h_Elemento_Ext[i] = Obtener_Proceso(Text_WindowFloat.Text, L_TextBox_Elemento[i].Text);
                    L_TextBox_hwdn_Ext[i].Text = h_Elemento_Ext[i].ToString();
                }
            }
        }

        // BOTON Hide                                                           
        private void Boton_Hide_Click(object sender, EventArgs e) {
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    SetWindowPos(h_Elemento_Ext[i], (IntPtr)0, 100, 1200, 300, 300, 0);
                    //MoveWindow(h_Elemento_Ext[i], 0, 0, 200, 200, true);
                }
            }
        }
        // BOTON UN Hide                                                           
        private void Boton_UnHide_Click(object sender, EventArgs e) {
            for (int i = 0; i < 10; i++) {
                if (L_Radio_Sel[i].Checked) {
                    SetWindowPos(h_Elemento_Ext[i], (IntPtr)0, 100, 100, 300, 300, 0);
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
            // escribimos en log
            Text_Log.Invoke(new MethodInvoker(delegate () {
                Text_Log.Text = String.Format("{0}\r\n{1}", message, Text_Log.Text); 
                })
            );
            // revisamos mensaje
            List<string> Mensaje = new List<string>(message.ToString().Split(new char[] { ':' }));
            Analisis_Mensaje(Mensaje);
        }

        void Analisis_Mensaje(List<string> mensaje)
        {
            if (mensaje.Count > 4) {
                if (mensaje[2] == " Swap nuevo ") {
                    Elementos++;
                    Swap_Nuevo = (IntPtr)long.Parse(mensaje[4]);
                    Log("Mensaje recibido nuevo. Elementos: " + Elementos);

                } else if (mensaje[2] == " Swap caido ") {
                    Elementos--;
                    Swap_Caido = (IntPtr)long.Parse(mensaje[4]);
                    Log("Mensaje recibido caido. Elementos: " + Elementos);
                }
            }
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
                        //Log("Arribo elemento: " + SwapChain.ToString());
                        Arribo_Swap(SwapChain);
                        if (screenshot != null && screenshot.Data != null)
                        {
                            ImagenBox.Invoke(new MethodInvoker(delegate () {
                                if (ImagenBox.Image != null) {
                                    ImagenBox.Image.Dispose();
                                }
                                ImagenBox.Image = screenshot.ToBitmap(); })
                            );
                        }
                        // llamar nuevamente a la captura
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


        private void Boton_Auto_Click(object sender, EventArgs e) {
            // Ejecutamos el proceso en hilo aparte
            Thread h_automatico = new Thread(new ThreadStart(Automatico));
            h_automatico.Start();
        }
        private void Automatico() {
            int Reintentos = 20;
            for (int i = 0; i < Reintentos; i++) {
                if (!Conectado) {
                    Thread.Sleep(1000);
                    Boton_Connect_Click(null, null);
                }
            }
            // avanzamos al segundo paso si esta conectado
            if (Conectado)
            {
                // OBtener Padre
                h_Padre = Obtener_Proceso(Text_ClassName.Text, Text_WindowName.Text);
                // delegar      
                Text_hwnd.Invoke(
                new MethodInvoker(delegate () {
                    Text_hwnd.Text = h_Padre.ToString();
                })
            );

                //              
                if (Elementos == 0)
                {
                    Log("Esperando Pantalla inicial");
                }
                // Esperar Elemento = 1 (ventana principal)
                for (int i = 0; i < Reintentos; i++)
                {
                    Thread.Sleep(1000);
                    if (Elementos == 1)
                    {
                        Log("Pantalla inicial cargada");
                        i = Reintentos;
                        // Pasar al siguiente paso  
                    }
                    if (Elementos > 1)
                    {
                        // Matar Swaps              
                        Log("Swap superados, reduciendo Swaps");
                        Matar_Swaps();
                        i = Reintentos;
                        Log("Pantalla inicial cargada");
                    }
                }
                // 3 er modulo                      
                if (Elementos == 1)
                {
                    // Extrar elemetos
                    Thread.Sleep(1000);
                    for (int i = 0; i < 10; i++)
                    {
                        if (L_Check[i].Checked)
                        {
                            Log("Extrar Swap " + i);
                            Extrar_Swap(i);
                            //SetWindowPos(h_Elemento_Ext[i], (IntPtr)0, 100, 100, 300, 300, 0);
                        }
                    }
                }
            }
        }

        private void Extrar_Swap(int Id)
        {
            int Elemento_previo = Elementos;
            // Enviamos tecla               
            Log("Send Key " + Id);
            SendKeys.SendWait(L_TextBox_Key[Id].Text);
            Thread.Sleep(1000);
            // Obtener valores              
            Log("Obtener sub procesos " + Id);
            h_Elemento[Id] = Obtener_Sub_Proceso(h_Padre, L_TextBox_Elemento[Id].Text, Text_WindowFloat.Text);
            h_Elemento_Ext[Id] = Obtener_Proceso(Text_WindowFloat.Text, L_TextBox_Elemento[Id].Text);
            // Almacenar (delegando)        
            L_TextBox_hwdn[Id].Invoke(
                new MethodInvoker(delegate () {
                    L_TextBox_hwdn[Id].Text = h_Elemento[Id].ToString();
                })
            );
            L_TextBox_hwdn_Ext[Id].Invoke(
                new MethodInvoker(delegate () {
                    L_TextBox_hwdn_Ext[Id].Text = h_Elemento_Ext[Id].ToString();
                })
            );
            Thread.Sleep(1000);
            // Los valores estan obtenidos si o si
            // Extraemos el objeto                
            Log("Desacoplar " + Id);
            Desacoplar(h_Elemento[Id], L_TextBox_Elemento[Id].Text, Text_WindowFloat.Text);
            Thread.Sleep(1000);
            // Revisar si no desacoplo            
            if (Elementos <= Elemento_previo)
            {
                // bajo de elementos o no cambio (Enviar de nuevo la tecla)
                Log("Desacople sin efecto " + Id);
                SendKeys.SendWait(L_TextBox_Key[Id].Text);
                Thread.Sleep(1000);
                Desacoplar(h_Elemento[Id], L_TextBox_Elemento[Id].Text, Text_WindowFloat.Text);
            } else
            {
                Log("Desacoplado " + Id);
                // desacoplo    
                h_Pointer[Id] = Swap_Nuevo;
                // Guardar en texto box
                L_TextBox_Point[Id].Invoke(
                    new MethodInvoker(delegate () {
                        L_TextBox_Point[Id].Text = h_Pointer[Id].ToString();
                    })
                );
                // Esconder             
                Thread.Sleep(2000);
                Log("Mostrar elemento " + Id);
                SetWindowPos(h_Elemento_Ext[Id], (IntPtr)0, 100, 100, 300, 300, 0);
                Thread.Sleep(2000);
                Log("Ocultar elemento " + Id);
                SetWindowPos(h_Elemento_Ext[Id], (IntPtr)0, 100, 1200, 300, 300, 0);
                Thread.Sleep(2000);
            }

        }
        private void Matar_Swaps()
        {
            for (int i = 0; i < 10; i++) {
                Log(i + " - Swaps actuales: " + Elementos);
                Intento_Reducir_Swaps(i);
                if (Elementos == 1) {
                    Log("Swaps eliminados");
                    i = 10;
                }
            }
        }

        private void Intento_Reducir_Swaps(int Id) {
            int Elemento_previo = Elementos;
            SendKeys.SendWait(L_TextBox_Key[Id].Text);
            Thread.Sleep(1000);
            if (Elementos >= Elemento_previo)
            {
                // subio de elementos o no cambio (Enviar de nuevo la tecla)
                SendKeys.SendWait(L_TextBox_Key[Id].Text);
                Thread.Sleep(1000);
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

        private void Boton_GetPoint_Click(object sender, EventArgs e)
        {

        }

        
    }

}
