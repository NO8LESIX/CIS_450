using System;

namespace Polymorephism
{
	class A 
	{
		public int a;
		public virtual void f() 
		{
			Console.WriteLine("A's f()");
		}
	}

	class B: A 
	{
		public int b;
		public void g() 
		{
			Console.WriteLine("B's g()");
		}
		public override void f()
		{
			Console.WriteLine("B's f()");
		}
	}

	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	class Polymorphism
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main(string[] args)
		{
			//
			// TODO: Add code to start application here
			//
			A ap = new A();
			B bp = new B();

			ap.f();
			bp.g();
			bp.f();

            ap = bp;	// comment this line and uncomment the next line
            //bp = ap;  // try bp = (B)ap;
			ap.f();

		}
	}
}
