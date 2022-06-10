/*
 * INSTRUCTION:
 *     This is a Java staring code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw3_1.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw3_1.java
 * Abstract: This program will check if an input string is a palindrome or not.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/15/2022
 */
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
			Scanner scan = new Scanner(System.in);

			String userWord = scan.nextLine();
			if(isAPalindrome(userWord)){
				System.out.println("TRUE");
			} else {
				System.out.println("FALSE");
			}

			scan.close();
    }

	static boolean isAPalindrome(String word){
		word = word.toLowerCase();

			int front = 0;
			int back = word.length() - 1;

			while(front < back){
				if(word.charAt(front) != word.charAt(back)){
					return false;
				}
				front++;
				back--;
			}
			return true;
	}
}

