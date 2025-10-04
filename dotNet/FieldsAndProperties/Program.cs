namespace FieldsAndProperties
{
    internal class Program
    {
        static void Main()
        {
            Class1 obj = new Class1();
            //obj.i = 100;
            //Console.WriteLine(obj.i);
            obj.I = -8;
            Console.WriteLine(obj.I);
            obj.S = "Abhay";
            Console.WriteLine(obj.S);
        }
    }

    public class Class1
    {
        private int i; //class level variables --Field
        
        public int I
        {
            set {
                if (value < 0)
                    Console.WriteLine("Please Insert Positive Value");
                else
                    i = value;
            }

            get { return i;}
        }
        private string s;
        public string S
        {
            set { s = value; }
            get { return s; }
        }
    }
}
