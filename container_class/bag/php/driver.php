<?php

require_once __DIR__."/bag.php";

function correct_range($thing){
    return is_numeric($thing) && $thing >= 0;
}

function get_ages(bag &$ages){
    echo "Type the ages in your family.\n";
    echo "Type a negative number when you are done:\n";
    $user_input = 0;
    do {
        fscanf(STDIN, "%d\n", $user_input);
        if(correct_range($user_input))
            $ages->insert($user_input);
    } while(correct_range($user_input));
}

function check_ages(bag &$ages){
    $user_input = 0;
    echo "Type those ages again. Press return after each age:\n";
    while($ages->size() > 0){
        fscanf(STDIN, "%d\n", $user_input);
        if(correct_range($user_input)){
            if($ages->erase_one($user_input)){
                echo "Yes, I've found that age and removed it.\n";
            } else {
                echo "No, that age does not occur!\n";
            }
        } else {
            break;
        }
    }
}


//------------------------------ Script -----------------------------
$ages = new bag();
get_ages($ages);
check_ages($ages);
echo "May your family live long and prosper.\n";
