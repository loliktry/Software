using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Serialize
{
    [Serializable()]
    public class Person
    {
        private string _Name;
        public int Alter { get; set; }

        public Person() { }
        public Person(string name, int alter)
        {
            Alter = alter;
            Name = name;
        }

        public string Name
        {
            get { return _Name; }
			set { _Name = value; }
        }
    }
}
