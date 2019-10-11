function thanos_sort(array) {

    while (!is_sorted(array)) {

        let half_length = array.length/2;

        // Vai remover length/2 elementos aleatórios
        for(let i = 0; i < half_length;i++){
            array.splice(Math.floor(Math.random()*array.length), 1)
        }

    }

    return array;
}

function is_sorted(array) {
    for (let i = 0; i < array.length; i++) {
        if (array[i] > array[i+1])
            return false;
    }
    return true;
}