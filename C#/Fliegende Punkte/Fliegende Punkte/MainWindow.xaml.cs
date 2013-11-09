using System.IO;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Drawing;
using System.Linq;
using System.Windows.Shapes;
using System;
using Microsoft.Kinect;

namespace Fliegende_Punkte
{
    public partial class MainWindow : Window
    {
        /// <summary>
        /// Aktive Kinect
        /// </summary>
        private KinectSensor sensor;

        // Beschreibbare Bitmaps für die Bildinformationen anlegen
        private WriteableBitmap colorBitmap;

        // Buffer für die Bilder von der Kampera
        private byte[] colorPixels;

        // Ellipsenobjekt
        Ellipse BlueEllipse = new Ellipse();
        Ellipse RedEllipse = new Ellipse();

        /// <summary>
        /// Hauptfenster initialisieren
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Window Open Tasks
        /// </summary>
        private void WindowLoaded(object sender, RoutedEventArgs e)
        {
            foreach (var potentialSensor in KinectSensor.KinectSensors)
            {
                if (potentialSensor.Status == KinectStatus.Connected)
                {
                    sensor = potentialSensor;
                    break;
                }
            }

            if (null != sensor)
            {
                // Skelett Stream und Farbkamera aktivieren
                sensor.SkeletonStream.Enable();
                sensor.ColorStream.Enable(ColorImageFormat.RgbResolution640x480Fps30);

                // Eventhandler der beiden Sensoren hinzufügen
                sensor.SkeletonFrameReady += SensorSkeletonFrameReady;
                sensor.ColorFrameReady += SensorColorFrameReady;

                // Neue Arrays für die Bilder anlegen
                colorPixels = new byte[sensor.ColorStream.FramePixelDataLength];

                // Neue Bitmaps erstellen (diese werden nachher angezeigt)
                colorBitmap = new WriteableBitmap(sensor.ColorStream.FrameWidth, sensor.ColorStream.FrameHeight, 96.0, 96.0, PixelFormats.Bgr32, null);

                // Image-Objekten die Bitmaps zuweisen
                Bild.Source = colorBitmap;

                // Sensor starten
                try
                {
                    sensor.Start();
                }
                catch (IOException)
                {
                    sensor = null;
                }

                // Ellipsen erzeugen
                BlueEllipse.Stroke = System.Windows.Media.Brushes.Black;
                BlueEllipse.Fill = System.Windows.Media.Brushes.DarkBlue;
                BlueEllipse.HorizontalAlignment = HorizontalAlignment.Left;
                BlueEllipse.VerticalAlignment = VerticalAlignment.Center;
                BlueEllipse.Width = 25;
                BlueEllipse.Height = 25;

                RedEllipse.Stroke = System.Windows.Media.Brushes.Black;
                RedEllipse.Fill = System.Windows.Media.Brushes.Red;
                RedEllipse.HorizontalAlignment = HorizontalAlignment.Left;
                RedEllipse.VerticalAlignment = VerticalAlignment.Center;
                RedEllipse.Width = 25;
                RedEllipse.Height = 25;

                // Ellipsen auf das Bild legen
                myGrid1.Children.Add(BlueEllipse);
                myGrid2.Children.Add(RedEllipse);

                BlueEllipse.Margin = new Thickness(0, 0, 0, 0);
                RedEllipse.Margin = new Thickness(0, 0, 0, 0);
            }

            if (null == sensor)
            {
                statusBarText.Text = "Keine Kinect gefunden";
            }
        }

        /// <summary>
        /// Shutdown Task
        /// </summary>
        private void WindowClosing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (null != sensor)
            {
                sensor.Stop();
            }
        }

