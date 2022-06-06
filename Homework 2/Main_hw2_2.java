/*
 * INSTRUCTION:
 *     This is a Java staring code for hw2_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw2_2.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw2_2.java
 * Abstract: This program will read the number of elements in a set, then read the elements of  the set. Next, the program will display all of the possible decimal numbers, corresponding binary numbers, and subsets, one at a time.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/09/2022
 */

import java.util.Scanner;
import java.lang.Math;
class Main {
    public static void main(String[] args) {
			Scanner scan = new Scanner(System.in);
			int numOfElements = scan.nextInt();
			int numOfIterations = (int) Math.pow(2, numOfElements);

			if (numOfElements == 0) {
					System.out.println("0:0:EMPTY");
			} else {
					String[] elementsArray = getStrings(scan);
					for (int i = 0; i < numOfIterations; i++) {
							String binaryString = Integer.toBinaryString(i);
							System.out.print(i + ":");
							if (binaryString.length() == numOfElements) {
									System.out.print(binaryString + ":");
									printElements(numOfElements, elementsArray, binaryString);
							} else {
									int numOfZeroes = numOfElements - binaryString.length();
									StringBuilder binary = new StringBuilder();
									binary.append("0".repeat(Math.max(0, numOfZeroes)));
									binary.append(binaryString);
									System.out.print(binary + ":");
									if (binaryString.equals("0")) {
											System.out.println("EMPTY");
											continue;
									}
									printElements(numOfElements, elementsArray, binary.toString());
							}
							System.out.println();
					}
			}
			scan.close();
    }

    private static String[] getStrings(Scanner scan) {
        scan.nextLine();
        String userElements = scan.nextLine();
        return userElements.split(" ");
    }

    private static void printElements(int iterations, String[] array, String bitString) {
        for (int j = 0; j < iterations; j++) {
            if (bitString.charAt(j) == 49) {
                System.out.print(array[j]);
                if (j != iterations - 1) {
                    System.out.print(" ");
                }
            }
        }
    }
}

