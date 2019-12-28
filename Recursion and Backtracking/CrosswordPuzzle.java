import java.lang.*;
import java.util.*;
import java.util.stream.*;
import java.util.function.*;
import java.io.*;

//https://www.hackerrank.com/challenges/crossword-puzzle

@SuppressWarnings("unchecked")
public class Solution {
  private static final char MINUS = '-';

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    /*String[] sInput = { "+-++++++++",
                    "+-++++++++",
                    "+-++++++++",
                    "+-----++++",
                    "+-+++-++++",
                    "+-+++-++++",
                    "+++++-++++",
                    "++------++",
                    "+++++-++++",
                    "+++++-++++" };*/
    /*String[] sInput = {
                        "+-++++++++",
                        "+-++++++++",
                        "+-------++",
                        "+-++++++++",
                        "+-----++++",
                        "+-+++-++++",
                        "+++-----++",
                        "+++++-++++",
                        "+++++-++++",
                        "+++++-++++" };*/
    String[] sInput = new String[10];
    for(int i = 0; i < sInput.length; i++) {
      sInput[i] = br.readLine();
    }
    char[][] input = transformInput(sInput);
    //printMatrix(input); //PRINT

    List<StrWord>[] strWords = (List<StrWord>[]) new List[11]; //index = word length
    for(int i = 0; i < strWords.length; i++) {
      strWords[i] = new ArrayList<>();
    }
    String wordsToFill;
    //wordsToFill = "LONDON;DELHI;ICELAND;ANKARA";
    //wordsToFill = "SYDNEY;TURKEY;DETROIT;EGYPT;PARIS";
    wordsToFill = br.readLine();
    int wordCount = fillWords(strWords, wordsToFill);
    //StrWord.print(strWords); //PRINT

    Word[] objWords = new Word[wordCount];
    markObjWords(objWords, input);
    //Word.printAll(objWords); //PRINT
    //check words unique in length
    searchByLen(objWords, strWords);
    //check words by intersections
    searchByIntersection(objWords, strWords); //TODO: can invoke it twice on failure

    //System.out.println();
    //Word.printAll(objWords); //PRINT
    //StrWord.print(strWords); //PRINT

    callTheOrcs(objWords, strWords);

