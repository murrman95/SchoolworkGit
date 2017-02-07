public class Palindrome{

  public Palindrome(){};

  public boolean palDriver(String s){
    return palAlg(s, 0, s.length() -1);
  }

  public boolean palAlg(String s, int start, int finish){
    if (start >= finish){
      return true;
    }
    else{
      if(s.charAt(start) != s.charAt(finish)){
        return false;
      }
      else{
        return palAlg(s, start + 1, finish - 1);
      }
    }
  }
}
