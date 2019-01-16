﻿using System;
using System.IO.Ports;

class PortDataReceived
{
    public static void Main()
    {
        SerialPort mySerialPort = new SerialPort("COM3");

        mySerialPort.BaudRate = 115200;
        mySerialPort.Parity = Parity.None;
        mySerialPort.StopBits = StopBits.One;
        mySerialPort.DataBits = 8;
        mySerialPort.Handshake = Handshake.None;
        mySerialPort.RtsEnable = true;

        mySerialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

        mySerialPort.Open();

        Console.WriteLine("Press any key to continue...");
        Console.WriteLine();
        Console.ReadKey();
        mySerialPort.Close();
    }

    private static void DataReceivedHandler(object sender,SerialDataReceivedEventArgs e)
    {
        SerialPort sp = (SerialPort)sender;
        string indata = sp.ReadLine(); // ReadExisting()
        //string[] split_data = indata.Split(' ');

        String[] newData = indata.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

        int x = 0;
        int y = 0;
        int z = 0;
        
        try
        {
            if (newData.Length == 3)
            {
                x = int.Parse(newData[0]);
                y = int.Parse(newData[1]);
                z = int.Parse(newData[2]);
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
}