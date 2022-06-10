/*
 * INSTRUCTION:
 *     This is a Java staring code for hw3_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw3_2.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw3_2.java
 * Abstract: This program will check if two strings are anagrams or not, as well as the counts of each character if the words are anagrams.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/15/2022
 */
import java.util.Scanner;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Map;
class Main 
{
    public static void main(String[] args) {
			Scanner scan = new Scanner(System.in);
			HashMap<Character, Integer> letterCount = new HashMap<Character, Integer>();
			boolean flag = true;

			String firstWord = scan.next();
			String secondWord = scan.next();

			for(int i = 0; i < firstWord.length(); i++){
				if(!letterCount.containsKey(firstWord.charAt(i))){
					letterCount.put(firstWord.charAt(i), 1);
				} else {
					int currentCount = letterCount.get(firstWord.charAt(i));
					letterCount.put(firstWord.charAt(i), currentCount + 1);
				}
			}

			Map<Character, Integer> originalCount = new TreeMap<>(letterCount);

			for(int i = 0; i < secondWord.length(); i++){
				if(!letterCount.containsKey(secondWord.charAt(i))){
					System.out.println("NO ANAGRAM");
					flag = false;
					break;
				} else {
					int currentCount = letterCount.get(secondWord.charAt(i));
					letterCount.put(secondWord.charAt(i), currentCount - 1);
				}
			}

			if(flag){
				System.out.println("ANAGRAM");
				for(Character i : originalCount.keySet()){
					System.out.println(i + ":" + originalCount.get(i));
				}
			}

			scan.close();
    }
}

