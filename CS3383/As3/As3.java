public class As3{
  public static void main(String[] args){
    functions f = new functions();
    int[] array = {1,3,2,5,3,7,4,9,5,11};
    int res = f.inversionAlg(array, 0, array.length);
    System.out.println("Number of signifigant inversions is: " + res);
  }
}
