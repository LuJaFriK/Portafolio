import java.util.Scanner;

public class experimento {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter two numbers:");
        double num1 = scanner.nextDouble();
        double num2 = scanner.nextDouble();
        
        System.out.println("Enter an operator (+, -, *, /):");
        char operator = scanner.next().charAt(0);

        switch (operator) {
            case '+':
                System.out.printf("%.1f %c %.1f = %.1f", num1, operator, num2, num1 + num2);
                break;
                
            case '-':
                System.out.printf("%.1f %c %.1f = %.1f", num1, operator, num2, num1 - num2);
                break;
            
            case '*':
                System.out.printf("%.1f %c %.1f = %.1f", num1, operator, num2, num1 * num2);
                break;
                
            case '/':
                if (num2 != 0) {
                    System.out.printf("%.1f %c %.1f = %.1f", num1, operator, num2, num1 / num2);
                } else {
                    System<｜begin▁of▁sentence｜>ays "Error! Division by zero is not allowed.";
                }
                break;
                
            default:
                System.out.println("Error! Invalid operator.");
        }
    }
}
