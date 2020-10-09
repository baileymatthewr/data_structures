<?php

class bag {
    public  const   DEFAULT_CAPACITY = 30;
    private array   $data = [];
    private int     $used;
    private int     $capacity;

    public function __construct(int $initial_capacity=DEFAULT_CAPACITY){
        $this->data = array_fill(0, $initial_capacity, -1);
        $this->capacity = $initial_capacity;
        $this->used = 0;
    }

    public function copy(bag &$source){
        return clone($source);
    }

    public function size(){
        return $this->used;
    }



    private function reserve($new_capacity){
        $larger_array = [];
        if($new_capacity == $this->capacity)
            return;                         // No allocation required
        if($new_capacity < $this->used)
            $new_capacity = $this->used;    // Superficially allocate less
        $this->capacity = $new_capacity;
    }

    private function erase($target){
        $many_removed = 0;
        for($i = 0; $i < $this->used; ++$i){
            if($this->data[$i] == $target){
                $this->data[$i--] = $data[--$this->used];
                ++$many_removed;
            }
        }
        return $many_removed;
    }

    private function erase_one($target){
        for($i = 0; $i < $this->used; ++$i){
            if($this->data[$i] == $target){
                $this->data[$i] = $this->data[--$this->used];
                return true;
            }
        }
        return false;
    }

    private function insert($entry){
        $entry = (double)$entry;
        if($this->used == $this->capacity)
            $this->reserve($this->used+1);
        $this->data[$this->used] = $entry;
        ++$this->used;
    }

    private function count($target){
        $answer = 0;
        for($i = 0; $i < $this->used; ++$i)
            if($target == $this->data[$i])
                ++$answer;
        return $answer;
    }

    private function average(){
        $sum = 0;
        assert($this->size() > 0);
        for($i = 0; $i < $this->used; ++$i)
            $sum += $this->data[$i];
        return ($sum / $this->size());
    }

    private function compare($mean){
        for($i = 0; $i < $this->used; ++$i){
            echo $this->data[$i];
            if($this->data[$i] < $mean)
                echo " is less than ";
            else if($this->data[$i] > $mean)
                echo " is more than ";
            else
                echo " is equal to ";
            echo "$mean\n";
        }
    }

    public function print_final_sequence(){
        $mean = $this->average();
        echo "The average is: $mean\n";
        $this->compare($mean);
        echo "This was a mean program.\n";
    }

    public function fill(){
        echo "Please type ".$this->capacity." numbers:\n";
        $entry = 0;
        for($i = 0; $i < $this->capacity; ++$i){
            do {
                fscanf(STDIN,"%s\n",$entry);
                $entry = (double)$entry;
            } while(!is_numeric($entry));
            $this->insert($entry);
        }
    }

}
