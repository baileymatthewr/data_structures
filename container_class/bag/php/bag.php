<?php

define('CAPACITY', 30);

class bag {
    private array $data;
    private int $used;

    public function __construct(){
        $this->data = array_fill(0, CAPACITY, -1);
        $this->used = 0;
    }

    public function erase(int $target){
        $many_removed = 0;
        for($i = 0; $i < $this->used; ++$i){
            if($target == $this->data[$i]){
                --$this->used;
                $this->data[$i] = $this->data[$this->used];
                ++$many_removed;
            }
        }
        return $many_removed;
    }

    public function erase_one(int $target){
        for($i = 0; $i < $this->used; ++$i){
            if($target == $this->data[$i]){
                --$this->used;
                $this->data[$i] = $this->data[$this->used];
                return true;
            }
        }
        return false;
    }

    public function insert(int $entry){
        assert($this->size() < CAPACITY);
        $this->data[$this->used++] = $entry;
    }

    public function append(bag $addend){
        assert($this->size() + $addend->size() < CAPACITY);
        $addend->data = array_merge($this->data, $addend->data);
        $this->used += $added->size();
    }

    public function size(){
        return $this->used;
    }

    public function count(int $target){
        $answer = 0;
        for($i = 0; $i < $this->used; ++$i){
            if($target == $this->data[$i])
                ++$answer;
        }
        return $answer;
    }
}
