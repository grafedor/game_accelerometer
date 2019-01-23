using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace acceleration_game
{
    static class Program
    {
        
        [STAThread]
        static void Main()
        {
            //SerialPortReadingData serialPortReadingData = new SerialPortReadingData();
            SerialPortReadingData.startSerialPort();                        // wywolanie matody startSerialPort() - odczyt danych z portu szeregowego
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new FormGame());                                // uruchomienie aplikacji okienkowej

        }

           
    }
}

