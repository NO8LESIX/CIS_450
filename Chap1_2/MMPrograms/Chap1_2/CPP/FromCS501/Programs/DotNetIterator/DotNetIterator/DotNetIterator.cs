//////////////////////////////////////////////////////////////////////////
//                                                                      //
//   DotNet Iterator                                                    // 
//   Written by Masaaki Mizuno, (c) 2007                                //
//      for Learning Tree Course  252P                                  //
//      also for K-State Course cis501                                  //
//                                                                      //
////////////////////////////////////////////////////////////////////////// 
using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace DotNetIterator
{
    class State
    {
        string s;

        public State(string s)
        {
            this.s = s;
        }

        public override string ToString()
        {
            return s;
        }
    }

    class Driver
    {
        static void Main(string[] args)
        {
            Console.WriteLine(
              "Use the generic list \"List<T>\" and the foreach construct");
            List<State> stateList = new List<State>();
            stateList.Add(new State("USA"));
            stateList.Add(new State("Japan"));
            stateList.Add(new State("Mexico"));
            foreach (State s in stateList)
                Console.WriteLine(s);

            Console.WriteLine(
              "\nThe foreach construct is equivalent to the following construct:");
            IEnumerator<State> sen = stateList.GetEnumerator();
            //IEnumerator sen = stateList.GetEnumerator(); // this works too
            while (sen.MoveNext())
                Console.WriteLine(sen.Current);

            Console.WriteLine(
              "\nThe foreach construct works with an array structure as well");
            State[] stateArray = new State[3];
            stateArray[0] = new State("Canada");
            stateArray[1] = new State("China");
            stateArray[2] = new State("Australia");
            foreach (State s in stateArray)
                Console.WriteLine(s);

            Console.WriteLine("\nIn case of Array, IEnumerator is not generic");
            IEnumerator en = stateArray.GetEnumerator(); /* the same enumerator */
            while (en.MoveNext())
                Console.WriteLine((State)en.Current);
            //in this particular case, since ToString() is defined in object, 
            // casting is not needed ("Current" returns a reference to "object")

            Console.WriteLine("\nNow, traverse Stack using foreach\n");
            Stack<State> stateStack = new Stack<State>();
            stateStack.Push(new State("Tokyo"));
            stateStack.Push(new State("Kanagawa"));
            stateStack.Push(new State("Ibaraki"));
            stateStack.Push(new State("Saitama"));

            foreach (State s in stateStack)
                Console.WriteLine(s);

            Console.WriteLine("\nNow, traverse Queue using foreach\n");
            Queue<State> stateQueue = new Queue<State>();
            stateQueue.Enqueue(new State("Tokyo"));
            stateQueue.Enqueue(new State("Kanagawa"));
            stateQueue.Enqueue(new State("Ibaraki"));
            stateQueue.Enqueue(new State("Saitama"));

            foreach (State s in stateQueue)
                Console.WriteLine(s);

            Console.WriteLine("\nNow, traverse Dictionary using foreach\n");
            Dictionary<string, State> stateDictionary = new Dictionary<string, State>();
            stateDictionary.Add("Tokyo", new State("Tokyo"));
            stateDictionary.Add("Kanagawa", new State("Kanagawa"));
            stateDictionary.Add("Ibaraki", new State("Ibaraki"));
            stateDictionary.Add("Saitama", new State("Saitama"));

            foreach (KeyValuePair<string, State> s in stateDictionary)
                Console.WriteLine(s.Key + "\t" + s.Value);






        }
    }
}