        /// <summary>
        /// Eventhandler für den Skelettframe
        /// </summary>
        private void SensorSkeletonFrameReady(object sender, SkeletonFrameReadyEventArgs e)
        {
            Joint Head = new Joint();
            Joint RightHand = new Joint();
            Joint LeftHand = new Joint();
            double RightX = 0;
            double RightY = 0;
            double LeftX = 0;
            double LeftY = 0;

            // Skelettframe öffnen
            using (SkeletonFrame skeletonFrame = e.OpenSkeletonFrame())
            {
                // Skelett vorhanden?
                if (skeletonFrame != null)
                {
                    Skeleton[] skeletonData = new Skeleton[skeletonFrame.SkeletonArrayLength];

                    // Skelettdaten in das Array "skeletonData" kopieren
                    skeletonFrame.CopySkeletonDataTo(skeletonData);

                    // Erste Skelett, dessen Status "Tracked" lautet, finden und auswählen
                    Skeleton playerSkeleton = (from s in skeletonData 
                                               where s.TrackingState == SkeletonTrackingState.Tracked 
                                               select s).FirstOrDefault();

                    if (playerSkeleton != null)
                    {
                        // Körperteile suchen und Objekten zuweisen
                        Head = playerSkeleton.Joints[JointType.Head];
                        RightHand = playerSkeleton.Joints[JointType.HandRight];
                        LeftHand = playerSkeleton.Joints[JointType.HandLeft];

                        // Ausgabe
                        TextBox_Status.Text = "" + playerSkeleton.TrackingState;
                        TextBox_HeadX.Text = "" + Head.Position.X;
                        TextBox_HeadY.Text = "" + Head.Position.Y;
                        TextBox_RightHandX.Text = "" + RightHand.Position.X;
                        TextBox_RightHandY.Text = "" + RightHand.Position.Y;
                        TextBox_LeftHandX.Text = "" + LeftHand.Position.X;
                        TextBox_LeftHandY.Text = "" + LeftHand.Position.Y;

                        // Rechte Hand X Achse
                        if (RightHand.Position.X < 0)
                        {
                            RightX = RightHand.Position.X * (-1.0);
                            RightX = ((double)Bild.Width / 2.0) - (RightX * ((double)Bild.Width / 2.0));
                        }
                        else
                        {
                            RightX = ((double)Bild.Width / 2.0) + (RightHand.Position.X * ((double)Bild.Width / 2.0));
                        }

                        // Rechte Hand Y Achse
                        if (RightHand.Position.Y < 0)
                        {
                            RightY = RightHand.Position.Y * (-1.0);
                            RightY = ((double)Bild.Height / 2.0) + (RightY * ((double)Bild.Height / 2.0));
                        }
                        else
                        {
                            RightY = ((double)Bild.Height / 2.0) - (RightHand.Position.Y * ((double)Bild.Height / 2.0));
                        }

                        // Linke Hand X Achse
                        if (LeftHand.Position.X < 0)
                        {
                            LeftX = LeftHand.Position.X * (-1.0);
                            LeftX = ((double)Bild.Width / 2.0) - (LeftX * ((double)Bild.Width / 2.0));
                        }
                        else
                        {
                            LeftX = ((double)Bild.Width / 2.0) + (LeftHand.Position.X * ((double)Bild.Width / 2.0));
                        }

                        // Linke Hand Y Achse
                        if (LeftHand.Position.Y < 0)
                        {
                            LeftY = LeftHand.Position.Y * (-1.0);
                            LeftY = ((double)Bild.Height / 2.0) + (LeftY * ((double)Bild.Height / 2.0));
                        }
                        else
                        {
                            LeftY = ((double)Bild.Height / 2.0) - (LeftHand.Position.Y * ((double)Bild.Height / 2.0));
                        }

                        // Neue Koordinaten der Ellipsen festlegen
                        BlueEllipse.Margin = new Thickness(RightX, RightY, 0, 0);
                        RedEllipse.Margin = new Thickness(LeftX, LeftY, 0, 0);
                    }
                }
            }
        }

        // Farbcamera Event
        private void SensorColorFrameReady(object sender, ColorImageFrameReadyEventArgs e)
        {
            using (ColorImageFrame colorFrame = e.OpenColorImageFrame())
            {
                if (colorFrame != null)
                {
                    // Pixel der Farbkamera in dem Array "colorPixels" speichern
                    colorFrame.CopyPixelDataTo(colorPixels);

                    // Daten in ein Bitmap schreiben
                    colorBitmap.WritePixels(
                        new Int32Rect(0, 0, colorBitmap.PixelWidth, colorBitmap.PixelHeight),
                        colorPixels,
                        colorBitmap.PixelWidth * sizeof(int),
                        0);
                }
            }
        }

        private void textBox1_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
        {

        }
    }
}
