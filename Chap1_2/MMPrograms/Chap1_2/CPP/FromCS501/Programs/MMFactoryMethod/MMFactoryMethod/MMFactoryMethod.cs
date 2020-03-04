//////////////////////////////////////////////////////////
//                                                      //
//  MM Factory Method                                   //
//  Written by Masaaki Mizuno, (c)2007                  //
//      for Learning Tree Course  252P                  //
//      also for K-State Course cis501                  //
//                                                      //
//////////////////////////////////////////////////////////
using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace MMFactoryMethod
{
    interface Server
    {
        void doMyWork();
        Client create();
    }
    interface Client
    {
        string whoAreYou();
    }

    class SA : Server
    {
        public void doMyWork() { Console.WriteLine("I am Server A"); }
        public Client create() { return new CA(); }
    }
    class SB : Server
    {
        public void doMyWork() { Console.WriteLine("Server B, here"); }
        public Client create() { return new CB(); }
    }
    class SC : Server
    {
        public void doMyWork() { Console.WriteLine("This is Server C"); }
        public Client create() { return new CC(); }
    }

    class CA : Client
    {
        public string whoAreYou() { return "CA"; }
    }
    class CB : Client
    {
        public string whoAreYou() { return "CB"; }
    }
    class CC : Client
    {
        public string whoAreYou() { return "CC"; }
    }

    class Driver
    {
        static void Main(string[] args)
        {
            Server s;
            s = new SA();
            //s = new SB();
            //s = new SC();

            s.doMyWork();
            Client c = s.create();
            Console.WriteLine("I can create ojbects of " + c.whoAreYou());
        }
    }
}