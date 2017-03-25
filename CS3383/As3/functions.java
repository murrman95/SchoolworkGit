public class functions{
  public functions(){}
    public int inversionAlg(int[] numbers, int start, int end){
      if(start == end){
        return 0;
      }
      else{
        int array1 = inversionAlg(numbers, start, (start + end)/2);
        int array2 = inversionAlg(numbers, (start + end)/2 + 1, end);
        return array1 + array2 + merge(numbers, start, end);
      }
    }

    static int merge(int[] array, int start, int end){
      System.out.println((start + end + 1)/2 - start);
      System.out.println(end-(start + end)/2);
      int[] array1 = new int[(start + end + 1)/2 - start];
      int[] array2 = new int[end-(start + end)/2];
      int numInversions = 0;
      int counter = 0;
      for(int i = start; i < (start + end)/2; i ++){
        array1[counter] = array[i];
        counter ++;
      }
      counter = 0;
      for(int i = (start + end)/2; i < end; i ++){
        array2[counter] = array[i];
        counter ++;
      }
      int a1Index = 0;
      int a2Index = 0;
      int aIndex = start;
      while(a1Index < array1.length && a2Index < array2.length){
        if(array1[a1Index] > array2[a2Index]){
          array[aIndex] = array2[a2Index];
          a2Index ++;
          aIndex ++;
        }
        else{
          if(array2[a2Index] > 2*array1[a1Index]){
            numInversions += (array2.length - a2Index);
          }
          array[aIndex] = array1[a1Index];
          a1Index ++;
          aIndex ++;
        }
      }
      while(a1Index < array1.length){
        array[aIndex] = array1[a1Index];
        a1Index ++;
        aIndex ++;
      }
      while(a2Index < array2.length){
        System.out.println("a2Index: " + a2Index + " a2.lenght: " + array2.length);
        System.out.println("aIndex: " + aIndex + " a.length: " + array.length);
        array[aIndex] = array2[a2Index];
        a2Index ++;
        aIndex ++;
      }
      return numInversions;
    }

}
