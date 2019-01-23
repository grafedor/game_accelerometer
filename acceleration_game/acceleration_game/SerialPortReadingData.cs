using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace acceleration_game
{
    class SerialPortReadingData
    {

        static SerialPort mySerialPort = new SerialPort("COM3");

        private static int x = 0;       // zmienna x - zawiera dane odczytywane z akcelerometru oś X
        private static int y = 0;       // zmienna y - zawiera dane odczytywane z akcelerometru oś Y
        private static int z = 0;       // zmienna z - zawiera dane odczytywane z akcelerometru oś Z

        // getery umożliwiają przekazanie danych o polu pryvatnym, do zewnętrznych klas
        public static int getX()
        {
            return x;
        }

        public static int getY()
        {
            return y;
        }

        public static  int getZ()
        {
            return z;
        }

        public static void startSerialPort()
        {
            // ustwienie parametrów komunikacji portu szeregowego
            mySerialPort.BaudRate = 115200;
            mySerialPort.Parity = Parity.None;
            mySerialPort.StopBits = StopBits.One;
            mySerialPort.DataBits = 8;
            mySerialPort.Handshake = Handshake.None;
            mySerialPort.RtsEnable = true;

            mySerialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            mySerialPort.Open();
        }

        // obsługa odebrania danych z portu szeregowego
        public static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadLine(); // ReadExisting()
            //string[] split_data = indata.Split(' ');

            String[] newData = indata.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            // obsługa wyjątku - gdy do terminala trafi dana z UART inna niż liczba, dane x, y, z zamieniane są na 0,0,0
            try
            {
                if (newData.Length == 3)    // jeśli ilość łąńcuchów znaków jest 3 (x,y,z)
                {
                    // konwertowanie string na int
                    x = int.Parse(newData[0]);
                    y = int.Parse(newData[1]);
                    z = int.Parse(newData[2]);
                    // kontrolene wyświetlenie w konsoli
                    Console.WriteLine(x);
                    Console.WriteLine(y);
                    Console.WriteLine(z);
                }
            }
            catch (Exception)
            {
                x = 0;
                y = 0;
                z = 0;
            }

        }

        public void closePort()
        {
            mySerialPort.Close();
        }

        

    }
}
