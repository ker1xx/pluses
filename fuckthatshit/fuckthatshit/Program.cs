namespace fuckthatshit
{
    internal class Program
    {
        static void Main()
        {
            char a = 'a';
            Console.WriteLine(a.GetHashCode());
            Console.WriteLine((a.ToString()).GetHashCode());
        }
    }
}