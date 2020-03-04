//////////////////////////////////////////////////////////////////////////
//                                                                      //
//   Iterator Pattern used in Java                                      //
//   Written by Masaaki Mizuno, (c) 2007	        		  	        //
//      for Learning Tree Course  252P                                  //
//      also for K-State Course cis501                                  //
//                                                                      //
//////////////////////////////////////////////////////////////////////////
import java.util.*;

class  State{
   String name;
   State(String name) {
	   this.name = name;
   }

   public String toString() {
	   return "\t" + name;
   }
}

public class JavaIterator {
   public static void main(String[] args) {
	   //List<State> ll = new LinkedList<State>();
	   List<State> ll = new ArrayList<State>();
	   ll.add(new State("Kansas"));
	   ll.add(new State("Ohio"));
	   ll.add(new State("Nebraska"));
	   ll.add(new State("Michigan"));

       System.out.println("Iterate the List using an iterator");
	   Iterator<State> li = ll.listIterator(0);
	   while (li.hasNext())
			 System.out.println(li.next().toString());
   }
}