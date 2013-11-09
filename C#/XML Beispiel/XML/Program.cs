using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;

namespace XML
{
    class Program
    {
        static void Main(string[] args)
        {
            string Path;

            // Pfad der XML Datei eingeben
            Console.WriteLine("Konsolenanwendung zum Auslesen von XML-Dateien");
            Console.WriteLine("www.Kampis-Elektroecke.de");
            Console.WriteLine();
            Console.Write("Kompletten Pfad der XML-Datei eingeben: ");

            // Einlesen des Pfades
            Path = Console.ReadLine();

            Console.WriteLine("Ausgabe:");
            Console.WriteLine();

            // XML Reader erzeugen
            XmlReader Reader = XmlReader.Create(@"" + Path);

            // Sämtliche Knoten auslesen
            while (Reader.Read())
            {
                // Knotentypen herausfiltern
                switch (Reader.NodeType)
                {
                    // XML Deklaration ausgeben
                    case XmlNodeType.XmlDeclaration:
                        Console.WriteLine("{0, -20}{1}","Deklaration", Reader.Value);
                        break;

                    // Elemente untersuchen
                    case XmlNodeType.Element:
                        if (Reader.IsEmptyElement) { }
                        else
                        {
                            Console.WriteLine("{0, -20}{1}", "Element", @"<" + Reader.Name + ">");

                            // Attribute vorhanden?
                            if (Reader.HasAttributes)
                            {
                                // Nächstes Attribut
                                while (Reader.MoveToNextAttribute())
                                {
                                    Console.WriteLine("{0, -20}{1}", "Attribut", Reader.Name + "=" + Reader.Value);
                                }
                            }
                        }
                        break;

                    case XmlNodeType.EndElement:
                        Console.WriteLine("{0, -20}{1}", "Element Ende", @"</" + Reader.Name + ">");
                        break;

                    // Text rausfiltern
                    case XmlNodeType.Text:
                        Console.WriteLine("{0, -20}{1}", "Text", Reader.Value);
                        break;
                }
            }

            // XML Reader beenden
            Reader.Close();
        }
    }
}