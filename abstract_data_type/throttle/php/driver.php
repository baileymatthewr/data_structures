<?php

class throttle {
    private int $position;
    public function shut_off(){
        $this->position = 0;
    }

    public function shift(int $amount){
        $this->position += $amount;
        if($this->position < 0)
            $this->position = 0;
        else if($this->position > 6)
            $this->position = 6;
    }

    public function flow(){
        return ($this->position / 6.0);
    }

    public function is_on(){
        return ($this->flow() > 0);
    }
}




// ----------------------------- Script -----------------------------
$sample = new throttle();
$user_input;
echo "I have a throttle with 6 positions.\n";
echo "Where would you like to set the throttle?\n";
echo "Please type a number from 0 to 6:\n";
fscanf(STDIN, "%d\n", $user_input);
$sample->shut_off();
$sample->shift($user_input);
while($sample->is_on()){
    echo "The flow is now ".$sample->flow()."\n";
    $sample->shift(-1);
}
echo "The flow is now off\n";
