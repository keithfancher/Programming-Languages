// File  : Dictionary.java
// Author: Keith T. Fancher
// Date  : 02/26/04
// Class : CS3490


import java.io.*;
import java.util.*;


class Dictionary
{
  // *** Dictionary() ***
  // Initializes the linked list of all the bajillion words in the dictionary
  public Dictionary() throws IOException
  {
    FileReader dicfile = new FileReader("jotto.dic");  
    BufferedReader dic = new BufferedReader(dicfile);
    wordList = new LinkedList();

    while(dic.ready())
      wordList.add(dic.readLine());
    
    dicfile.close();
  }

  // *** randomGet() ***
  // Paramters: none
  // Returns  : The random word it gets from the dictionary list
  public String randomGet()
  {
    Random r = new Random();
    return new String((String)wordList.get(r.nextInt(wordList.size())));
  }

  // The linked list of words... the GIANT linked list of words
  private LinkedList wordList;
}

