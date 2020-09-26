<?php

function allocate_doubles(&$p, &$n){
    echo "How many doubles should I allocate?\n";
    echo "Please type a positive integer answer: ";
    fscanf(STDIN, "%d\n", $n);
    $n = (int)$n;
    $p = array_fill(0, $n, -1);
}

function fill_array(&$data, $n){
    echo "Please type $n double numbers:\n";
    for($i = 0; $i < $n; ++$i)
        fscanf(STDIN, "%d\n", $data[$i]);
}

function average(&$data, $n){
    $sum = 0;
    assert(is_numeric($n) && $n > 0);
    for($i = 0; $i < $n; ++$i)
        $sum += $data[$i];
    return ($sum/$n);
}

function compare(&$data, $n, $value){
    for($i = 0; $i < $n; ++$i){
        echo $data[$i];
        if($data[$i] < $value)
            echo " is less than ";
        else if($data[$i] > $value)
            echo " is more than ";
        else
            echo " is equal to ";
        echo "$value\n";
    }
}


// -------------------------- script --------------------------
$numbers = [];
$array_size = 0;
$mean_value = 0;

echo "This program will compute the average of some numbers. The\n";
echo "numbers will be stored in an array of doubles that I allocate.\n";
allocate_doubles($numbers, $array_size);

fill_array($numbers, $array_size);
$mean_value = average($numbers, $array_size);

echo "The average is: $mean_value\n";
compare($numbers, $array_size, $mean_value);
echo "This was a mean program.\n";

