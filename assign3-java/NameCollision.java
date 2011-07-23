// File  : NameCollision.java
// Author: Keith T. Fancher
// Date  : 02-18-04
// Class : CS3490

//
// You can't have name collision in Java, because in order for a class
// to inherit from two super classes, they have to actually be interfaces.
// This means all their data members are automatically static and final.
// This means they are class variables, and also can't be modified at all
// by lower classes.  Also if you try to compile with just an ambiguous
// reference (like the below commented-out line), Java gets pissed and
// lets you know exactly what it thinks of your little "name collision"
// business.  So I guess really the problem itself exists, it's just that
// Java won't let you go anywhere until you fix it, so you can't really
// do any harm with it.  Also since the variables are static they can
// easily be referenced with ClassName.whatever which gets around the whole
// issue (as shown below so the code would compile).
//
// There could be a problem, however, if two interfaces each had a method in
// them with the same signature (see crap()), but they were supposed to do 
// something different.  Then when a class implements these interfaces, it 
// would only be able to implement one of these methods from one of the 
// interfaces.  This is easily changed by re-naming one of those methods in one
// of the interfaces, but  COULD be a problem if you don't have access to 
// the code for those interfaces.
//

interface A
{
  public static final String blah = "I am A!";
  public void crap();           // <-- This function is supposed to do something,
}                               //     I dunno, A-worthy.

interface B
{
  public static final String blah = "I am B!";
  public void crap();           // <-- This function is supposed do some really
}                               //     serious B-ing... of some sort.

class C implements A, B
{
  public void print()
  {
    System.out.println(A.blah); // <-- If you don't specify like this the code
    System.out.println(B.blah); //     ain't even gonna TRY to compile.

//  System.out.println(blah);      <-- This is what you CAN'T do, because Java
//                                     will thrash you if you even THINK it!
  }

  public void crap()            // <-- Is this A.crap(), or B.crap()???  Who even
  {                             //     can TELL anymore?  Ain't no way to specify,
    System.out.println("Crap!");//     so only one can exist.
  }

//public void crap()
//{
//  System.out.println("This is VERY IMPORTANT!!");  <-- This is what B's crap() is supposed
//}                                                      to do, but it's not allowed to exist.
}

class NameCollision
{
  public static void main(String [] argv)
  {
    C cobj = new C();
    cobj.print();
    cobj.crap();
  }
}

