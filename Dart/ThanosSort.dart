import 'dart:math';

class ThanosSort {
  bool isSorted(List<int> array) {
    for (var i = 0; i < array.length - 1; i++) {
      if (array[i] > array[i + 1]) return false;
    }
    return true;
  }

  snap(List<int> array) {
    // O Gerador de números aleatórios
    var generator = new Random();

    while (!isSorted(array)) {
      // Pega a metade do array
      int half = (array.length / 2).floor();

      // Remove elementos aleatórios até ter removido metade do array
      for (var i = 0; i < half; i++) {
        int random = generator.nextInt(array.length);
        array.removeAt(random);
      }

      print("\n\n===== SNAP! ======\n\n");

      print("Array agora:");
      for (var item in array) {
        print('$item');
      }

      if (isSorted(array)) {
        print("\nAgora sim ... Tudo em perfeito equilíbrio\n");
      } else {
        print("\nO universo ainda não está balanceado!\n");
      }
    }
  }

  main(List<String> args) {
    List<int> array = [2, 1, 4, 3, 6, 5, 8, 7, 10, 9];

    print('Array antes da ordenação:');
    for (var item in array) {
      print('$item');
    }

    snap(array);
  }
}
