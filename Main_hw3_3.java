/*
 * INSTRUCTION:
 *     This is a Java staring code for hw3_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw3_3.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw3_3.java
 * Abstract: This program will read two timestamps from a user and display the difference of the timestamps
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/15/2022
 */
import java.util.Scanner;
class Main {
    public static void main(String[] args) {
			        Scanner scan = new Scanner(System.in);
        int hour1, min1, sec1;
        int hour2, min2, sec2;
        int hrPassed, minPassed, secPassed;
        String firstTimeStamp, secondTimeStamp;

        firstTimeStamp = scan.nextLine();
        secondTimeStamp = scan.nextLine();

        hour1 = Integer.parseInt(firstTimeStamp.substring(0, 2));
        min1 = Integer.parseInt(firstTimeStamp.substring(3, 5));
        sec1 = Integer.parseInt(firstTimeStamp.substring(6, 8));

        hour2 = Integer.parseInt(secondTimeStamp.substring(0, 2));
        min2 = Integer.parseInt(secondTimeStamp.substring(3, 5));
        sec2 = Integer.parseInt(secondTimeStamp.substring(6, 8));

        hrPassed = hour2 - hour1;
        minPassed = min2 - min1;
        secPassed = sec2 - sec1;

        if(secPassed < 0){
            secPassed += 60;
            minPassed--;
        } else if(secPassed > 60){
            secPassed -= 60;
            minPassed++;
        }

        if(minPassed < 0){
            minPassed += 60;
            hrPassed--;
        } else if(minPassed > 60){
            minPassed -= 60;
            minPassed++;
        }

        if(hrPassed < 0){
            hrPassed += 24;
        } else if(hrPassed > 24){
            hrPassed -= 24;
        }


        if(hrPassed < 10){
            System.out.print("0" + hrPassed + ":");
        } else {
            System.out.print(hrPassed + ":");
        }

        if(minPassed < 10){
            System.out.print("0" + minPassed + ":");
        } else {
            System.out.print(minPassed + ":");
        }

        if(secPassed < 10){
            System.out.println("0" + secPassed);
        } else {
            System.out.println(secPassed);
        }

        scan.close();
			
    }
}