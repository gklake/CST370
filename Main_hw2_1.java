/*
 * INSTRUCTION:
 *     This is a Java staring code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw2_1.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw2_1.java
 * Abstract: This program will read a set of ranges of two numbers from the user and display the intersection of the ranges
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/07/2022
 */
 
import java.util.Scanner;
import java.util.ArrayList; 
class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int numOfRanges = scan.nextInt();
        ArrayList<int[]> listOfRanges = new ArrayList<>();

        for(int i = 0; i < numOfRanges; i++){
            int x = scan.nextInt();
            int y = scan.nextInt();
            listOfRanges.add(new int[]{x, y});
        }

        int listSize = listOfRanges.size();
        int intervalStart = listOfRanges.get(0)[0];
        int intervalEnd = listOfRanges.get(0)[1];

        for(int i = 1; i < listSize; i++){
            if(listOfRanges.get(i)[0] > intervalEnd || listOfRanges.get(i)[1] < intervalStart){
                System.out.println(-1);
                return;
            } else {
                intervalStart = Math.max(intervalStart, listOfRanges.get(i)[0]);
                intervalEnd = Math.min(intervalEnd, listOfRanges.get(i)[1]);
            }
        }

        System.out.println(intervalStart + " " + intervalEnd);

        scan.close();
    }
}

