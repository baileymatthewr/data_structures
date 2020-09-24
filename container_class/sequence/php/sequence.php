<?php

define('CAPACITY', 30);

class sequence {
    private array $data = [];
    private int $used;
    private int $current_index;

    function __construct(){
        $this->current_index = 0;
        $this->used = 0;
        $this->data = array_fill(0,CAPACITY,-1);
    }

    public function start(){
        $this->current_index = 0;
    }

    public function advance(){
        if($this->is_item())
            ++$this->current_index;
    }

    public function insert($entry){
        assert(is_numeric($entry));
        assert($this->size() < CAPACITY);
        if($this->current_index < $this->used)
            $this->shift(($this->current_index - 1), $this->used);
        $this->data[$this->current_index] = $entry;
        ++$this->used;
    }

    public function attach($entry){
        assert(is_numeric($entry));
        assert($this->size() < CAPACITY);
        if($this->current_index < $this->used)
            $this->shift($this->current_index++, $this->used);
        $this->data[$this->current_index] = $entry;
        ++$this->used;
    }

    public function remove_current(){
        if($this->is_item())
            $this->shift($this->current_index, $this->used--, false);
    }

    public function size(){
        return $this->used;
    }

    public function is_item(){
        return (
            0 <= $this->current_index
            &&
            $this->current_index < $this->used
        );
    }

    public function current(){
        return $this->data[$this->current_index];
    }

    private function shift($first, $last, bool $expand=true){
        assert(is_numeric($first) && is_numeric($last));
        if($expand){
            for($i = $last; $i > $first; --$i){
                $this->data[$i] = $this->data[$i - 1];
            }
        } else {
            for($i = $first; $i < $last; ++$i){
                $this->data[$i] = $this->data[$i + 1];
            }
        }
    }
}

