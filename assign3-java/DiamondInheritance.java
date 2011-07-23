// File  : DiamondInheritance.java
// Author: Keith T. Fancher
// Date  : 02-18-04
// Class : CS3490

//
// Diamond inheritance sort of/kind of exists in Java, but it doesn't seem
// like it could really be a big problem since Java does allow multiple
// inheritance.  As long as the higher up classes have to be interfaces you
// don't really have too many options to screw things up.  Since your data
// members have to be static ANYhoo, all the lower interfaces/class are
// inheriting the same friggin' copy of whatever is in Z.  Of course the very
// nature of diamond inheritance means that the whole name collision issue
// arises again.  Dumb ol' Java...
//

interface Z
{
  public static final String blah = "What up, I'm Z";
}

interface A extends Z
{
}

interface B extends Z
{
}

class C implements A, B
{
  public void print()
  {
    System.out.println(blah);     // <-- this works
    System.out.println(blah);

    System.out.println(A.blah);   // <-- so does this!
    System.out.println(B.blah);
  }
}

class DiamondInheritance
{
  public static void main(String [] argv)
  {
    C cobj = new C();
    cobj.print();
  }
}
