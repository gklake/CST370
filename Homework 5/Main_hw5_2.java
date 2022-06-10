/*
 * Title: Main_hw5_2.java
 * Abstract: This program will read an input graph data from a user and present a path for the Traveling Salesman Problem.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/27/2022
 */
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
class Main {
  public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numV = scan.nextInt();
        ArrayList<String> vertexNames = new ArrayList<>();
        int[][] matrix = new int[10][10];
        int[] fromStart = new int[4];
        int[] toStart = new int[4];
        HashMap<String, Integer> vertexNameToNum = new HashMap<>();
        scan.nextLine();
        String startingCity = scan.nextLine();
        for(int i = 0; i < numV - 1; i++){
            String tempName = scan.nextLine();
            vertexNames.add(tempName);
        }
        int numE = scan.nextInt();
        scan.nextLine();
        fillMatrix(scan, vertexNames, matrix, fromStart, toStart, numE);

        StringBuilder permutationString = new StringBuilder();
        for(int i = 0; i < numV - 1; i++) {
            permutationString.append(i);
        }

        ArrayList<String> permutations = findPermutations(permutationString.toString());

        calculateCost(matrix, fromStart, toStart, vertexNameToNum, permutations);

        int minimumCost = Integer.MAX_VALUE;
        String path = "";
        if(!vertexNameToNum.isEmpty()){
            for(Map.Entry<String, Integer> set : vertexNameToNum.entrySet()){
                if(minimumCost > set.getValue()){
                    minimumCost = set.getValue();
                    path = set.getKey();
                }
            }
            printLeastCostPath(vertexNames, startingCity, minimumCost, path);
        } else {
            System.out.println("Path:");
            System.out.println("Cost:-1");
        }

        
    }

    private static void fillMatrix(Scanner scan, ArrayList<String> vertexNames, int[][] matrix, int[] fromStart, int[] toStart, int numE) {
        for(int i = 0; i < numE; i++){
            String tempEdge = scan.nextLine();
            String[] tempArray = tempEdge.split(" ");
            int source = vertexNames.indexOf(tempArray[0]);
            int destination = vertexNames.indexOf(tempArray[1]);
            if(source == -1){
                fromStart[destination] = Integer.parseInt(tempArray[2]);
            } else if(destination == -1){
                toStart[source] = Integer.parseInt(tempArray[2]);
            } else {
                matrix[source][destination] = Integer.parseInt(tempArray[2]);
            }
        }
    }

    private static void calculateCost(int[][] matrix, int[] fromStart, int[] toStart, HashMap<String, Integer> vertexNameToNum, ArrayList<String> permutations) {
        for(String s : permutations) {
            char[] tempCharacters = s.toCharArray();
            int size = s.length();
            int firstStop = Character.getNumericValue(tempCharacters[0]);
            int lastStop = Character.getNumericValue(tempCharacters[size - 1]);
            if (fromStart[firstStop] != 0 && toStart[lastStop] != 0) {
                boolean flag = false;
                int currentCost = 0;
                for (int i = 0; i < size - 1; i++) {
                    int[]matrixRow = matrix[Character.getNumericValue(tempCharacters[i])];
                    if(matrixRow[Character.getNumericValue(tempCharacters[i + 1])] == 0){
                        flag = true;
                    } else {
                        currentCost += matrixRow[Character.getNumericValue(tempCharacters[i + 1])];
                    }
                }
                if (!flag) {
                    currentCost += fromStart[firstStop];
                    currentCost += toStart[lastStop];
                    vertexNameToNum.put(s, currentCost);
                }
            }
        }
    }

    private static void printLeastCostPath(ArrayList<String> vertexNames, String startingCity, int minimumCost, String path) {
        System.out.print("Path:");
        System.out.print(startingCity + "->");
        char[] chars = path.toCharArray();
        for(char c: chars) {
           int temp = Character.getNumericValue(c);
            System.out.print(vertexNames.get(temp));
            System.out.print("->");
        }
        System.out.println(startingCity);
        System.out.println("Cost:" + minimumCost);
    }

    // Reference: https://stackoverflow.com/questions/13218019/generating-permutations-of-an-int-array-using-java-error
    public static ArrayList<String> findPermutations(String permutationString){
        ArrayList<String> arrayList = new ArrayList<>();
        if (permutationString == null) {
            return null;
        } else if (permutationString.length() == 0) {
            arrayList.add("");
            return arrayList;
        } else {
            for (int i = 0; i < permutationString.length(); i++) {
                ArrayList<String> remaining = findPermutations(permutationString.substring(0, i) + permutationString.substring(i + 1));
                for (String s : remaining) {
                    arrayList.add(permutationString.charAt(i) + s);
                }
            }
            return arrayList;
        }
    }
}

