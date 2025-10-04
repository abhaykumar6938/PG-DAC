namespace BasicClassConcepts  //Allows us to organizes classes They contain only classes or also other namespace and classes contains code.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            //System.Console.WriteLine("I am .Net Developer....");

            Class1 obj;
            obj = new Class1();
            obj.Display();

            //Positional parameters
            Console.WriteLine(obj.add(1, 2, 3));
            Console.WriteLine(obj.add(1,3));
            Console.WriteLine(obj.add(3));

            //Named Parameter
            Console.WriteLine(obj.add(a:10,b:20,c:12));
            Console.WriteLine(obj.add(a: 10, b: 20));
            Console.WriteLine(obj.add(a:5,10));
        }
    }

    public class Class1
    {
        public void Display()
        {
            Console.WriteLine("Display Called");
        }

        //default parameters Function
        public int add(int a = 0, int b = 0, int c = 0)
        {
            return a + b + c;
        }
    }
}
