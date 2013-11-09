using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Wave_Reader
{
    class Program
    {
        static void Main(string[] args)
        {
            // Datei öffnen
            FileStream File = new FileStream(@"C:\Users\Daniel\Desktop\batR.wav", FileMode.Open);

            // Größe der Datei bestimmen
            long Size = File.Length;

            // Daten der Chunks
            byte[] ChunkID = new byte[4];
            byte[] ChunkSize = new byte[4];
            byte[] Format = new byte[4];
            byte[] SubChunkID = new byte[4];
            byte[] SubChunkSize = new byte[4];
            byte[] AudioFormat = new byte[2];
            byte[] Channel = new byte[2];
            byte[] Samplerate = new byte[4];
            byte[] Byterate = new byte[4];
            byte[] BlockAlign = new byte[2];
            byte[] BitsPerSample = new byte[2];
            byte[] SubChunk2ID = new byte[4];
            byte[] SubChunk2Size = new byte[4];

            // Dekoder erstellen
            ASCIIEncoding Encoder = new ASCIIEncoding();

            // Mehrdimensionales Array für die Chunks
            byte[][] Chunk = new byte[3][];
            Chunk[0]= new byte[12];
            Chunk[1] = new byte[24];
            Chunk[2] = new byte[Size - 36];

            // Ersten Chunk auslesen
            File.Read(Chunk[0], 0, 12);

            // Zweiten Chunk auslesen
            File.Read(Chunk[1], 0, 24);

            // Dritten Chunk auslesen
            for (int i = 0; i <= (Chunk[2].Length - 1); i++)
            {
                Chunk[2][i] = (byte)File.ReadByte();
            }

            // Datei freigeben
            File.Close();

            // Daten aus dem Array holen
            ChunkID = Chunk[0].Take(4).ToArray();
            ChunkSize = Chunk[0].Skip(4).Take(4).ToArray();
            Format = Chunk[0].Skip(8).Take(4).ToArray();
            SubChunkID = Chunk[1].Skip(0).Take(4).ToArray();
            SubChunkSize = Chunk[1].Skip(4).Take(4).ToArray();
            AudioFormat = Chunk[1].Skip(8).Take(2).ToArray();
            Channel = Chunk[1].Skip(10).Take(2).ToArray();
            Samplerate = Chunk[1].Skip(12).Take(4).ToArray();
            Byterate = Chunk[1].Skip(16).Take(4).ToArray();
            BlockAlign = Chunk[1].Skip(20).Take(2).ToArray();
            BitsPerSample = Chunk[1].Skip(22).Take(2).ToArray();
            SubChunk2ID = Chunk[2].Take(4).ToArray();
            SubChunk2Size = Chunk[2].Skip(4).Take(4).ToArray();

            // Konsolenausgabe
            Console.WriteLine("Chunk 1");
            Console.WriteLine("Chunk ID: " + Encoder.GetString(ChunkID));
            Console.WriteLine("Größe der Wave Datei: " + (BitConverter.ToInt32(ChunkSize, 0) + 8) + " Bytes");
            Console.WriteLine("Format: " + Encoder.GetString(Format));
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("Chunk 2");
            Console.WriteLine("Chunk ID: " + Encoder.GetString(SubChunkID));
            Console.WriteLine("Chunk Size: " + BitConverter.ToInt16(SubChunkSize, 0));
            Console.WriteLine("Audio Format: " + BitConverter.ToInt16(AudioFormat, 0));
            Console.WriteLine("Anzahl Kanäle: " + BitConverter.ToInt16(Channel, 0));
            Console.WriteLine("Samplerate: " + BitConverter.ToInt32(Samplerate, 0) + " Hz");
            Console.WriteLine("Byterate: " + BitConverter.ToInt32(Byterate, 0));
            Console.WriteLine("Bytes pro Sample: " + BitConverter.ToInt16(BlockAlign, 0));
            Console.WriteLine("Bits pro Sample: " + BitConverter.ToInt16(BitsPerSample, 0));
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("Chunk 3");
            Console.WriteLine("Chunk ID: " + Encoder.GetString(SubChunk2ID));
            Console.WriteLine("Chunk Size: " + BitConverter.ToInt32(SubChunk2Size, 0));

            Console.ReadLine();
        }
    }
}
