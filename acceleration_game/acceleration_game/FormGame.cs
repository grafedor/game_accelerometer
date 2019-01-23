using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace acceleration_game
{
    public partial class FormGame : Form
    {
        private int x_pos;
        private int y_pos;
        private int x_acc;
        private int y_acc;
        private bool kolizja;
        private int wynik;

        public FormGame()
        {

            InitializeComponent();
            
            //ustawienie pozycji startowej
            x_pos = 40;
            y_pos = 40;
        }

        /*
         *  metoda odpowiada za rysowanie obiektu
         *  metoda ta jest wywołana jako event na PaintEventArgs
         */
        private void FormGame_Paint(object sender, PaintEventArgs e)
        {

            //e.Graphics.FillRectangle(Brushes.Cyan, x_pos, y_pos, 20, 20);       // rysowanie obiektu
            
            Bitmap bitmap_mario = new Bitmap("mario.png");
            Bitmap bitmap_retro1 = new Bitmap("RetroBlock.png");

            e.Graphics.DrawImage(bitmap_mario, x_pos, y_pos, 64, 64);    // rysowanie obiektu ruchomego

            e.Graphics.DrawImage(bitmap_retro1, 400, 200, 64, 64);   // rysowanie obiektu nieruchomego

            // detekcja kolizji mario z retro1
            if ((x_pos > 336 & x_pos < 464) & (y_pos > 136 & y_pos < 264))
            {
                kolizja = true;
            }
            else
            {
                if(kolizja == true)
                {
                    wynik += 1;
                    
                    kolizja = false;
                }
            }
              
           

        }

        /*
         *  metoda odpowiada za update danych i wyswietlanego obrazu 
         *  metoda ta jest wywołana jako event na timer tick 100ms
         */
        private void timerMove_Tick(object sender, EventArgs e)
        {
            move_algorithm();   // wywolanie algorytmu sterowania

            // aktualizacja wyniku 
            if (wynik >= 5)
                label1.Text = "Gratulacje wygrałeś";    
            else
                label1.Text = "Wynik: " + wynik; 

            Invalidate(); // wywolanie rysowania od nowa - redraw (update)
        }

        /*
         *  metoda odpowiada za sterowanie obiektem na podstawie danych otrzymanych z akcelerometru 
         */
        private void move_algorithm()
        {

            x_acc = SerialPortReadingData.getX();       // pobranie danych z klasy SerialPortReadData za pomocą geterów
            y_acc = SerialPortReadingData.getY();       // pobranie danych z klasy SerialPortReadData za pomocą geterów


            if ((x_acc > -4000) & (x_acc < 4000))      // bez ruchu
                x_pos += 0;
            if ((x_acc >= 4000) & (x_acc < 8000))      // ruch w prawo - wolno
                x_pos += 1;
            if ((x_acc >= 8000) & (x_acc < 12000))     // ruch w prawo - średnia prędkość
                x_pos += 5;
            if ((x_acc >= 12000) & (x_acc < 17000))    // ruch w prawo - duża prędkość
                x_pos += 8;

            if ((x_acc <= -4000) & (x_acc > -8000))    // ruch w lewo - wolno
                x_pos -= 1;
            if ((x_acc <= -8000) & (x_acc > -12000))   // ruch w lewo - średnia prędkość
                x_pos -= 5;
            if ((x_acc <= -12000) & (x_acc > -17000))  // ruch w lewo - duża prędkość
                x_pos -= 8;

            if ((y_acc > -4000) & (y_acc < 4000))      // bez ruchu
                y_pos += 0;
            if ((y_acc >= 4000) & (y_acc < 8000))      // ruch w dół - wolno
                y_pos += 1;
            if ((y_acc >= 8000) & (y_acc < 12000))     // ruch w dół - średnia prędkość
                y_pos += 5;
            if ((y_acc >= 12000) & (y_acc < 17000))    // ruch w dół - duża prędkość
                y_pos += 8;

            if ((y_acc <= -4000) & (y_acc > -8000))    // ruch w górę - wolno
                y_pos -= 1;
            if ((y_acc <= -8000) & (y_acc > -12000))   // ruch w górę - średnia prędkość
                y_pos -= 5;
            if ((y_acc <= -12000) & (y_acc > -17000))  // ruch w górę - duża prędkość
                y_pos -= 8;

        }

        
            
        
    }
}
