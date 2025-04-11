import java.util.Scanner;
 
public class Q2_nuberWays {
    // Function to calculate the factorial of a number
    public static int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
 
    // Function to calculate the number of ways to choose 'P' pencils and 'E' erasers
    public static int countWaysToChoose(int N, int M, int P, int E) {
        // Calculate the number of ways to choose 'P' pencils
        int waysToChoosePencils = factorial(N) / (factorial(P) * factorial(N - P));
 
        // Calculate the number of ways to choose 'E' erasers
        int waysToChooseErasers = factorial(M) / (factorial(E) * factorial(M - E));
 
        // Calculate the total number of ways
        int totalWays = waysToChoosePencils * waysToChooseErasers;
 
        return totalWays;
    }
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int P = scanner.nextInt();
        int E = scanner.nextInt();
        int ways = countWaysToChoose(N, M, P, E);
        System.out.println(ways);
    }
}