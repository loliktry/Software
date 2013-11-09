using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Kinect;
using System.IO;

namespace KameraBasics
{
    /// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        // Objekt für die aktive Kinect anlegen
        private KinectSensor mySensor;

        // Beschreibbare Bitmaps für die Bildinformationen anlegen
        private WriteableBitmap colorBitmap;
        private WriteableBitmap depthBitmap;
        private WriteableBitmap MyBitmap;

        // Buffer für die Bilder von der Kampera
        private byte[] colorPixels;
        private DepthImagePixel[] depthPixels;
        private byte[] MyBuffer;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Kamera_Loaded(object sender, RoutedEventArgs e)
        {
            // Alle Sensoren in einer Liste "KinectSensor.KinectSensors" speichern und einzeln ausgeben
            foreach (var aktuellerSensor in KinectSensor.KinectSensors)
            {
                // Aktuelle Kinect verbunden?
                if (aktuellerSensor.Status == KinectStatus.Connected)
                {
                    // Aktuell verbundene Kinect unter "mySensor" speichern
                    mySensor = aktuellerSensor;
                    break;
                }
            }

            // Wenn mind. ein Sensor vorhanden
            if (null != mySensor)
            {
                // Tiefensensor und Farbkamera aktivieren
                mySensor.DepthStream.Enable(DepthImageFormat.Resolution640x480Fps30);
                mySensor.ColorStream.Enable(ColorImageFormat.RgbResolution640x480Fps30);

                // Neue Arrays für die Bilder anlegen
                depthPixels = new DepthImagePixel[mySensor.DepthStream.FramePixelDataLength];
                colorPixels = new byte[mySensor.ColorStream.FramePixelDataLength];
                MyBuffer = new byte[640*480*4];

                // Neue Bitmaps erstellen (diese werden nachher angezeigt)
                depthBitmap = new WriteableBitmap(
                                        mySensor.DepthStream.FrameWidth, 
                                        mySensor.DepthStream.FrameHeight, 
                                        96.0, 96.0, PixelFormats.Bgr32, null);
                colorBitmap = new WriteableBitmap(
                                        mySensor.ColorStream.FrameWidth,
                                        mySensor.ColorStream.FrameHeight,
                                        96.0, 96.0, PixelFormats.Bgr32, null);
                MyBitmap = new WriteableBitmap(
                                        640,
                                        480,
                                        96.0, 96.0, PixelFormats.Bgr32, null);

                // Image-Objekten die Bitmaps zuweisen
                Image_Depth.Source = MyBitmap;
                Image_Color.Source = colorBitmap;

                // Eventhandler der beiden Sensoren hinzufügen
                mySensor.DepthFrameReady += SensorDepthFrameReady;
                mySensor.ColorFrameReady += SensorColorFrameReady;

                // Sensor starten
                try
                {
                    mySensor.Start();
                    Status.Text = "" + KinectStatus.Connected;
                }
                catch (IOException)
                {
                    mySensor = null;
                    Status.Text = "" + KinectStatus.Disconnected;
                }
            }
        }


        // Kinect freigeben wenn das Fenster geschlossen wird
        private void WindowClosing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (null != mySensor)
            {
                mySensor.Stop();
            }
        }

         // Tiefensensor Event
        private void SensorDepthFrameReady(object sender, DepthImageFrameReadyEventArgs e)
        {
            using (DepthImageFrame depthFrame = e.OpenDepthImageFrame())
            {
                // Bild in SW umwandeln
                if (depthFrame != null)
                {
                    // Bild des Tiefensensors in das Array "SW" kopieren
                    depthFrame.CopyDepthImagePixelDataTo(depthPixels);

                    Text.Text = "" + mySensor.ColorStream.FramePixelDataLength;

                    // Pixel aus dem Array in ein Bitmap schreiben
                   MyBitmap.WritePixels(
                        new Int32Rect(0, 0, 640, 480),
                        depthPixels,
                        640 * sizeof(int),
                        0);
                }
            }
        }

        private void SensorColorFrameReady(object sender, ColorImageFrameReadyEventArgs e)
        {
            using (ColorImageFrame colorFrame = e.OpenColorImageFrame())
            {
                if (colorFrame != null)
                {
                    // Pixel der Farbkamera in dem Array "colorPixels" speichern
                    colorFrame.CopyPixelDataTo(colorPixels);

                    // Pixeldaten in das Bitmap schreiben
                    colorBitmap.WritePixels(
                        new Int32Rect(0, 0, colorBitmap.PixelWidth, colorBitmap.PixelHeight),
                        colorPixels,
                        colorBitmap.PixelWidth * sizeof(int),
                        0);
                }
            }
        }

        private void SaveImage(WriteableBitmap Bitmap, String Name)
        {
            if (null != mySensor)
            {
                // Erstellt ein neues BitmapFrame Objekt und wandelt Bitmap in einen Bitmapframe um
                BitmapFrame Frame = BitmapFrame.Create(Bitmap);

                // Dateistream erstellen
                var stream = new MemoryStream();

                // Encoder erstellen um Bilder im .png Format zu speichern
                BitmapEncoder encoder = new PngBitmapEncoder();

                // Bildframes erstellen
                encoder.Frames.Add(Frame);

                // Bildframes als Stream speichern
                encoder.Save(stream);

                // Neues Bitmap aus einem Stream erzeugen
                var bitmap = new System.Drawing.Bitmap(stream);

                // Bild speichern
                bitmap.Save("C:/Users/Daniel/Desktop/" + Name + ".png");
            }
        }

        // Screenshotbutton
        private void Screenshot_Click(object sender, RoutedEventArgs e)
        {
            SaveImage(colorBitmap, "color");
            SaveImage(depthBitmap, "depth");
        }
    }
}
