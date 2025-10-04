namespace EmployeeAssignment
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Employee emp = new Employee();

            Console.Write("Enter Name: ");
            emp.Name = Console.ReadLine();

            Console.Write("Enter Employee Number: ");
            emp.Empno = int.Parse(Console.ReadLine());

            Console.Write("Enter Basic Salary: ");
            emp.Basic = decimal.Parse(Console.ReadLine());

            Console.Write("Enter Department number: ");
            emp.Deptno = short.Parse(Console.ReadLine());

            Console.WriteLine();
            Console.WriteLine("Employee Details");
            Console.WriteLine("Employee Name: " + emp.Name);
            Console.WriteLine("Employee Id: " + emp.Empno);
            Console.WriteLine("Employee Department no.: " + emp.Deptno);
            Console.WriteLine("Employee Basic Salary: " + emp.Basic);
            Console.WriteLine("Employee Net Salary: " + emp.GetNetSalary()); 
        }
    }
}

class Employee
{
    private string? name;
    private int empno;
    private decimal basic;
    private short deptno;
    public string Name
    {
        set
        {
            if(value == "")
            {
                Console.WriteLine("Name Should Not Blank");
            }
            else
            {
                name = value;
            }
        }
        get
        {
            return name;
        }
    }
    public int Empno
    {
        set
        {
            if (value > 0)
            {
                empno = value;
            }
            else
            {
                Console.WriteLine("Id Employee number must be greater than 0");
            }
        }
        get
        {
            return empno;
        }
    }
    public decimal Basic
    {
        set
        {
            if(value >= 20000 && value <= 500000)
            {
                basic = value;
            }
            else
            {
                Console.WriteLine("Salary must between 5000-500000");
            }
        }
        get
        {
            return basic;
        }
    }
    public short Deptno
    {
        set
        {
            if (value < 0)
            {
                Console.WriteLine("Department number must be greater than 0");
            }
            else
            {
                deptno = value;
            }
        }
        get
        {
            return deptno;
        }
    }

    public decimal GetNetSalary()
    {
        decimal totalallowance = 5000;
        decimal totaldeduction = 7500;
        if(basic >= 20000)
        {
            return (basic + totalallowance - totaldeduction);

        }
        else
        {
            return 0;
        }
    }
}
