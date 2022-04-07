import java.io.*;
import java.util.*;

public class Test
{
  private int a;
  public double b;
  
  public Test(int first, double second)
  {
    this.a = first;
    this.b = second;
  }
  public static void main(String[] args)
  {
    Test c1 = new Test(10, 20.5);
    Test c2 = new Test(10, 31.5);
    // lines below are changed from the question above
    c2 = c1;   
    c1.a = 2;
    System.out.println(c2.a);
  }
}