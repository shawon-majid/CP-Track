import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Test
{

  public static void main(String[] args)
  {


    Pattern pattern = Pattern.compile("([0-9](\\.)*[+-\\*/](\\.)*[0-9])*");

    Scanner in = new Scanner(System.in);

    int T = in.nextInt();

    while(T != 0){
      T -= 1;

      String str = in.next();

      if(pattern.matcher(str).find()){
        System.out.println("Yes");
      }
      else System.out.println("No");
    }

    
  }
}