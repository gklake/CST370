/*
 * INSTRUCTION:
 *     This is a Java staring code for hw1_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw1_1.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw1_1.java
 * Abstract: This program will read input from a user and display the closest distance between two numbers among all of the user's inputted numbers.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 1/31/2022
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class Main 
{
    public static void main(String[] args) {
			int minDistance = 0;
			Scanner scan = new Scanner(System.in);
			int totalNums = scan.nextInt();
			ArrayList<Integer> nums = new ArrayList<Integer>();

			for(int i = 0; i < totalNums; i++){
				nums.add(scan.nextInt()); // adding numbers to array list
			}

			Collections.sort(nums); // sorting into ascending order

			for(int i = 0; i < nums.size() - 1; i++){
				if(i == 0){
					minDistance = Math.abs(nums.get(i) - nums.get(i + 1));
				}
				if(Math.abs(nums.get(i) - nums.get(i + 1)) < minDistance){
					minDistance = Math.abs(nums.get(i) - nums.get(i + 1));
				}
			}

			System.out.println("Min Distance:" + minDistance);

			for(int i = 0; i < nums.size() - 1; i++){
				if(Math.abs(nums.get(i) - nums.get(i + 1)) == minDistance){
					System.out.println("Pair:" + nums.get(i) + " " + nums.get(i + 1));
				}
			}

			scan.close();
    }
}

