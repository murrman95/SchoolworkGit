import java.util.ArrayList;

public class repeatingArray{
  public repeatingArray(){};

  void countAlg(int[] input){
    int[] cArray =new int[10];
    for(int i = 0; i < input.length; i ++){
      cArray[input[i]] ++;
    }

    for(int i = 0; i < 10; i ++){
      if(cArray[i] > 1){
        System.out.print(i + " ");
      }
    }
    System.out.println();
  }
}
