public class proyecto8 {

    public static void main(String[] args) {
        int i;
        for (i = 0; i < 101; i++) {
            if (i % 3 == 0 && i % 5 == 0 && i != 0) {
                System.out.println("FizzBuzz");
            } else if (i % 5 == 0 && i != 0) {
                System.out.println("Buzz");
            } else if (i % 3 == 0 && i != 0) {
                System.out.println("Fizz");
            } else {
                System.out.println(i);
            }
        }
    }
}
