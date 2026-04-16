public class PalindromeNumber {
    public static boolean isPalindrome(int n) {
        if (n < 0) return false; // Negative numbers are not palindromes
        
        int original = n;
        int reversed = 0;
        
        while (n > 0) {
            int lastDigit = n % 10;
            reversed = (reversed * 10) + lastDigit;
            n /= 10;
        }
        return original == reversed;
    }

    public static void main(String[] args) {
        int num = 121;
        System.out.println(num + " is palindrome: " + isPalindrome(num));
    }
}