    printResultMatrix(objWords, input);
    //TODO: on failure try all the combinations that are left checking for overriden words
  }

  private static void callTheOrcs(Word[] objWords, List<StrWord>[] strWords) {
    for(Word objW : objWords) {
      if(!objW.matchFound) {
        for(int i = 0; i < strWords[objW.length].size(); i++) {
          StrWord strW = strWords[objW.length].get(i);
          if(!strW.used) {
            strW.used = true;
            objW.matchFound = true;
            objW.matchWord = strW.word;
          }
        }
      }
    }
  }

  private static void printResultMatrix(Word[] words, char[][] m) {
    for(Word word : words) {
      if(word.direction == Direction.HORIZONTAL) {
        for(int j = 0; j < word.length; j++) {
          m[word.row][word.col + j] = word.matchWord.charAt(j);
        }
      } else {
        for(int i = 0; i < word.length; i++) {
          m[word.row + i][word.col] = word.matchWord.charAt(i);
        }
      }
    }
    printMatrixNoWhitespace(m);
  }

  private static void searchByLen(Word[] objWords, List<StrWord>[] strWords) {
    for(List<StrWord> list : strWords) {
      if(list.size() == 1) {
        int wordLen = list.get(0).word.length();
        for(int i = 0; i < objWords.length; i++) {
          if(objWords[i].length == wordLen) {
            objWords[i].matchFound = true;
            objWords[i].matchWord = list.get(0).word;
            list.get(0).used = true;
          }
        }
      }
    }
  }

  private static void searchByIntersection(Word[] objWords, List<StrWord>[] strWords) {
    for(Word obj : objWords) {
      if(!obj.matchFound) {
        //System.out.println(obj.row + " " + obj.col);
        for(Intersection intr : obj.intrList) {
          int matches = 0;
          StrWord w1, w2, matchW1 = null, matchW2 = null;
          //check current word and the intersecting word
          //if only one match exists set both, the check is made only if
          //current word is not used
          for(int a = 0; a < strWords[obj.length].size(); a++) {
            w1 = strWords[obj.length].get(a);
            //if(!w1.used) {
              for(int b = 0; b < strWords[intr.otherWordLen].size(); b++) {
                //if both words are with same lengths
                if(obj.length == intr.otherWordLen && a == b) {
                  continue;
                }
                w2 = strWords[intr.otherWordLen].get(b);
                if(w1.word.charAt(intr.currCharPosition) ==
                    w2.word.charAt(intr.otherCharPosition)) {
                  matches++;
                  matchW1 = w1;
                  matchW2 = w2;
                }
              }
            //}
          }
          if(matches == 1) {
            matchW1.used = true;
            obj.matchFound = true;
            obj.matchWord = matchW1.word;

            Word other = findWord(objWords, intr.otherStartRow, intr.otherStartCol,
              obj.direction == Direction.HORIZONTAL ? Direction.VERTICAL : Direction.HORIZONTAL);
            matchW2.used = true;
            other.matchFound = true;
            other.matchWord = matchW2.word;

            //System.out.println("MATCH w1 : " + matchW1.word + " w2: " + matchW2.word);
          }
        }
      }
    }
  }

  private static Word findWord(Word[] words, int startRow, int startCol, Direction direction) {
    for(Word w : words) {
      if(w.row == startRow && w.col == startCol && w.direction == direction) {
        return w;
      }
    }
    return null;
  }

  private static char[][] transformInput(String[] input) {
    int len = input.length;
    char[][] m = new char[len][len];
    for(int i = 0; i < len; i++) {
      m[i] = input[i].toCharArray();
    }
    return m;
  }

  private static int fillWords(List<StrWord>[] words, String input) {
    String[] sArr = input.split(";");
    for(int i = 0; i < sArr.length; i++) {
      words[sArr[i].length()].add(new StrWord(sArr[i]));
    }
    return sArr.length;
  }

  private static void printMatrix(char[][] m) {
    int rows = m.length;
    int cols = m[0].length;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        System.out.print(m[i][j] + " ");
      }
      System.out.println();
    }
  }

  private static void printMatrixNoWhitespace(char[][] m) {
    int rows = m.length;
    int cols = m[0].length;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        System.out.print(m[i][j]);
      }
      System.out.println();
    }
  }

  private static void markObjWords(Word[] words, char[][] m) {
    int len = m.length;
    int wordRow, wordCol, wordLen;
    Direction wordDirection;
    int wordIndex = 0;
    for(int i = 0; i < len; i++) {
      for(int j = 0; j < len; j++) {
        if(m[i][j] == MINUS) {
          //check if found vert word
          if( ((i > 0 && m[i-1][j] != MINUS) || i == 0) &&
              i+1 < len && m[i+1][j] == MINUS ) {
            wordRow = i;
            wordCol = j;
            wordDirection = Direction.VERTICAL;
            wordLen = 0;
            List<Intersection> intrList = new ArrayList<>();
            while(i < len && m[i][j] == MINUS) {
              Intersection intr = getHorizIntersection(i, j , m);
              if(intr != null) {
                intr.currCharPosition = wordLen;
                intrList.add(intr);
              }
              wordLen++;
              i++;
            }
            i = wordRow;
            words[wordIndex++] = new Word(wordRow, wordCol, wordLen, wordDirection, intrList);
          }
          //check if found horiz word
          if( ((j > 0 && m[i][j-1] != MINUS) || j == 0) &&
               j+1 < len && m[i][j+1] == MINUS) {
            wordRow = i;
            wordCol = j;
            wordDirection = Direction.HORIZONTAL;
            wordLen = 0;
            List<Intersection> intrList = new ArrayList<>();
            while(j < len && m[i][j] == MINUS) {
              Intersection intr = getVertIntersection(i, j , m);
              if(intr != null) {
                intr.currCharPosition = wordLen;
                intrList.add(intr);
              }
              wordLen++;
              j++;

            }
            j = wordCol;
            words[wordIndex++] = new Word(wordRow, wordCol, wordLen, wordDirection, intrList);
          }
        }
      }
    }
  }

  private static Intersection getHorizIntersection(int i, int j, char[][] m) {
    Intersection res = null;
    int len = m.length;

    if( (j - 1 >= 0 && m[i][j-1] == MINUS) ||
        (j + 1 < len && m[i][j+1] == MINUS) ) {
      res = new Intersection();

      int oldJ = j;
      //move j to start of intersecting word
      while(j >= 0 && m[i][j] == MINUS) {
        j--;
      }
      j++;
      res.otherStartRow = i;
      res.otherStartCol = j;
      while(j < len && m[i][j] == MINUS) {
        if(j == oldJ) {
          res.otherCharPosition = res.otherWordLen;
        }
        res.otherWordLen++;
        j++;
      }
    }

    return res;
  }

  private static Intersection getVertIntersection(int i, int j, char[][] m) {
    Intersection res = null;
    int len = m.length;

    if( (i - 1 >= 0 && m[i-1][j] == MINUS) ||
        (i + 1 < len && m[i+1][j] == MINUS) ) {
      res = new Intersection();

      int oldI = i;
      //move i to start of intersecting word
      while(i >= 0 && m[i][j] == MINUS) {
        i--;
      }
      i++;
      res.otherStartRow = i;
      res.otherStartCol = j;
      while(i < len && m[i][j] == MINUS) {
        if(i == oldI) {
          res.otherCharPosition = res.otherWordLen;
        }
        res.otherWordLen++;
        i++;
      }
    }

    return res;
  }
}
class Intersection {
  //direction is opposite of current word
  public int currCharPosition;
  public int otherWordLen;
  public int otherCharPosition;
  public int otherStartRow;
  public int otherStartCol;

  @Override
  public String toString() {
    return String.format(" -> otherStartRow = %d, otherStartCol = %d, "+
      "otherWordLen = %d, otherCharPosition = %d, currCharPosition = %d",
      otherStartRow, otherStartCol, otherWordLen, otherCharPosition , currCharPosition);
  }
}
class StrWord {
  public String word;
  public boolean used;

  public StrWord(String word) {
    this.word = word;
    this.used = false;
  }

  @Override
  public String toString() {
    return word + " used: " + used;
  }

  public static void print(List<StrWord>[] strWords) {
    for(int i = 0; i < strWords.length; i++) {
      System.out.println(i + " " + strWords[i]);
    }
  }

}
class Word {
  public final int row;
  public final int col;
  public final int length;
  public final Direction direction;
  public boolean matchFound = false;
  public String matchWord;
  List<Intersection> intrList;

  public Word(int row, int col, int length, Direction direction, List<Intersection> intrList) {
    this.row = row;
    this.col = col;
    this.length = length;
    this.direction = direction;
    this.intrList = intrList;;
  }

  @Override
  public String toString() {
    return String.format("row = %d, col = %d, length = %d, direction = %s "+
      "matchFound = %b, matchWord = %s%n"+
      "Intersections: %s", row, col, length, direction, matchFound, matchWord, intrList);
  }

  public static void printAll(Word... words) {
    for(Word item : words) {
      System.out.println(item);
    }
  }
}
enum Direction {
  HORIZONTAL, VERTICAL;
}
