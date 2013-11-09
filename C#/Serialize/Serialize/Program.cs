using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace Serialize
{
    class Program
    {
        static XmlSerializer serializer;
        static FileStream stream;

        static void Main(string[] args)
        {
            serializer = new XmlSerializer(typeof(Person));
            Person person = new Person("Jutta", 34);
            SerializeObject(person);
            Person oldPerson = DeserializeObject();
            Console.WriteLine("Name: " + oldPerson.Name);
            Console.WriteLine("Alter: " + oldPerson.Alter);
            Console.ReadLine();
        }

        public static void SerializeObject(object obj)
        {
            stream = new FileStream(@"C:\Users\Daniel\Desktop\XMLTest.xml", FileMode.Create);
            serializer.Serialize(stream, obj);
            stream.Close();
        }

        public static Person DeserializeObject()
        {
            stream = new FileStream(@"C:\Users\Daniel\Desktop\XMLTest.xml", FileMode.Open);
            return (Person)serializer.Deserialize(stream);
        }
    }
}
