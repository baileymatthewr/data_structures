<?php
require_once __DIR__.'/bag.php';

// -------------------------- script --------------------------
$numbers;
$array_size = 0;
$mean_value = 0;

echo "This program will compute the average of some numbers. The\n";
echo "numbers will be stored in an array of doubles that I allocate.\n";
echo "How many doubles should I allocate?\n";
do {
    echo "Please type a positive integer answer:\n";
    fscanf(STDIN, "%d\n", $array_size);
} while(!is_numeric($array_size));
$numbers = new bag($array_size);
$numbers->fill();
$numbers->print_final_sequence();

