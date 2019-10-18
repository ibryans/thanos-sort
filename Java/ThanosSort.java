import java.util.Random;

public class ThanosSort {

    static int[] remove(int[] array, int pos) {
        int[] arrayAux = new int[array.length -1];
        int index = 0;
        for(int i = 0; i < array.length; i++){
            if(i != pos){
                arrayAux[index] = array[i];
                index++;
            }
        }
        return arrayAux;
    }

    static Boolean isSorted(int[] array) {
        for (int i = 0; i < array.length-1; i++) {
            if (array[i] > array[i+1]) {
                return false;
            }
        }
        return true;
    }

    static int[] snap(int[] array) {
        Random gerador = new Random();

        while (!isSorted(array)) {

            int halfLength = array.length / 2;

            // Vai remover length/2 elementos aleatórios
            for(int i = 0; i < halfLength; i++){
                int random = gerador.nextInt(array.length);
                array = remove(array, random);
            }

            System.out.println("\n\nSNAP!\n");

            for (int i : array) {
                System.out.print(i + " ");
            }
        }

        return array;
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 8, 1};
        
        for (int i : array) {
            System.out.print(i + " ");
        }

        array = snap(array);
    }

}