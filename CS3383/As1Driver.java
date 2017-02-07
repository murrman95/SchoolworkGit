import java.util.Scanner;

public class As1Driver{
  public static void main(String[] args){
    System.out.println("Please input a word:");
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();

    Palindrome p = new Palindrome();
    System.out.println("Palindrome? == " + p.palDriver(s));

    int[] input = {1,2,5,7,5,1,4,2,5,7,4};
    System.out.println("Input array is: ");
    for(int i = 0; i < input.length; i++){
      System.out.print(input[i] + " ");
    }
    System.out.println();
    System.out.println("Repeating numbers in this array are:");
    repeatingArray rA = new repeatingArray();
    rA.countAlg(input);
  }
}
