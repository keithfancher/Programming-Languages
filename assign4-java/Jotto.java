// File  : Jotto.java
// Author: Keith T. Fancher
// Date  : 02/26/04
// Class : CS3490


import java.io.*;


class Jotto
{
  // Java IO is some whack stuff
  static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

  // *** showDirections() ***
  // Parameters: none
  // Returns   : void
  public static void showDirections()
  {
    System.out.println("\nAight, Jotto works like this: when the game starts a 5-letter");
    System.out.println("word is chosen at random from a big ol' dictionary of 5-letter");
    System.out.println("words.  Your job is to guess that word.  You've got as many");
    System.out.println("chances as you want, but there's a catch: you never actually see");
    System.out.println("if you got a letter right or not.  After you make a guess you just");
    System.out.println("see how many \"jots\" (matching letters) you got.  So like... go");
    System.out.println("for it or something.  You'll figure it out.");
  }

  // *** getJots(String, String) ***
  // Parameters: The two strings to compare
  // Returns   : The number of jots between the two compared strings
  public static int getJots(String s1, String s2)
  {
    int ret = 0;  // number of jots to return

    for(int i = 0; i < 5; i++)
    {
      if(s2.indexOf(s1.charAt(i)) != -1) // found the char
      {
        ret++;
        s2 = s2.replaceFirst(s1.substring(i, i + 1), " "); // replace char w/ a space
      }
    }
    
    return ret;
  }

  // *** isAlpha(String) ***
  // Parameters: The input string to be tested
  // Returns   : True if the string is all letters, false otherwise
  public static boolean isAlpha(String s)
  {
    for(int i = 0; i < s.length(); i++)
      if(!Character.isLetter(s.charAt(i)))
        return false;
    return true;
  }

  // *** getInput() ***
  // Parameters: none
  // Returns   : The string the user inputs when prompted
  public static String getInput() throws IOException
  {
    System.out.print("\nEnter a five letter word (or q to quit): ");
    String in = stdin.readLine();
    return in.toUpperCase();  // so they always compare correctly
  }

  
  public static void main(String [] argv) throws IOException
  {
    Dictionary dictionary = new Dictionary();
    String answer = new String(dictionary.randomGet());
    String instring;

    // Intro-ma-duction
    System.out.println(answer);  // for, uhh... testing purposes or something *cheat cheat*
    System.out.print("Jotto welcomes you!  You want directions (Y,N)? ");
    instring = stdin.readLine();
    if(instring.compareToIgnoreCase("yes") == 0 || instring.compareToIgnoreCase("y") == 0)
      showDirections();

    // the game loop (I think do/while loops are the most... the absolute MOST!)
    boolean winner = false;
    do
    {
      instring = getInput();
      if(instring.compareToIgnoreCase("q") != 0)
      {
        try
        {
          if(instring.length() != 5)
            throw new Exception("FIVE letter word.  Five.");
          if(!isAlpha(instring))
            throw new Exception("Words are made of letters.  Get it right.");

            int numjots = getJots(instring, answer);
            if(numjots == 5)
            {
              if(instring.compareToIgnoreCase(answer) == 0)  // winner!
              {
                System.out.println("Dude!  You got it!  The word was " + answer + "!\n");
                winner = true;
              }
            }
            if(!winner)
              System.out.println(getJots(instring, answer) + " jot" + (numjots != 1 ? "s" : "") + ".");
        }
        catch(Exception e)
        {
          System.out.println(e.getMessage());
        }
      }
      else // quit
        System.out.println("\nBefore you peace out, you might like to know that the word was " + answer + ".");
    } while(instring.compareToIgnoreCase("q") != 0 && !winner);
  }
}

